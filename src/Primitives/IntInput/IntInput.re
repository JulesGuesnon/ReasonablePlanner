open Revery;
open Revery.UI;

let%component make =
              (
                ~placeholder,
                ~onChangeValue,
                ~placeholderColor=Colors.gray,
                ~style=[],
                (),
              ) => {
  let%hook (value, setValue) = Hooks.state("");

  <Components.Input
    placeholder
    placeholderColor
    onChange={(value, _) => {
      switch (value |> int_of_string) {
      | value =>
        setValue(_ => value |> string_of_int);
        onChangeValue(value);
      | exception error =>
        setValue(value => value);
        onChangeValue(0);
      }
    }}
    value
    style
  />;
};