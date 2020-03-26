open Revery;
open Revery.UI;

let%component make =
              (
                ~placeholder,
                ~onChangeValue: string => unit,
                ~placeholderColor=Colors.gray,
                ~style=[],
                (),
              ) => {
  let%hook (hourValue, setHourValue) = Hooks.state("00");
  let%hook (minuteValue, setMinuteValue) = Hooks.state("00");

  let updateValue = (currentValue, newValue, updateFunction) =>
    if (newValue |> String.length == 3) {
      let firstChar = newValue.[0];
      let secondChar = newValue.[1];

      if (firstChar != currentValue.[0]) {
        updateFunction(_ =>
          String.make(1, firstChar) ++ String.make(1, currentValue.[1])
        );
      } else if (secondChar != currentValue.[1]) {
        updateFunction(_ => {
          String.make(1, currentValue.[0]) ++ String.make(1, secondChar)
        });
      };
    } else if (newValue.[0] == currentValue.[0]) {
      updateFunction(_ => String.make(1, newValue.[0]) ++ "0");
    } else {
      updateFunction(_ => "0" ++ String.make(1, currentValue.[1]));
    };

  <Components.Input
    placeholder
    placeholderColor
    onChange={(value, cursorPosition) => {
      print_endline("Cursor position: " ++ string_of_int(cursorPosition));
      let splittedValue = String.split_on_char(':', value);
      updateValue(hourValue, List.nth(splittedValue, 0), setHourValue);
      updateValue(minuteValue, List.nth(splittedValue, 1), setMinuteValue);
    }}
    value={hourValue ++ ":" ++ minuteValue}
    style
  />;
};