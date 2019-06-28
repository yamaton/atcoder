open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let s = stdin.ReadLine()

s
|> String.filter (fun c -> c = '1')
|> String.length
|> printfn "%d"
