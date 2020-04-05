open Unix;
open GlobalState.Date.Types;

module Operands = {
  let (%) = (value, modulo) => value mod modulo;
};
open Operands;

let getCurrentDay: unit => day =
  () => {
    let date = gmtime(time());
    {
      day: date.tm_mday,
      month: date.tm_mon,
      wDay: date.tm_wday,
      year: date.tm_year + 1900,
    };
  };

let weekDayFromWDay = wDay => {
  switch (wDay) {
  | 0 => "Sunday"
  | 1 => "Monday"
  | 2 => "Tuesday"
  | 3 => "Wednesday"
  | 4 => "Thursday"
  | 5 => "Friday"
  | 6 => "Saturday"
  | _ => raise(Not_found)
  };
};

let monthFromMon = mon => {
  switch (mon) {
  | 0 => "January"
  | 1 => "Febuary"
  | 2 => "March"
  | 3 => "April"
  | 4 => "May"
  | 5 => "June"
  | 6 => "July"
  | 7 => "August"
  | 8 => "September"
  | 9 => "October"
  | 10 => "November"
  | 11 => "December"
  | _ => raise(Not_found)
  };
};

let getNumberOfDaysInAMonth = month => {
  switch (month) {
  | 2 =>
    let year = Unix.gmtime(Unix.time()).tm_year;
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      29;
    } else {
      28;
    };
  | mon =>
    let isThirtyOne = mon % 2 == 1;
    if (mon < 8) {
      if (isThirtyOne) {31} else {30};
    } else if (!isThirtyOne) {
      31;
    } else {
      30;
    };
  };
};

let getRelativeWDay = (~wDay, ~gap) =>
  if (gap >= 0) {
    (wDay + gap) % 7;
  } else {
    7 + gap;
  };

let getFixedRelativeMonth = month =>
  if (month <= 0) {
    (12 + month, false, true);
  } else if (month > 12) {
    (month % 12, true, false);
  } else {
    (month, false, false);
  };

let getRelativeDay = (~day, ~gap) => {
  let originRelativeDay = day.day + gap;
  let relativeDay = ref(day.day + gap);
  let relativeMonth = ref(day.month);
  let relativeYear = ref(day.year);

  let numberOfDAyInMonth = ref(getNumberOfDaysInAMonth(relativeMonth^));

  if (originRelativeDay <= numberOfDAyInMonth^ && originRelativeDay > 0) {
    {
      day: relativeDay^,
      year: relativeYear^,
      month: relativeMonth^,
      wDay: getRelativeWDay(~wDay=day.wDay, ~gap),
    };
  } else {
    relativeDay := abs(relativeDay^);
    let (month, shouldAddYear, shouldSubstractYear) =
      getFixedRelativeMonth(
        if (originRelativeDay < 1) {
          relativeMonth^ - 1;
        } else {
          relativeMonth^ + 1;
        },
      );

    if (shouldAddYear) {
      relativeYear := relativeYear^ + 1;
    } else if (shouldSubstractYear) {
      relativeYear := relativeYear^ - 1;
    };

    relativeMonth := month;
    numberOfDAyInMonth := getNumberOfDaysInAMonth(relativeMonth^);

    while (relativeDay^ > 0) {
      relativeDay := relativeDay^ - numberOfDAyInMonth^;
      if (relativeDay^ >= 0) {
        let (month, shouldAddYear, shouldSubstractYear) =
          getFixedRelativeMonth(
            if (originRelativeDay < 1) {
              relativeMonth^ - 1;
            } else if (originRelativeDay > numberOfDAyInMonth^) {
              relativeMonth^ + 1;
            } else {
              relativeMonth^;
            },
          );

        if (shouldAddYear) {
          relativeYear := relativeYear^ + 1;
        } else if (shouldSubstractYear) {
          relativeYear := relativeYear^ - 1;
        };
        relativeMonth := month;
        numberOfDAyInMonth := getNumberOfDaysInAMonth(relativeMonth^);
      };
    };

    relativeDay :=
      (
        if (relativeDay^ == 0) {
          numberOfDAyInMonth^;
        } else if (originRelativeDay < 1) {
          abs(relativeDay^);
        } else {
          numberOfDAyInMonth^ - abs(relativeDay^);
        }
      );

    {
      day: relativeDay^,
      year: relativeYear^,
      month: relativeMonth^,
      wDay: getRelativeWDay(~wDay=day.wDay, ~gap),
    };
  };
};

let getWeekFromDay = (~day) => {
  let week = ref([]);

  if (day.wDay == 0) {
    week := [day];
    for (i in 1 to 6) {
      week := [getRelativeDay(~day, ~gap=- i), ...week^];
    };
  } else if (day.wDay == 1) {
    week := [day];
    for (i in 1 to 6) {
      week := [getRelativeDay(~day, ~gap=i)] @ week^;
    };
  } else {
    for (i in 1 to day.wDay - 1) {
      week := week^ @ [getRelativeDay(~day, ~gap=(day.wDay - i) * (-1))];
    };

    week := List.append(week^, [day]);

    for (i in day.wDay + 1 to 7) {
      week := week^ @ [getRelativeDay(~day, ~gap=i - day.wDay)];
    };
  };

  week^;
};

/**
 * Normal case
 * for (i in 1 to day.wDay - 1) {
      week := [getRelativeDay(~day, ~gap=(day.wDay - i) * (-1))] @ week^;
    };

    week := List.append([day], week^);

    for (i in day.wDay + 1 to 7) {
      week := [getRelativeDay(~day, ~gap=i - day.wDay)] @ week^;
    };
 */;

let monthsOfWeek = week => {
  let months = ref([]);

  week
  |> List.iter(day => {
       let month = monthFromMon(day.month);
       let monthExist = months^ |> List.exists(m => m == month);
       if (!monthExist) {
         months := months^ @ [month];
       };
     });

  months^;
};