open Revery;
open Revery.UI;

let root =
  Style.[
    backgroundColor(Colors.rebeccaPurple),
    flexGrow(1),
    borderRight(~color=Colors.black, ~width=2),
    alignItems(`Center),
    minWidth(200),
  ];

let taskContainer =
  Style.[position(`Absolute), top(60), left(0), right(0), bottom(0)];

let text =
  Style.[
    fontSize(20),
    fontFamily("Roboto-Regular.ttf"),
    color(Colors.white),
    justifyContent(`Center),
    backgroundColor(Colors.red),
  ];