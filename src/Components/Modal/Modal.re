open Revery;
open Revery.UI;

let%component make =
              (
                ~children,
                ~isVisible,
                ~style,
                ~fadeTime=Time.milliseconds(100),
                ~fadeEasing=Easing.easeOut,
                ~maxOpacity=1.0,
                ~onClick=?,
                (),
              ) => {
  let%hook (transitionOpacity, opacityTo) =
    Hooks.transition(
      ~duration=fadeTime,
      ~easing=Easing.easeOut,
      if (isVisible) {maxOpacity} else {0.},
    );

  let%hook () =
    Hooks.effect(
      If((!=), isVisible),
      () => {
        opacityTo(if (isVisible) {maxOpacity} else {0.});
        None;
      },
    );

  switch (onClick) {
  | Some(onClick) =>
    <Components.Clickable
      style=Style.[`Opacity(transitionOpacity), ...style] onClick>
      children
    </Components.Clickable>
  | None =>
    <View style=Style.[`Opacity(transitionOpacity), ...style]>
      children
    </View>
  };
};