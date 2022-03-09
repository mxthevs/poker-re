let get_with_default = (maybe, default) => {
  switch (maybe) {
  | Some(value) => value
  | None => default
  };
};

module Syntax = {
  let (||) = get_with_default;
};
