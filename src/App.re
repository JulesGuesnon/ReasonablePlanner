open Revery;
open Revery.UI;
open GlobalState.Date.Types;

let init = app => {
  Timber.App.enable();
  Timber.App.setLevel(Timber.Level.perf);

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

  let _: Revery.UI.renderFunction = UI.start(win, <Kernel />);
  ();
};

let run = () => Revery.App.start(init);