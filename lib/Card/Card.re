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
    open Fmt;

    let value = Value.to_string(value);
    switch (suit) {
    | Spades => black(Printf.sprintf("%s of spades ♠️", value))
    | Diamonds => red(Printf.sprintf("%s of diamonds ♦️", value))
    | Clubs => black(Printf.sprintf("%s of clubs ♣️", value))
    | Hearts => red(Printf.sprintf("%s of hearts ♥️", value))
    };
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
