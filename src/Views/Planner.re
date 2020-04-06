open Revery;
open Revery.UI;
open Types.Task;

let%component make = () => {
  let%hook (state, _) = GlobalState.useState();
  let tasks =
    state.week
    |> List.mapi((i, day) =>
         [
           {
             title: "My task #" ++ string_of_int(i),
             description: "Some descriptions, pretty fun right",
             timing: {
               start: Random.int(12),
               end_: 12 + Random.int(12),
             },
             day,
             color:
               Color.rgb(
                 Random.float(1.),
                 Random.float(1.),
                 Random.float(1.),
               ),
           },
         ]
       );

  <View style=Utils.Style.fullSize>
    <CalendarController />
    <Calendar week={state.week} tasks />
  </View>;
};