open Types.Date;

let monthsOfWeek = week => {
  let months = ref([]);

  week
  |> List.iter(day => {
       let month = Engine.Conversion.monthToString(day.month);
       let monthExist = months^ |> List.exists(m => m == month);
       if (!monthExist) {
         months := months^ @ [month];
       };
     });

  months^;
};