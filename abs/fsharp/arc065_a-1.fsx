open System

let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let s = stdin.ReadLine()
let xs = [ "dream"; "dreamer"; "erase"; "eraser" ]

let truncate (ss : string) =
    let x = xs |> List.tryFind ss.EndsWith
    match x with
    | Some i -> Some(ss.[0..(ss.Length - 1 - i.Length)])
    | None -> None

let mutable k = s
let mutable ss = Some s

while (Option.isSome ss) do
    // eprintfn "%A" ss
    k <- Option.get ss
    ss <- truncate k

if (k.Length = 0) then "YES"
else "NO"
|> printfn "%s"
