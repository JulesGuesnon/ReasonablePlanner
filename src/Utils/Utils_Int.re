let stringToIntOrDefault = (str, default) => {
  switch (str |> int_of_string) {
  | value => value
  | exception e => default
  };
};