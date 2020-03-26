open Revery;
open Revery.UI;

let sidebarSize = 200;
let sidebarPadding = 10;
let root =
  Style.[
    width(sidebarSize),
    backgroundColor(Colors.aquamarine),
    alignItems(`Center),
    justifyContent(`Center),
    position(`Absolute),
    left(0),
    top(0),
    bottom(0),
    padding(sidebarPadding),
  ];

let text =
  Style.[
    fontSize(20),
    fontFamily("Roboto-Regular.ttf"),
    color(Colors.white),
  ];

let input =
  Style.[
    height(30),
    border(~color=Colors.white, ~width=2),
    color(Colors.white),
    width(sidebarSize - sidebarPadding * 2),
  ];

let textarea =
  Style.[
    height(60),
    border(~color=Colors.white, ~width=2),
    color(Colors.white),
    width(sidebarSize - sidebarPadding * 2),
  ];