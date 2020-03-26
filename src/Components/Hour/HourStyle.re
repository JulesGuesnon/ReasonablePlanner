open Revery;
open Revery.UI;

let root =
  Style.[
    width(30),
    height(60),
    justifyContent(`FlexEnd),
    alignItems(`Center),
  ];

let line =
  Style.[
    backgroundColor(Colors.red),
    width(30),
    height(2),
    position(`Absolute),
    left(0),
    bottom(0),
  ];