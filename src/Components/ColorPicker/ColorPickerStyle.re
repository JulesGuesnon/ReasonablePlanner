open Revery;
open Revery.UI;

let root = (~bgColor) =>
  Style.[
    width(75),
    height(30),
    borderRadius(3.),
    border(~color=Colors.black, ~width=2),
    backgroundColor(bgColor |> Color.hex),
    marginTop(10),
    marginBottom(10),
  ];