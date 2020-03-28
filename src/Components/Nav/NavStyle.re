open Revery;
open Revery.UI;

let root =
  Style.[
    flexDirection(`Column),
    justifyContent(`Center),
    alignItems(`Center),
    position(`Absolute),
    left(0),
    top(0),
    bottom(0),
    backgroundColor(Theme.Color.background),
    boxShadow(
      ~xOffset=2.,
      ~yOffset=0.,
      ~blurRadius=5.,
      ~spreadRadius=0.,
      ~color=Color.rgba(0., 0., 0., 0.2),
    ),
  ];

let rootStyleFromProps = (~width as w) => {
  Style.[width(w), ...root];
};