type t =
  | Ace
  | Numeric(int)
  | Jack
  | Queen
  | King;

exception Invalid_value(string);

let invalid_value = s => {
  raise(Invalid_value(Printf.sprintf("%s is not a valid card value", s)));
};

let to_string = v => {
  switch (v) {
  | Ace => "Ace"
  | Numeric(n) => Int.to_string(n)
  | Jack => "Jack"
  | Queen => "Queen"
  | King => "King"
  };
};

let of_string = s => {
  switch (s) {
  | "Ace" => Ace
  | "Jack" => Jack
  | "Queen" => Queen
  | "King" => King
  | numeric => Numeric(int_of_string(numeric))
  };
};

let of_int = n => {
  switch (n) {
  | 1 => Ace
  | n when n > 1 && n < 11 => Numeric(n)
  | 11 => Jack
  | 12 => Queen
  | 13 => King
  | _ => invalid_value(string_of_int(n))
  };
};
