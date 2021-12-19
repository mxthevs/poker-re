let safe_div = (a, b) =>
  if (b == 0.0) {
    None;
  } else {
    Some(a /. b);
  };
