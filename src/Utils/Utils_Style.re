open Revery.UI;

let textStyleFromFontSize = size =>
  Style.[
    fontSize(size),
    fontFamily("Roboto-Regular.ttf"),
    color(Theme.Colors.fontDark),
  ];

let merge = (style1, style2) => List.merge((_, _) => 0, style1, style2);