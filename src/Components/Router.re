open LightRouter;

module RouterConfig = {
  type route =
    | Home
    | Settings;

  let defaultRoute = Home;

  let nameFromRoute = route => {
    switch (route) {
    | Home => "Home"
    | Settings => "Settings"
    };
  };
};

include Make(RouterConfig);