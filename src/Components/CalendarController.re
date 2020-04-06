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
      flexDirection(`Row),
    ];

  let textMargin = 10;
  let text =
    Style.[
      marginRight(textMargin),
      marginLeft(textMargin),
      ...Utils.Style.textStyleFromFontSize(16.),
    ];
};

module Arrow = {
  module Styles = {
    let text = Utils.Style.textStyleFromFontSize(16.);
  };

  type side =
    | Right
    | Left;

  let make = (~side, ~onClick, ()) => {
    <Components.Clickable onClick>
      <Text
        style=Styles.text
        text={
          switch (side) {
          | Right => ">"
          | Left => "<"
          }
        }
      />
    </Components.Clickable>;
  };
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

  <View style=Styles.root>
    <Arrow side=Left onClick={_ => dispatch(PreviousWeek)} />
    <Text style=Styles.text text />
    <Arrow side=Right onClick={_ => dispatch(NextWeek)} />
  </View>;
};