let getStringDifference = (str1, str2) => {
  let toReturn = ref("");
  for (i in 0 to str2 |> String.length) {
    if (str1.[i] != str2.[i]) {
      toReturn := toReturn^ ++ (str2.[i] |> String.make(1));
    };
  };

  toReturn^;
};