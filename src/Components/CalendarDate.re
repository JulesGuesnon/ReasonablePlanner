open Revery;
open Revery.UI;
open Types.Date;

module Styles = {
  let root = (~width as w) =>
    Style.[
      width(w),
      height(Theme.Sizes.datesHeight),
      flexDirection(`Column),
      justifyContent(`Center),
      alignItems(`Center),
    ];

  let text = Utils.Style.textStyleFromFontSize(16.);
};

let make = (~day, ~width, ()) => {
  <View style={Styles.root(~width)}>
    <Text
      style=Styles.text
      text={day.wDay |> Engine.Conversion.wDayToString |> Utils.Format.day}
    />
    <Text style=Styles.text text={day.day |> Utils.Format.date} />
  </View>;
};