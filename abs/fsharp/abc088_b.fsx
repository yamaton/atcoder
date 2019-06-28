open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let n = readInt()
let xs = readIntArray() |> Array.sortDescending

let alice =
    xs
    |> Array.indexed
    |> Array.filter (fun (i, v) -> i % 2 = 0)
    |> Array.sumBy (fun (i, v) -> v)

let bob = Array.sum xs - alice

printfn "%d" (alice - bob)
