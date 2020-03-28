open Revery;
open Revery.UI;

let make = (~onClick, ()) => {
  <Components.Clickable onClick>
    <View
      style=Style.[
        flexDirection(`Column),
        width(25),
        height(13),
        justifyContent(`SpaceBetween),
      ]>
      <View
        style=Style.[backgroundColor(Colors.black), height(3), width(20)]>
        <Text
          style=Style.[
            fontFamily("Roboto-Regular.ttf"),
            color(Colors.black),
            fontSize(16.0),
          ]
        />
      </View>
      <View
        style=Style.[backgroundColor(Colors.black), height(3), width(25)]>
        <Text
          style=Style.[
            fontFamily("Roboto-Regular.ttf"),
            color(Colors.black),
            fontSize(16.0),
          ]
        />
      </View>
      <View
        style=Style.[backgroundColor(Colors.black), height(3), width(15)]>
        <Text
          style=Style.[
            fontFamily("Roboto-Regular.ttf"),
            color(Colors.black),
            fontSize(16.0),
          ]
        />
      </View>
    </View>
  </Components.Clickable>;
};