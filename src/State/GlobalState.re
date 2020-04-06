open Revery.UI;

module Helpers = GlobalState_Helpers;

module Store = {
  type state = {
    year: int,
    week: Types.Date.week,
    tasks: Types.Task.tasks,
    window: option(Revery.Window.t),
    colorPickerValue: string,
  };

  type action =
    | Init(state)
    | Year(int)
    | Window(option(Revery.Window.t))
    | AddTask(Types.Task.task)
    | ColorChanged(string)
    | PreviousWeek
    | NextWeek;

  let subscriptions = ref([]);

  let state =
    ref({
      year: 2020,
      week: [],
      window: None,
      tasks: [],
      colorPickerValue: "#FFF",
    });

  let setState = newState => {
    state := newState;
  };

  let dispatch = action => {
    switch (action) {
    | Init(state) => setState(state)
    | Year(year) => setState({...state^, year})
    | Window(window) => setState({...state^, window})
    | AddTask(task) => setState({...state^, tasks: state^.tasks @ [task]})
    | ColorChanged(color) => setState({...state^, colorPickerValue: color})
    | PreviousWeek =>
      let week =
        Engine.getWeekOfDay(
          ~day=Engine.getRelativeDay(~day=List.nth(state^.week, 0), ~gap=-1),
        );
      setState({...state^, week});
    | NextWeek =>
      let week =
        Engine.getWeekOfDay(
          ~day=Engine.getRelativeDay(~day=List.nth(state^.week, 6), ~gap=1),
        );
      setState({...state^, week});
    };

    List.iter(subscription => subscription(state^), subscriptions^);
  };

  let subscribe = cb => {
    subscriptions := List.append(subscriptions^, [cb]);
  };

  let unsubscribe = cb => {
    subscriptions :=
      List.filter(subscription => subscription != cb, subscriptions^);
  };
};

let useState = () => {
  let%hook (_, dispatch) =
    Hooks.reducer(~initialState=Store.state^, (_, _) => Store.state^);

  let%hook _ =
    Hooks.effect(
      OnMount,
      () => {
        Store.subscribe(_ => dispatch());
        None;
      },
    );

  (Store.state^, Store.dispatch);
};