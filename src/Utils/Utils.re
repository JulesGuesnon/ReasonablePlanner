open Revery.UI;

module Date = Utils_Date;
module Style = Utils_Style;
module Window = Utils_Window;
module Int = Utils_Int;
module Format = Utils_Format;

let rec range = (start: int, end_: int) =>
  if (start >= end_) {
    [];
  } else {
    [start, ...range(start + 1, end_)];
  };