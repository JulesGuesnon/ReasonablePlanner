open Revery;

let getWindowSize = () => {
  let {window}: GlobalState.Store.state = GlobalState.Store.state^;
  switch (window) {
  | Some(window) => Window.getRawSize(window)
  | None => {width: 0, height: 0}
  };
};