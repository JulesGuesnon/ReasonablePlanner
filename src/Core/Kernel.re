open Revery;
open Revery.UI;

let%component make = () => {
  let%hook (_, name) = Router.useRoute();
  let%hook (navOpen, setNavOpen) = Hooks.state(false);

  <View
    style=Style.[
      position(`Absolute),
      top(0),
      left(0),
      right(0),
      bottom(0),
    ]>
    <Router
      style=Style.[
        position(`Absolute),
        left(60),
        top(60),
        bottom(0),
        right(0),
      ]
      render={route =>
        switch (route) {
        | Home => <Index />
        | Settings => <Settings />
        }
      }
    />
    <View
      style=Style.[
        position(`Absolute),
        left(60),
        top(0),
        right(0),
        height(60),
        padding2(10, 5),
        backgroundColor(Colors.red),
      ]>
      <NavButton onClick={() => {setNavOpen(_ => true)}} />
      <Text
        style=Style.[
          fontFamily("Roboto-Regular.ttf"),
          fontSize(50.),
          color(Colors.black),
        ]
        text=name
      />
    </View>
    <Nav isOpen=navOpen />
    <Modal
      isVisible=navOpen
      maxOpacity=0.5
      onClick={() => {setNavOpen(_ => false)}}
      style=Style.[
        backgroundColor(Color.rgb(0., 0., 0.)),
        position(`Absolute),
        left(200),
        top(0),
        right(0),
        bottom(0),
      ]>
      <View />
    </Modal>
  </View>;
};