open StarterLib;

let usage = "USAGE: esy x ReasonStarter <dividend> <divisor>";

let () =
  switch (Array.to_list(Sys.argv)) {
  | [_program, a, b] =>
    let a = float_of_string(a);
    let b = float_of_string(b);

    Math.safe_div(a, b)
    |> Option.fold(
         ~some=Printf.sprintf("Result of division is %.1f"),
         ~none="Cannot divide by 0",
       )
    |> print_endline;
  | _ =>
    prerr_endline(usage);
    exit(1);
  };
