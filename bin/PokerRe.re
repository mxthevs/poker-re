open Poker;

let () =
  Deck.make()
  |> Deck.remove_jokers
  |> Deck.shuffle
  |> List.map(Card.to_notty_image)
  |> List.iter(image => {
       Notty_unix.output_image(image);
       print_string("\n");
     });
