// https://atcoder.jp/contests/abc127_b

open System

let [| r; D; x0 |] = stdin.ReadLine().Split(' ') |> Array.map int
x0  |> Seq.unfold (fun x -> Some (x, r * x - D))
    |> Seq.tail
    |> Seq.take 10
    |> Seq.iter (printfn "%d")
