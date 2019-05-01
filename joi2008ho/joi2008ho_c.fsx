open System


let binarySearch (arr: 'a []) key =
  let isOK index =
      arr.[index] <= key

  let mutable ok = -1
  let mutable ng = arr.Length
  let mutable mid = -1

  while abs (ok - ng) > 1 do
      mid <- (ok + ng) / 2
      if isOK mid then ok <- mid
      else ng <- mid
  ok


let solve (ps: int []) n m =
    let ps = Array.append ps [| 0 |]
    let xs = seq {
      for i in 0..n do
        for j in i..n do
          yield ps.[i] + ps.[j]}
              |> Seq.filter (fun x -> x <= m)
              |> Seq.toArray |> Array.sort
    seq {
        for x in xs do
            let idx = binarySearch xs (m - x)
            yield xs.[idx] + x
    } |> Seq.max


let [| N; M |] = stdin.ReadLine().Split(' ') |> Array.map int
let ps = [| for i in 1..N -> stdin.ReadLine() |> int |]

// [<EntryPoint>]
// let main argv =
(ps, N, M)
|||> solve
|> printfn "%d"

  // 0