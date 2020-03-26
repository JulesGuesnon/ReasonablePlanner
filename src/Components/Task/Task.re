open Revery;
open Revery.UI;
open TaskStyle;
open GlobalState.Task.Types;

let make = (~task, ()) => {
  <View
    style=Style.[
      position(`Absolute),
      top(-12),
      left(0),
      right(0),
      height(60),
      backgroundColor(Colors.red),
    ]>
    <Text
      style=Style.[
        fontFamily("Roboto-Regular.ttf"),
        color(Colors.black),
        fontSize(16.0),
      ]
      text={task.title}
    />
  </View>;
};