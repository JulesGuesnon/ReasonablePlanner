module Types = {
  type day = {
    day: int,
    wDay: int,
    month: int,
    year: int,
  };

  type week = list(day);
};
open Types;

let areDaysEquals = (day1, day2) =>
  if (day1.day == day2.day
      && day1.wDay == day2.wDay
      && day1.month == day2.month
      && day1.year == day2.year) {
    true;
  } else {
    false;
  };