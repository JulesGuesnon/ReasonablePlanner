open Revery;
open Revery.UI;

module Store = {
  let subscriptions = ref([]);
  let oldRoute = ref("index");
  let route = ref("index");

  let updateRoute = newRoute => {
    oldRoute := route^;
    route := newRoute;

    subscriptions^ |> List.iter(sub => sub(oldRoute^, newRoute));
    (oldRoute^, newRoute);
  };

  let subscribe = cb => {
    subscriptions := List.append(subscriptions^, [cb]);
  };
};

type action =
  | Route(string);

type state = {currentRoute: string};

let reducer = (action, state) => {
  switch (action) {
  | Route(route) => {currentRoute: route}
  };
};

let%component make = (~render, ()) => {
  let%hook (state, dispatch) =
    Hooks.reducer(~initialState={currentRoute: Store.route^}, reducer);

  let%hook () =
    Hooks.effect(
      OnMount,
      () => {
        Store.subscribe((_, newRoute) => dispatch(Route(newRoute)));
        None;
      },
    );

  <View> {render(state.currentRoute)} </View>;
};