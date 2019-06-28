open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let [| n ; y |] = readIntArray()

let res =
    seq {
        for i in 0..n do
            for j in 0..(n - i) do
                let k = n - i - j
                if (10000 * i + 5000 * j + 1000 * k = y) then yield (i, j, k)
    }
    |> Seq.tryHead

match res with
| Some i -> i
| None -> (-1, -1, -1)
|||> printfn "%d %d %d"
