open Revery.UI;

let root =
  Style.[
    position(`Absolute),
    left(200),
    right(0),
    top(0),
    bottom(0),
    overflow(`Hidden),
  ];

let container =
  Style.[
    position(`Absolute),
    flexDirection(`Row),
    right(0),
    bottom(0),
    left(0),
  ];

let days =
  Style.[
    position(`Absolute),
    flexDirection(`Row),
    left(30),
    top(0),
    bottom(0),
    right(0),
    overflow(`Hidden),
  ];

let hours =
  Style.[
    position(`Absolute),
    left(0),
    top(0),
    width(30),
    alignItems(`Center),
  ];

let text = theme =>
  Style.[fontSize(20), fontFamily("Roboto-Regular.ttf"), color(theme)];