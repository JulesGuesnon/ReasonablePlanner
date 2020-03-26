open Revery;
open Revery.UI;
open SidebarStyle;
open GlobalState_Task.Types;

type state = task;

type action =
  | Title(string)
  | Description(string)
  | Color(string)
  | Date(string)
  | Start(int)
  | End(int);

let%component make = () => {
  let%hook (state, dispatch) =
    Hooks.reducer(
      ~initialState={
        title: "",
        description: "",
        color: Colors.white,
        day: Utils.Date.getCurrentDay(),
        timing: {
          start: 0,
          end_: 1,
        },
      },
      (action, state) => {
      switch (action) {
      | Title(title) => {...state, title}
      | Description(description) => {...state, description}
      | Color(color) => {
          ...state,
          color:
            switch (Color.hex(color)) {
            | color => color
            | exception error => state.color
            },
        }
      | Date(date) => {
          ...state,
          day:
            Utils.Date.getRelativeDay(
              ~day=Utils.Date.getCurrentDay(),
              ~gap=
                switch (date |> int_of_string) {
                | value => value
                | exception error => 0
                },
            ),
        }
      | Start(start) => {
          ...state,
          timing: {
            ...state.timing,
            start,
          },
        }
      | End(end_) => {
          ...state,
          timing: {
            ...state.timing,
            end_,
          },
        }
      }
    });

  <View style=root>
    <Components.Input
      placeholder="Titre"
      onChange={(value, _) => {dispatch(Title(value))}}
      style=input
    />
    <Components.Input
      placeholder="Description"
      onChange={(value, _) => {dispatch(Description(value))}}
      style=textarea
    />
    <ColorPicker />
    <HourInput
      placeholder="Date"
      onChangeValue={value => {dispatch(Date(value))}}
      style=input
    />
    <IntInput
      placeholder="Start"
      onChangeValue={value => {dispatch(Start(value))}}
      style=input
    />
    <IntInput
      placeholder="End"
      onChangeValue={value => {dispatch(End(value))}}
      style=input
    />
    <Components.Clickable
      onClick={() => {GlobalState.dispatch(AddTask(state)) |> ignore}}>
      <Text
        text="Validate"
        style=Style.[
          fontSize(20.0),
          fontFamily("Roboto-Regular.ttf"),
          color(Colors.black),
        ]
      />
    </Components.Clickable>
  </View>;
};