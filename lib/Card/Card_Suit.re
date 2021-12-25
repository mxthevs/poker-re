type t =
  | Spades
  | Diamonds
  | Clubs
  | Hearts;

exception Invalid_suit(string);

let invalid_suit = s => {
  raise(Invalid_suit(Printf.sprintf("%s is not a valid suit", s)));
};

let of_string = s => {
  switch (s) {
  | "spades" => Spades
  | "diamonds" => Diamonds
  | "clubs" => Clubs
  | "hearts" => Hearts
  | _ => invalid_suit(s)
  };
};
