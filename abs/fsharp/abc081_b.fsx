open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int

let cnt x =
    x
    |> Seq.unfold (fun n ->
           if (n > 0) then Some(n, n / 2)
           else None)
    |> Seq.length

let n = readInt()
let xs = readIntArray()

xs
|> Seq.map cnt
|> Seq.min
|> printfn "%d"
