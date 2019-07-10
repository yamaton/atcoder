open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let n = readInt()
let xs = readIntArray()

let alice =
    xs
    |> Array.sortDescending
    |> Array.toSeq
    |> Seq.indexed
    |> Seq.filter (fun (i, v) -> i % 2 = 0)
    |> Seq.sumBy (fun (i, v) -> v)

let bob = Array.sum xs - alice

printfn "%d" (alice - bob)
