open Oni_Core;
open BenchFramework;

let largeBufferLine =
  String.make(10000, 'a')
  |> BufferLine.make(~indentation=IndentationSettings.default);

let lengthSlow = () => {
  let _ = largeBufferLine |> BufferLine.lengthSlow;
  ();
};

let lengthBounded = () => {
  let _ = largeBufferLine |> BufferLine.lengthBounded(~max=5000);
  ();
};

let getUCharExn = () => {
  let _ = largeBufferLine |> BufferLine.getUCharExn(~index=8000);
  ();
};

let getPositionAndWidth = () => {
  let _ = largeBufferLine |> BufferLine.getUCharExn(~index=9000);
  ();
};

let setup = () => ();
let options = Reperf.Options.create(~iterations=1000, ());

bench(~name="BufferLine: lengthSlow", ~options, ~setup, ~f=lengthSlow, ());

bench(
  ~name="BufferLine: lengthBounded",
  ~options,
  ~setup,
  ~f=lengthBounded,
  (),
);

bench(~name="BufferLine: getUCharExn", ~options, ~setup, ~f=getUCharExn, ());

bench(
  ~name="BufferLine: getPositionAndWidth",
  ~options,
  ~setup,
  ~f=getPositionAndWidth,
  (),
);
