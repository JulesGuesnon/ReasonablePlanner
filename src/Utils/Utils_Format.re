let with0 = str =>
  if (String.length(str) == 1) {
    "0" ++ str;
  } else {
    str;
  };

let day = day => String.sub(day, 0, 3) |> String.uppercase_ascii;
let date = date => date |> string_of_int |> with0;
let hour = hour => (hour |> string_of_int |> with0) ++ ":00";