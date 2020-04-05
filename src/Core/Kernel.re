open Revery;
open Revery.UI;

let topBarHeight = 100;

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
        left(100),
        top(topBarHeight),
        bottom(20),
        right(20),
      ]
      render={route =>
        switch (route) {
        | Home => <Planner />
        | Settings => <Settings />
        }
      }
    />
    <View
      style=Style.[
        position(`Absolute),
        left(90),
        top(0),
        right(0),
        height(100),
        padding2(10, 5),
        flexDirection(`Row),
        alignItems(`Center),
      ]>
      <NavButton onClick={() => {setNavOpen(_ => true)}} />
      <Text
        style=Style.[
          fontFamily("Roboto-Regular.ttf"),
          fontSize(20.),
          color(Colors.black),
          marginLeft(16),
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