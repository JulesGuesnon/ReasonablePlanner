open Revery;
open Revery.UI;

type icon =
  | Home
  | Settings;

let make = (~icon, ~width, ~height, ()) =>
  switch (icon) {
  | Home => <Image src="./home-outline.png" width height />
  | Settings => <Image src="./settings-2-outline.png" width height />
  };