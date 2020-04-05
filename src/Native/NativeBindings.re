external create_color_picker: unit => unit = "caml_create_color_picker";
external show_color_picker: unit => unit = "caml_show_color_picker";
external hide_color_picker: unit => unit = "caml_hide_color_picker";

let setup = () => {
  Callback.register("colorHandler", color => {
    GlobalState.Store.dispatch(ColorChanged("#" ++ color))
  });
  create_color_picker();
};