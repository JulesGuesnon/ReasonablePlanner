open Revery;
open Revery.UI;
open NavStyle;

type navElement = {
  icon: string,
  name: string,
};

let navElements = [
  {icon: "home", name: "Home"},
  {icon: "gear", name: "Settings"},
];

let make = () => {
  <View style=root>
    <View> <NavItem icon="home" text="Hello" /> </View>
  </View>;
};