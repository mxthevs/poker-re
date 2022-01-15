type state = {
  mutable deck: list(Card.t),
  mutable drawn_cards: list(Card.t),
};

let draw: (int, state) => list(Card.t);

let flop: state => list(Card.t);
let turn: state => Card.t;
let river: state => Card.t;
