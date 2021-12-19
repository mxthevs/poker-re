type suit =
  | Spades
  | Diamonds
  | Clubs
  | Hearts;

type value =
  | Ace
  | Numeric(int)
  | Jack
  | Queen
  | King;

type t =
  | Card(value, suit)
  | Joker;

exception Invalid_suit(string);
exception Invalid_format(string);

let invalid_suit = s => {
  raise(Invalid_suit(Printf.sprintf("%s is not a valid suit", s)));
};
let invalid_format = s => {
  raise(Invalid_format(Printf.sprintf("%s is not a valid card format", s)));
};

let make = (~value, ~suit) => Card(value, suit);
let make_joker = () => Joker;

let val_ = v =>
  switch (v) {
  | Ace => "Ace"
  | Numeric(n) => Int.to_string(n)
  | Jack => "Jack"
  | Queen => "Queen"
  | King => "King"
  };

let to_val = s => {
  switch (s) {
  | "Ace" => Ace
  | "Jack" => Jack
  | "Queen" => Queen
  | "King" => King
  | other => Numeric(int_of_string(other))
  };
};

let to_suit = s => {
  switch (s) {
  | "spades" => Spades
  | "diamonds" => Diamonds
  | "clubs" => Clubs
  | "hearts" => Hearts
  | _ => invalid_suit(s)
  };
};

let to_string = card => {
  switch (card) {
  | Card(value, suit) =>
    switch (suit) {
    | Spades => Printf.sprintf("%s of spades", val_(value))
    | Diamonds => Printf.sprintf("%s of diamonds", val_(value))
    | Clubs => Printf.sprintf("%s of clubs", val_(value))
    | Hearts => Printf.sprintf("%s of hearts", val_(value))
    }
  | Joker => "Joker"
  };
};

let of_string = card => {
  switch (Helpers.split(~str=card, ~c=' ')) {
  | [suit, _, value] => Card(to_val(value), to_suit(suit))
  | [joker] when joker == "Joker" => Joker
  | _other => invalid_format(String.concat(" ", _other))
  };
};
