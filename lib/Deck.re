type t = list(Card.t);

let make = (): t => {
  open Card;

  let rec aux = (count, acc) => {
    switch (count) {
    | c when c > 52 => acc
    | _ =>
      let v = to_val;
      let deck =
        switch (count) {
        | n when n <= 13 => [Card(v(n), Spades), ...acc]
        | n when n > 13 && n <= 26 => [Card(v(n - 13), Diamonds), ...acc]
        | n when n > 26 && n <= 39 => [Card(v(n - 26), Clubs), ...acc]
        | n => [Card(v(n - 39), Hearts), ...acc]
        };

      aux(count + 1, deck);
    };
  };

  aux(1, [])
  |> List.append(Helpers.range(2) |> List.map(_ => Joker))
  |> List.rev;
};

let remove_jokers = (deck: t): t => {
  List.filter(card => !Card.is_joker(card), deck);
};

let shuffle = (deck: t): t => {
  let nd = List.map(card => (Random.bits(), card), deck);
  let sond = List.sort(compare, nd);
  List.map(snd, sond);
};
