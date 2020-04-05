open Revery;
open Revery.UI;

module Styles = {
  let root =
    Style.[
      position(`Absolute),
      left(0),
      top(0),
      right(0),
      height(Theme.Sizes.calendarTopBarHeight),
      justifyContent(`Center),
      alignItems(`Center),
    ];

  let text = Utils.Style.textStyleFromFontSize(16.);
};

let%component make = () => {
  let%hook (state, dispatch) = GlobalState.useState();

  let text =
    String.concat(", ", Utils.Date.monthsOfWeek(state.week))
    ++ " "
    ++ string_of_int(List.nth(state.week, 0).day)
    ++ " - "
    ++ string_of_int(List.nth(state.week, 6).day)
    ++ ", "
    ++ string_of_int(state.year);

  <View style=Styles.root> <Text style=Styles.text text /> </View>;
};