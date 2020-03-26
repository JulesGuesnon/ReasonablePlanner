open Revery;
open Revery.UI;

open ColorPickerStyle;

let%component make = () => {
  let%hook (color, setColor) = Hooks.state("#FFF");
  let%hook (hasColorPicker, setHasColorPicker) = Hooks.state(false);

  GlobalState.subscribe(state => {setColor(_ => state.colorPickerValue)});

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
    <View style={root(color)}>
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