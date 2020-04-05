open Revery;
open Revery.UI;

let topBarHeight = 75;

module Styles = {
  let root =
    Style.[position(`Absolute), top(0), left(0), right(0), bottom(0)];

  let router =
    Style.[
      position(`Absolute),
      left(100),
      top(topBarHeight),
      bottom(20),
      right(20),
    ];

  let topBar =
    Style.[
      position(`Absolute),
      left(90),
      top(0),
      right(0),
      height(topBarHeight),
      padding2(10, 5),
      flexDirection(`Row),
      alignItems(`Center),
    ];

  let topBarText =
    Style.[marginLeft(16), ...Utils.Style.textStyleFromFontSize(20.0)];

  let modal =
    Style.[
      backgroundColor(Color.rgb(0., 0., 0.)),
      position(`Absolute),
      left(200),
      top(0),
      right(0),
      bottom(0),
    ];
};

let%component make = () => {
  let%hook (_, name) = Router.useRoute();
  let%hook (navOpen, setNavOpen) = Hooks.state(false);

  <View style=Styles.root>
    <Router
      style=Styles.router
      render={route =>
        switch (route) {
        | Home => <Planner />
        | Settings => <Settings />
        }
      }
    />
    <View style=Styles.topBar>
      <NavButton onClick={() => {setNavOpen(_ => true)}} />
      <Text style=Styles.topBarText text=name />
    </View>
    <Nav isOpen=navOpen />
    <Modal
      isVisible=navOpen
      maxOpacity=0.5
      onClick={() => {setNavOpen(_ => false)}}
      style=Styles.modal>
      <View />
    </Modal>
  </View>;
};