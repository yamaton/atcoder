open System
let readInt () = stdin.ReadLine() |> int
let readIntArray () = stdin.ReadLine().Split(' ') |> Array.map int

