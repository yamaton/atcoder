let readInt() = stdin.ReadLine() |> int
let readIntArray() = stdin.ReadLine().Split(' ') |> Array.map int
let n = readInt()
let mutable t = 0
let mutable x = 0
let mutable y = 0

let format tf =
    if tf then "Yes"
    else "No"

let isReachable t x y t1 x1 y1 =
    let time = t1 - t
    let dist = abs (x1 - x) + abs (y1 - y)
    time >= dist && (time - dist) % 2 = 0

seq {
    for i in 1..n do
        let [| t1; x1; y1 |] = readIntArray()
        yield isReachable t x y t1 x1 y1
        t <- t1
        x <- x1
        y <- y1
}
|> Seq.forall id
|> format
|> printfn "%s"
