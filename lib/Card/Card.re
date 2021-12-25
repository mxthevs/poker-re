module Suit = Card_Suit;
module Value = Card_Value;

type t =
  | Card(Value.t, Suit.t)
  | Joker;

exception Invalid_format(string);

let invalid_format = s => {
  raise(Invalid_format(Printf.sprintf("%s is not a valid card format", s)));
};

let to_string = card => {
  switch (card) {
  | Card(value, suit) =>
    switch (suit) {
    | Spades => Printf.sprintf("%s of spades", Value.to_string(value))
    | Diamonds => Printf.sprintf("%s of diamonds", Value.to_string(value))
    | Clubs => Printf.sprintf("%s of clubs", Value.to_string(value))
    | Hearts => Printf.sprintf("%s of hearts", Value.to_string(value))
    }
  | Joker => "Joker"
  };
};

let of_string = card => {
  switch (Helpers.split(~str=card, ~c=' ')) {
  | [suit, _, value] => Card(Value.of_string(value), Suit.of_string(suit))
  | [joker] when joker == "Joker" => Joker
  | unknown => invalid_format(String.concat(" ", unknown))
  };
};

let is_joker = card => {
  switch (card) {
  | Joker => true
  | Card(_, _) => false
  };
};
