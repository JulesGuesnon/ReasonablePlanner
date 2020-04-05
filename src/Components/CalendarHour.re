open Revery;
open Revery.UI;

module Styles = {
  let root =
    Style.[
      width(Theme.Sizes.hoursWidth),
      height(Theme.Sizes.hourHeight),
      alignItems(`Center),
      justifyContent(`FlexStart),
    ];

  let line = (width as w) =>
    Style.[
      position(`Absolute),
      left(Theme.Sizes.hoursWidth),
      top(10),
      width(w),
      height(2),
      backgroundColor(Color.rgba(0., 0., 0., 0.1)),
    ];

  let text = Utils.Style.textStyleFromFontSize(Theme.Sizes.hourFontSize);
};

let make = (~hour, ~lineWidth, ()) => {
  <View style=Styles.root>
    <Text style=Styles.text text={hour |> Utils.Format.hour} />
    <View style={Styles.line(lineWidth)} />
  </View>;
};