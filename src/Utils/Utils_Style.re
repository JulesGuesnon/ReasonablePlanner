open Revery.UI;

let textStyleFromFontSize = size =>
  Style.[
    fontSize(size),
    fontFamily("Roboto-Regular.ttf"),
    color(Revery.Colors.black),
    textWrap(`NoWrap),
    textOverflow(`Ellipsis),
  ];

let merge = (style1, style2) => List.merge((_, _) => 0, style1, style2);