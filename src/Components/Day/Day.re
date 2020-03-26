open Revery;
open Revery.UI;
open DayStyle;

let make = (~children, ~day, ~wDay, ~width as dayWidth, ()) => {
  let formattedWDay =
    String.sub(Utils.Date.weekDayFromWDay(wDay), 0, 3)
    |> String.uppercase_ascii;

  <View style={Utils.Style.merge(root, Style.[width(dayWidth)])}>
    <Text
      style=Style.[
        fontFamily("Roboto-Regular.ttf"),
        color(Colors.black),
        fontSize(16.0),
      ]
      text={formattedWDay ++ " - " ++ string_of_int(day)}
    />
    <View style=taskContainer> children </View>
  </View>;
};