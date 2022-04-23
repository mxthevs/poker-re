let red = string => {
  Notty.(I.string(~attr=A.(fg(red)), string));
};

let black = string => {
  Notty.(I.string(~attr=A.(fg(black)), string));
};
