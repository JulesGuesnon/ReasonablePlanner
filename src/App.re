open Revery;
open Revery.UI;
open Types.Date;

Engine.getWeekOfDay(~day=Engine.getCurrentDay());
let init = app => {
  /*Timber.App.enable();
    Timber.App.setLevel(Timber.Level.perf);*/

  NativeBindings.setup();
  let win = App.createWindow(app, "ReasonnablePlanner");

  Window.setBackgroundColor(win, Theme.Colors.background);
  Window.maximize(win);

  GlobalState.Store.dispatch(
    Init({
      year: 2019,
      week: Engine.getWeekOfDay(~day=Engine.getCurrentDay()),
      window: Some(win),
      tasks: [],
      colorPickerValue: "#FFF",
    }),
  );

  let _: Revery.UI.renderFunction = UI.start(win, <Kernel />);
  ();
};

let run = () => Revery.App.start(init);