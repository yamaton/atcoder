open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let n = readInt()
let mutable s = Set.empty

for i in 1..n do
    let x = stdin.ReadLine() |> int
    s <- s.Add(x)
s
|> Set.count
|> printfn "%d"
