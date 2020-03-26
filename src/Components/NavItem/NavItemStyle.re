open Revery;
open Revery.UI;

let root =
  Style.[
    width(100),
    flexDirection(`Row),
    alignItems(`Center),
    backgroundColor(Colors.red),
    boxShadow(
      ~xOffset=4.,
      ~yOffset=0.,
      ~blurRadius=5.,
      ~spreadRadius=0.,
      ~color=Colors.black,
    ),
  ];