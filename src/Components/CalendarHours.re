open Revery;
open Revery.UI;

module Styles = {
  let root = (~scrollTop) =>
    Style.[
      position(`Absolute),
      left(0),
      top(Theme.Sizes.datesHeight + scrollTop),
      bottom(0),
      width(Theme.Sizes.hoursWidth),
      paddingTop(Theme.Sizes.hoursPaddingTop),
      borderRight(~color=Theme.Colors.lightGray, ~width=2),
      backgroundColor(Theme.Colors.white),
    ];
};

let make = (~hours, ~dayWidth, ~scrollTop, ()) => {
  <View style={Styles.root(~scrollTop)}>
    {hours
     |> List.map(hour => <CalendarHour hour lineWidth={7 * dayWidth} />)
     |> React.Expert.jsx_list}
  </View>;
};