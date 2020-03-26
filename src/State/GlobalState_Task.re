open GlobalState_Date.Types;

module Types = {
  type timing = {
    start: int,
    end_: int,
  };

  type task = {
    title: string,
    timing,
    day,
    description: string,
    color: Revery.Color.t,
  };

  type tasks = list(task);
};

open Types;

let getTasksFromDay = (day: day, tasks: tasks) => {
  List.filter(task => GlobalState_Date.areDaysEquals(day, task.day), tasks);
};