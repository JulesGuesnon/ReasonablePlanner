open Revery;
open Revery.UI;

let make = (~to_, ~text, ~fontSize=16, ()) => {
  <Components.Clickable
    onClick={_ => {Router.Store.updateRoute(to_) |> ignore}}>
    <Text
      style=Style.[
        fontFamily("Roboto-Regular.ttf"),
        color(Colors.black),
        fontSize(16.0),
      ]
      text
    />
  </Components.Clickable>;
};