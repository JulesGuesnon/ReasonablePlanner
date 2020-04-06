open Types.All;

let areDaysEquals = (day1: day, day2: day) =>
  if (day1.day == day2.day
      && day1.wDay == day2.wDay
      && day1.month == day2.month
      && day1.year == day2.year) {
    true;
  } else {
    false;
  };

let getTasksFromDay = (day: day, tasks: tasks) => {
  List.filter(task => areDaysEquals(day, task.day), tasks);
};