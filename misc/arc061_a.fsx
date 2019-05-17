// https://arc061.contest.atcoder.jp/tasks/arc061_a

open System

let rec solve (s: string) i =
    seq {
        if (s = "") then yield 0L
        elif (i = String.length s) then yield int64 s
        else
            yield! Seq.map (fun x -> x + int64 s.[..(i - 1)]) (solve s.[i..] 1)
            yield! solve s (i + 1)
    }

let S = stdin.ReadLine()
(S, 1) ||> solve |> Seq.sum |> printfn "%d"
