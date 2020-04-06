open Revery;
open Revery.UI;
open Types.Date;

module Styles = {
  let root = (~scrollLeft) =>
    Style.[
      position(`Absolute),
      left(scrollLeft),
      right(0),
      top(0),
      flexDirection(`Row),
      height(Theme.Sizes.datesHeight),
      paddingLeft(Theme.Sizes.hoursWidth),
      borderBottom(~color=Theme.Colors.lightGray, ~width=2),
      backgroundColor(Theme.Colors.white),
    ];
};

let make = (~week: week, ~dayWidth as width, ~scrollLeft, ()) => {
  <View style={Styles.root(~scrollLeft)}>
    {week
     |> List.map(day => <CalendarDate day width />)
     |> React.Expert.jsx_list}
  </View>;
};