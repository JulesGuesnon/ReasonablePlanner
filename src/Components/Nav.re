open Revery;
open Revery.UI;

module Styles = {
  let root = (~width as w) =>
    Style.[
      flexDirection(`Column),
      justifyContent(`Center),
      alignItems(`Center),
      position(`Absolute),
      left(0),
      top(0),
      bottom(0),
      backgroundColor(Theme.Colors.background),
      boxShadow(
        ~xOffset=2.,
        ~yOffset=0.,
        ~blurRadius=5.,
        ~spreadRadius=0.,
        ~color=Theme.Colors.lightGray,
      ),
      width(w),
    ];
};

type navElement = {
  to_: Router.route,
  icon: Icon.icon,
  name: string,
};

let navElements = [
  {to_: Home, icon: Home, name: "Home"},
  {to_: Settings, icon: Gear, name: "Settings"},
];

let nameFromRoute = route =>
  List.find(el => el.to_ == route, navElements).name;

let%component make = (~isOpen=false, ()) => {
  let%hook (route, _) = Router.useRoute();
  let%hook (width, setWidth) =
    Hooks.transition(
      ~duration=Time.milliseconds(100),
      ~easing=Easing.easeOut,
      if (isOpen) {200.} else {60.},
    );

  let%hook () =
    Hooks.effect(
      If((!=), isOpen),
      () => {
        setWidth(if (isOpen) {200.} else {60.});
        None;
      },
    );

  <View style={Styles.root(~width=width |> int_of_float)}>
    <View style=Style.[justifyContent(`Center), alignItems(`Center)]>
      {navElements
       |> List.mapi((i, {to_, icon, name}) =>
            <NavItem
              to_
              icon
              text=name
              isActive={route == to_}
              hasMargin={i != 0}
            />
          )
       |> React.Expert.jsx_list}
    </View>
  </View>;
};