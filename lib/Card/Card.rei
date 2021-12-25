module Suit = Card_Suit;
module Value = Card_Value;

type t =
  | Card(Value.t, Suit.t)
  | Joker;

let to_string: t => string;
let of_string: string => t;

let is_joker: t => bool;
