open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let [| n; a; b |] = readIntArray()
let digitSum (x : int) = x.ToString() |> Seq.sumBy (fun c -> int c - int '0')

seq { 1..n }
|> Seq.filter (fun i ->
       let sum = digitSum i
       a <= sum && sum <= b)
|> Seq.sum
|> printfn "%d"
