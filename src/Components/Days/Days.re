open Revery;
open Revery.UI;
open GlobalState.Date.Types;

let%component make = (~dayWidth, ()) => {
  let%hook (week, setWeek) = Hooks.state(GlobalState.state^.week);
  let%hook (effectTriggered, setEffectTriggered) = Hooks.state(false);

  let%hook () =
    Hooks.effect(
      If((!=), effectTriggered),
      () => {
        setEffectTriggered(_ => true);
        GlobalState.subscribe(state => {setWeek(_ => state.week)});
        None;
      },
    );

  List.map(
    day =>
      <Day day={day.day} wDay={day.wDay} width=dayWidth> <Tasks day /> </Day>,
    week,
  )
  |> React.Expert.jsx_list;
};