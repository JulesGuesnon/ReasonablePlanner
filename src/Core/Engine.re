open Unix;
open Types.Date;

module Conversion = {
  let tmToDay = tm => {
    day: tm.tm_mday,
    wDay: tm.tm_wday,
    month: tm.tm_mon,
    year: tm.tm_year + 1900,
  };

  let dayToTm = day => {
    let (_, tm) =
      Unix.mktime({
        tm_sec: 0,
        tm_min: 0,
        tm_hour: 0,
        tm_mday: day.day,
        tm_mon: day.month,
        tm_year: day.year - 1900,
        tm_wday: 1,
        tm_yday: 0,
        tm_isdst: true,
      });

    tm;
  };

  let dayToTime = day => {
    let (time, _) =
      Unix.mktime({
        tm_sec: 0,
        tm_min: 0,
        tm_hour: 12,
        tm_mday: day.day,
        tm_mon: day.month,
        tm_year: day.year - 1900,
        tm_wday: 0,
        tm_yday: 0,
        tm_isdst: true,
      });

    time;
  };

  let wDayToString = wDay => {
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

  let monthToString = month => {
    switch (month) {
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
};

open Conversion;

let getCurrentDay = () => tmToDay(gmtime(time()));

let getRelativeDay = (~day, ~gap) =>
  if (gap == 0) {
    day;
  } else {
    dayToTime(day) +. 24. *. 3600. *. float_of_int(gap) |> gmtime |> tmToDay;
  };

let getWeekOfDay = (~day) => {
  List.init(7, i => i)
  |> List.map(i => getRelativeDay(~day, ~gap=i - day.wDay));
};

exception YearNotProvided(string);

let getNumberOfDayInMonth = (~month, ~year=?, ()) => {
  switch (month) {
  | 1 =>
    switch (year) {
    | Some(y) =>
      if (y mod 4 == 0 && (y mod 100 != 0 || y mod 400 == 0)) {
        29;
      } else {
        28;
      }
    | None =>
      raise(
        YearNotProvided(
          "Year is required when you want to get the number of day of febuary",
        ),
      )
    }

  | 3
  | 5
  | 8
  | 10 => 30
  | _ => 31
  };
};

let getMonthOfDay = (~day) => {
  List.init(
    getNumberOfDayInMonth(~month=day.month, ~year=day.year - 1900, ()), i =>
    i
  )
  |> List.map(i => getRelativeDay(~day, ~gap=i - day.day));
};