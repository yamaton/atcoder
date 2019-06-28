open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let a = readInt()
let b = readInt()
let c = readInt()
let x = readInt()

seq {
    for i in 0..a do
        for j in 0..b do
            for k in 0..c do
            if (500 * i + 100 * j + 50 * k = x) then yield (i, j, k)
}
|> Seq.length
|> printfn "%d"
