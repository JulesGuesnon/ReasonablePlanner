open Revery;
open Revery.UI;

let root =
  Style.[
    width(40),
    height(40),
    flexDirection(`Row),
    alignItems(`Center),
    borderRadius(3.),
    justifyContent(`Center),
    alignItems(`Center),
  ];

let rootActive =
  Style.[
    backgroundColor(Theme.Color.white),
    boxShadow(
      ~xOffset=2.,
      ~yOffset=2.,
      ~blurRadius=5.,
      ~spreadRadius=0.,
      ~color=Color.rgba(0., 0., 0., 0.2),
    ),
  ];

let rootStyleFromProps =
    (~isActive, ~hasMargin, ~xOffset, ~yOffset, ~blurRadius) =>
  Style.[
    backgroundColor(
      if (isActive) {Colors.white} else {Theme.Color.background},
    ),
    marginTop(if (hasMargin) {20} else {0}),
    boxShadow(
      ~xOffset,
      ~yOffset,
      ~blurRadius,
      ~spreadRadius=0.,
      ~color=Color.rgba(0., 0., 0., 0.2),
    ),
    ...root,
  ];