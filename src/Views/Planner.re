open Revery;
open Revery.UI;
open GlobalState.Task.Types;

let make = () => {
  let week = Utils.Date.getWeekFromDay(~day=Utils.Date.getCurrentDay());
  let tasks =
    week
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
  <Calendar week tasks />;
};