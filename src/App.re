open Revery;
open Revery.UI;
open GlobalState.Date.Types;

let init = app => {
  //let _ = Log.listen((_, msg) => print_endline("LOG: " ++ msg));
  NativeBindings.setup();
  let win = App.createWindow(app, "ReasonnablePlanner");

  Window.setBackgroundColor(win, Theme.Color.background);
  Window.maximize(win);

  GlobalState.dispatch(
    Init({
      year: 2019,
      week: Utils.Date.getWeekFromDay(~day=Utils.Date.getCurrentDay()),
      window: Some(win),
      tasks: [],
      colorPickerValue: "#FFF",
    }),
  )
  |> ignore;

  let element =
    <View
      style=Style.[
        position(`Absolute),
        top(0),
        left(0),
        right(0),
        bottom(0),
      ]>
      <Nav />
      <Router
        render={route =>
          switch (route) {
          | "/" =>
            <View>
              <Text
                style=Style.[
                  fontFamily("Roboto-Regular.ttf"),
                  color(Colors.black),
                  fontSize(16.0),
                ]
                text="Index"
              />
              <RouterLink to_="salut" text="404" />
            </View>
          | _ =>
            <View>
              <Text
                style=Style.[
                  fontFamily("Roboto-Regular.ttf"),
                  color(Colors.black),
                  fontSize(16.0),
                ]
                text="404"
              />
              <RouterLink to_="/" text="Index" />
            </View>
          }
        }
      />
    </View>;

  let _ = UI.start(win, element);
  ();
};

let run = () => Revery.App.start(init);