open Revery;
open Revery.UI;
open HourStyle;

let make = (~hour, ()) => {
  let formattedHour =
    if (hour < 13) {
      (hour |> string_of_int) ++ "AM";
    } else {
      (hour - 12 |> string_of_int) ++ "PM";
    };

  <View style=root>
    <Text
      style=Style.[
        fontFamily("Roboto-Regular.ttf"),
        color(Colors.black),
        fontSize(16.0),
      ]
      text=formattedHour
    />
  </View>;
};

/**<View style=line /> */;