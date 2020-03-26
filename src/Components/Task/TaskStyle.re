open Revery;
open Revery.UI;

let rootStyleFromProps = color => {
  Style.[
    height(60),
    position(`Absolute),
    top(60),
    left(0),
    right(0),
    backgroundColor(color),
  ];
};