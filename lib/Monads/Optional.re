module Infix = {
  let (||) = (maybe, default) => {
    switch (maybe) {
    | Some(value) => value
    | None => default
    };
  };
};
