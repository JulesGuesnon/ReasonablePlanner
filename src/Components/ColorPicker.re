open Revery;
open Revery.UI;

module Styles = {
  let root = (~bgColor) =>
    Style.[
      width(75),
      height(30),
      borderRadius(3.),
      border(~color=Colors.black, ~width=2),
      backgroundColor(bgColor |> Color.hex),
      marginTop(10),
      marginBottom(10),
    ];
};

let%component make = () => {
  let%hook (hasColorPicker, setHasColorPicker) = Hooks.state(false);

  let%hook (state, _) = GlobalState.useState();

  <Components.Clickable
    onClick={_ =>
      if (hasColorPicker) {
        NativeBindings.hide_color_picker();
        setHasColorPicker(_ => false);
      } else {
        NativeBindings.show_color_picker();
        setHasColorPicker(_ => true);
      }
    }>
    <View style={Styles.root(~bgColor=state.colorPickerValue)}>
      <Text
        text=""
        style=Style.[
          fontSize(20.0),
          fontFamily("Roboto-Regular.ttf"),
          color(Colors.black),
        ]
      />
    </View>
  </Components.Clickable>;
};