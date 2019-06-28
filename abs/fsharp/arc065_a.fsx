let rev (s : string) =
    s.ToCharArray()
    |> Array.rev
    |> System.String

let rec solve (s : string) =
    if s.Equals("") then true
    elif s.StartsWith(rev "dreamer") then solve (s.[7..])
    elif s.StartsWith(rev "eraser") then solve (s.[6..])
    elif s.StartsWith(rev "dream") || s.StartsWith(rev "erase") then
        solve (s.[5..])
    else false

let format tf =
    if tf then "YES"
    else "NO"

let s = stdin.ReadLine()

s
|> rev
|> solve
|> format
|> printfn "%s"
