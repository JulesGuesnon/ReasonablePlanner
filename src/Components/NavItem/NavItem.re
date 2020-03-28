open Revery;
open Revery.UI;
open NavItemStyle;

let cap = (cap, value) =>
  if (value >= cap) {
    cap;
  } else {
    value;
  };

let%component make =
              (~to_, ~icon, ~text: string, ~isActive, ~hasMargin=true, ()) => {
  let%hook (transitionValue, setTransitionValue) =
    Hooks.transition(
      ~duration=Time.milliseconds(100),
      ~easing=Easing.easeOut,
      if (isActive) {1.0} else {0.},
    );

  let%hook () =
    Hooks.effect(
      If((!=), isActive),
      () => {
        if (isActive) {
          setTransitionValue(1.0);
        } else {
          setTransitionValue(0.);
        };
        None;
      },
    );

  <Router.RouterLink
    to_
    style={rootStyleFromProps(
      ~isActive,
      ~hasMargin,
      ~xOffset=transitionValue *. 2.,
      ~yOffset=transitionValue *. 2.,
      ~blurRadius=transitionValue *. 5.,
    )}>
    <Icon
      icon
      width=35
      height=35
      opacity={cap(1.0, transitionValue +. 0.5)}
    />
  </Router.RouterLink>;
};