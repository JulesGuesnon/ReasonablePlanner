open Revery;
open Revery.UI;

module Styles = {
  let root =
    Style.[
      flexDirection(`Column),
      width(25),
      height(13),
      justifyContent(`SpaceBetween),
    ];

  let bar = (~width as w) =>
    Style.[backgroundColor(Colors.black), height(3), width(w)];
};

let make = (~onClick, ()) => {
  <Components.Clickable onClick>
    <View style=Styles.root>
      <View style={Styles.bar(20)} />
      <View style={Styles.bar(25)} />
      <View style={Styles.bar(15)} />
    </View>
  </Components.Clickable>;
};