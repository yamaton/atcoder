open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let [| a; b |] = readIntArray()

let res =
    if ((a * b) % 2 = 0) then "Even"
    else "Odd"

res |> printfn "%s"
