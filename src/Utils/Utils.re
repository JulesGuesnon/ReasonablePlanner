open Revery.UI;

module Style = Utils_Style;
module Date = Utils_Date;
module Window = Utils_Window;
module String = Utils_String;
module Int = Utils_Int;
module Format = Utils_Format;

module Operands = {
  open Date.Operands;
};

let rec range = (start: int, end_: int) =>
  if (start >= end_) {
    [];
  } else {
    [start, ...range(start + 1, end_)];
  };