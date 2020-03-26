open Revery;

let getWindowSize = () => {
  let {window}: GlobalState.state = GlobalState.state^;
  switch (window) {
  | Some(window) => Window.getRawSize(window)
  | None => {width: 0, height: 0}
  };
};