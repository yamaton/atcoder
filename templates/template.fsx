let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int

let format tf =
    if tf then "Yes"
    else "No"

let unwrapOr (alt: 'a) (wrapped: 'a option) =
    match wrapped with
    | Some x -> x
    | None -> alt
 