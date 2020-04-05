open Revery;
open Revery.UI;

let hours =
  Utils.range(0, 25)
  |> List.mapi((i, h) =>
       if (i == 24) {
         0;
       } else {
         h;
       }
     );

module Styles = {
  let root =
    Style.[
      position(`Absolute),
      left(0),
      right(0),
      top(0),
      bottom(0),
      backgroundColor(Theme.Colors.white),
      boxShadow(
        ~xOffset=0.,
        ~yOffset=0.,
        ~spreadRadius=0.,
        ~blurRadius=5.,
        ~color=Theme.Colors.lightGray,
      ),
      borderRadius(5.),
      overflow(`Hidden),
    ];

  let tasksContainer = (~scrollLeft, ~scrollTop) =>
    Style.[
      position(`Absolute),
      left(Theme.Sizes.hoursWidth + scrollLeft),
      top(Theme.Sizes.datesHeight + scrollTop),
      right(0),
      bottom(0),
      flexDirection(`Row),
    ];
};

type mouse = {
  x: float,
  y: float,
};

type size = {
  width: int,
  height: int,
};

type state = {
  scrollTop: float,
  scrollLeft: float,
  mouseIsDown: bool,
  lastPosition: mouse,
  planner: size,
};

type action =
  | ScrollTop(float)
  | ScrollLeft(float)
  | MouseIsDown
  | MouseIsUp
  | LastPosition(mouse)
  | Planner(size);

let%component make = (~week, ~tasks, ()) => {
  let%hook (state, dispatch) =
    Hooks.reducer(
      ~initialState={
        scrollTop: 0.,
        scrollLeft: 0.,
        mouseIsDown: false,
        lastPosition: {
          x: 0.,
          y: 0.,
        },
        planner: {
          width: 0,
          height: 0,
        },
      },
      (action, state) => {
      switch (action) {
      | ScrollTop(scrollTop) => {...state, scrollTop}
      | ScrollLeft(scrollLeft) => {...state, scrollLeft}
      | MouseIsDown => {...state, mouseIsDown: true}
      | MouseIsUp => {...state, mouseIsDown: false}
      | LastPosition(lastPosition) => {...state, lastPosition}
      | Planner(planner) => {...state, planner}
      }
    });

  let%hook () = Hooks.effect(OnMount, () => {None});

  let dayWidth =
    if (state.planner.width / 7 < Theme.Sizes.minimumDayWidth) {
      Theme.Sizes.minimumDayWidth;
    } else {
      state.planner.width / 7;
    };

  let {scrollLeft, scrollTop} = state;

  let update = (~delta) => {
    dispatch(
      ScrollTop(
        {
          let newValue = state.scrollTop +. delta.y;
          let visibleHourCount =
            state.planner.height / Theme.Sizes.hourHeight |> float_of_int;

          /**
            * Explanation : Get scrollTop limit so ~= get the height of the tasks
            * Multiply hour height by the total number of hours less those which are visibile (to avoid to have the block outside of the planner)
            * Add an hour height in order to hide midnight minus a padding to show the top of midnight
          */
          let maxValue =
            (- Theme.Sizes.hourHeight |> float_of_int)
            *. (25. -. visibleHourCount)
            +. float_of_int(Theme.Sizes.hourHeight)
            -. (Theme.Sizes.hourFontSize +. 30.);

          if (newValue > 0.) {
            0.;
          } else if (newValue < maxValue) {
            state.scrollTop;
          } else {
            newValue;
          };
        },
      ),
    );
    dispatch(
      ScrollLeft(
        {
          let newValue = state.scrollLeft +. delta.x;
          let maxValue =
            state.planner.width
            - (dayWidth * 7 + Theme.Sizes.hoursWidth)
            |> float_of_int;

          if (newValue > 0.) {
            0.;
          } else if (newValue < maxValue) {
            state.scrollLeft;
          } else {
            newValue;
          };
        },
      ),
    );
  };
  <View
    style=Styles.root
    onDimensionsChanged={({width, height}) =>
      dispatch(Planner({width, height}))
    }>
    <View
      style={Styles.tasksContainer(
        ~scrollLeft=int_of_float(scrollLeft),
        ~scrollTop=int_of_float(scrollTop),
      )}
      onMouseWheel={({deltaX as x, deltaY as y}) => {
        update(~delta={x: -. x *. 3., y: y *. 3.})
      }}
      onMouseDown={e => {
        dispatch(MouseIsDown);
        dispatch(LastPosition({x: e.mouseX, y: e.mouseY}));
      }}
      onMouseUp={e => {dispatch(MouseIsUp)}}
      onMouseMove={e => {
        dispatch(LastPosition({x: e.mouseX, y: e.mouseY}));

        if (state.mouseIsDown) {
          let x = e.mouseX -. state.lastPosition.x;
          let y = e.mouseY -. state.lastPosition.y;
          update(~delta={x, y});
        };
      }}>
      {tasks
       |> List.map(tasks => <CalendarTasks tasks width=dayWidth />)
       |> React.Expert.jsx_list}
    </View>
    <CalendarHours
      hours
      dayWidth
      scrollTop={state.scrollTop |> int_of_float}
    />
    <CalendarDates
      week
      dayWidth
      scrollLeft={state.scrollLeft |> int_of_float}
    />
  </View>;
};