open Revery;
open Revery.UI;

let make = () =>
  <View>
    <Text
      style=Style.[
        fontFamily("Roboto-Regular.ttf"),
        color(Colors.black),
        fontSize(16.0),
      ]
      text="Settings"
    />
  </View>;