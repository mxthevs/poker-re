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

let to_val: int => value;

let to_string: t => string;
let of_string: string => t;

let is_joker: t => bool;
