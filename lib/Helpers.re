let split = (~str, ~c) => {
  let rec rev_split' = (~str, ~i, ~c, ~acc) => {
    let split_exn = () => {
      let index = String.index_from(str, i, c);
      let before = String.sub(str, i, index - i);

      rev_split'(~str, ~c, ~i=index + 1, ~acc=[before, ...acc]);
    };

    try(split_exn()) {
    | Not_found => [String.sub(str, i, String.length(str) - i), ...acc]
    };
  };

  List.rev(rev_split'(~str, ~i=0, ~c, ~acc=[]));
};
