open Revery;
open Revery.UI;

type icon =
  | Home
  | Gear
  | Nav;

let make = (~icon, ~width, ~height, ~opacity=1.0, ()) => {
  switch (icon) {
  | Home => <Image src="home-outline.png" width height opacity />
  | Gear => <Image src="settings-2-outline.png" width height opacity />
  | Nav => <Image src="nav.png" width height opacity />
  };
};