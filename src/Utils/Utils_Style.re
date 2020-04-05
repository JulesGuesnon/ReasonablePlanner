open Revery.UI;

let textStyleFromFontSize = size =>
  Style.[
    fontSize(size),
    fontFamily("Roboto-Regular.ttf"),
    color(Theme.Colors.fontDark),
  ];

let fullSize =
  Style.[position(`Absolute), left(0), right(0), top(0), bottom(0)];

let merge = (style1, style2) => List.merge((_, _) => 0, style1, style2);