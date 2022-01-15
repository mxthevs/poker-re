type state = {
  mutable deck: list(Card.t),
  mutable drawn_cards: list(Card.t),
};

let draw = (n, state) => {
  let rec aux = (count, drawn) =>
    if (count == n) {
      drawn;
    } else {
      switch (state.deck) {
      | [] => drawn
      | [top, ...rest] =>
        state.deck = rest;
        state.drawn_cards = [top, ...state.drawn_cards];
        aux(count + 1, [top, ...drawn]);
      };
    };

  aux(1, []);
};

let flop = draw(3);
let turn = state => List.hd(draw(1, state));
let river = state => List.hd(draw(1, state));
