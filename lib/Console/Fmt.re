open Pastel;
open Optional.Syntax;

let format = (~inverse=?, s) => {
  <Pastel inverse={inverse || false}> s </Pastel>;
};

let red = s => <Pastel color=Red> {format(s)} </Pastel>;
let black = s => <Pastel> {format(~inverse=true, s)} </Pastel>;
