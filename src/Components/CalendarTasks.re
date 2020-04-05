open Revery;
open Revery.UI;

module Styles = {
  let root = (~width as w) =>
    Style.[
      flexGrow(1),
      width(w),
      minWidth(Theme.Sizes.minimumDayWidth),
      borderRight(~color=Theme.Colors.lightGray, ~width=2),
    ];
};

let make = (~tasks, ~width, ()) => {
  <View style={Styles.root(~width)}>
    {List.map(task => <CalendarTask task width />, tasks)
     |> React.Expert.jsx_list}
  </View>;
};