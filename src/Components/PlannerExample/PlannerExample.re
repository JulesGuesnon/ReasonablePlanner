open Revery;
open Revery.UI;
open PlannerExampleStyle;
/* open GlobalState.Date.Types; */

type mouse = {
  x: float,
  y: float,
};

type state = {
  scrollToTop: float,
  scrollToLeft: float,
  mouseIsDown: bool,
  lastPosition: mouse,
};

type action =
  | ScrollToTop(float)
  | ScrollToLeft(float)
  | MouseIsDown
  | MouseIsUp
  | LastPosition(mouse);

let%component make = () => {
  let%hook (state, dispatch) =
    Hooks.reducer(
      ~initialState={
        scrollToTop: 0.,
        scrollToLeft: 0.,
        mouseIsDown: false,
        lastPosition: {
          x: 0.,
          y: 0.,
        },
      },
      (action, state) => {
      switch (action) {
      | ScrollToTop(value) => {...state, scrollToTop: value}
      | ScrollToLeft(value) => {...state, scrollToLeft: value}
      | MouseIsDown => {...state, mouseIsDown: true}
      | MouseIsUp => {...state, mouseIsDown: false}
      | LastPosition(value) => {...state, lastPosition: value}
      }
    });

  let%hook (plannerWidth, setPlannerWidth) = Hooks.state(0);

  let dayWidth =
    if (plannerWidth / 7 < 200) {
      200;
    } else {
      plannerWidth / 7;
    };

  <View style=root onDimensionsChanged={e => {setPlannerWidth(_ => e.width)}}>
    <View
      style={Utils.Style.merge(
        container,
        Style.[top(state.scrollToTop |> int_of_float)],
      )}>
      <View style=hours>
        {List.map(hour => <Hour hour />, Utils.range(0, 25))
         |> React.Expert.jsx_list}
      </View>
      <View style=days>
        <View
          style=Style.[
            position(`Absolute),
            flexDirection(`Row),
            left(state.scrollToLeft |> int_of_float),
            top(0),
            bottom(0),
          ]
          onMouseDown={e => {
            dispatch(MouseIsDown);
            dispatch(LastPosition({x: e.mouseX, y: e.mouseY}));
          }}
          onMouseUp={e => {dispatch(MouseIsUp)}}
          onMouseMove={e =>
            if (state.mouseIsDown) {
              let diffY = e.mouseY -. state.lastPosition.y;
              let diffX = e.mouseX -. state.lastPosition.x;
              dispatch(LastPosition({x: e.mouseX, y: e.mouseY}));
              dispatch(
                ScrollToTop(
                  {let newValue = state.scrollToTop +. diffY;
                   let visibleHourCount =
                     Utils.Window.getWindowSize().height / 60 |> float_of_int;

                   if (newValue > 0.) {
                     0.;
                   } else if (newValue < (-60.)
                              *. (25. -. visibleHourCount)
                              -. 20.) {
                     state.scrollToTop;
                   } else {
                     newValue;
                   }},
                ),
              );
              dispatch(
                ScrollToLeft(
                  {let newValue = state.scrollToLeft +. diffX;
                   let maxValue =
                     plannerWidth - (dayWidth * 7 + 30) |> float_of_int;

                   if (newValue > 0.) {
                     0.;
                   } else if (newValue < maxValue) {
                     state.scrollToLeft;
                   } else {
                     newValue;
                   }},
                ),
              );
            }
          }
        />
      </View>
    </View>
  </View>;
};