open Revery;
open Revery.UI;
open Types.Task;

module Styles = {
  let paddingL = 3;

  let root = (~height as h, ~width as w, ~order, ~top as t, ~color as c) =>
    Style.[
      position(`Absolute),
      top(t),
      /* Allow to make a padding and have a dynamic with. - 2 = borderRight */
      width(w - paddingL * 2 - 2),
      left(paddingL + w * order),
      height(h),
      backgroundColor(c),
      borderRadius(3.),
      padding(5),
    ];

  let text = Utils.Style.textStyleFromFontSize(16.0);
};

let make = (~task, ~width, ~order=0, ()) => {
  <View
    style={Styles.root(
      ~height=
        Theme.Sizes.hourHeight * (task.timing.end_ - task.timing.start) - 4,
      ~width,
      ~order,
      ~top=
        Theme.Sizes.hourHeight
        * task.timing.start
        + Theme.Sizes.hoursPaddingTop
        + int_of_float(Theme.Sizes.hourFontSize)
        - 1,
      ~color=task.color,
    )}>
    <Text style=Styles.text text={task.title} />
  </View>;
};