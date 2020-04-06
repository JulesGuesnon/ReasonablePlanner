open Types_Date;

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