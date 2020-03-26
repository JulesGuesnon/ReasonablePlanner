module Date = GlobalState_Date;
module Task = GlobalState_Task;

type state = {
  year: int,
  week: Date.Types.week,
  tasks: Task.Types.tasks,
  window: option(Revery.Window.t),
  colorPickerValue: string,
};

type action =
  | Init(state)
  | Year(int)
  | Window(option(Revery.Window.t))
  | AddTask(Task.Types.task)
  | ColorChanged(string);

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
  };

  List.map(subscription => subscription(state^), subscriptions^);
};

type subscribe = (state => unit) => unit;
let subscribe: subscribe =
  cb => {
    subscriptions := List.append(subscriptions^, [cb]);
  };

let unsubscribe: subscribe =
  cb => {
    subscriptions :=
      List.filter(subscription => subscription != cb, subscriptions^);
  };