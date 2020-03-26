open Revery;
open Revery.UI;

let%component make = (~day, ()) => {
  let%hook (tasks, setTasks) =
    Hooks.state(
      GlobalState.Task.getTasksFromDay(day, GlobalState.state^.tasks),
    );

  let%hook () =
    Hooks.effect(
      OnMount,
      () => {
        GlobalState.subscribe(state => {
          setTasks(_ => GlobalState.Task.getTasksFromDay(day, state.tasks))
        });
        None;
      },
    );

  List.map(task => <Task task />, tasks) |> React.Expert.jsx_list;
};