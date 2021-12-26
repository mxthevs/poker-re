open Poker;

let () =
  Deck.make()
  |> Deck.remove_jokers
  |> Deck.shuffle
  |> List.map(Card.to_string)
  |> List.iter(Console.log);
