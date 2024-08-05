use std::collections::BinaryHeap;

fn value(len: i64, pieces: i64) -> i64 {
    let unit = len / pieces;
    let extra = len - unit * pieces;
    (pieces - extra) * unit * unit + extra * (unit + 1) * (unit + 1)
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut s = s.split_whitespace();
    s.next().unwrap();
    let k = s.next().unwrap().parse::<usize>().unwrap();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let sum1 = s
        .split_whitespace()
        .map(|s| {
            let len = s.parse::<i64>().unwrap();
            (-value(len, 2) + len * len, len, 2)
        })
        .collect::<Vec<(i64, i64, i64)>>();

    let mut queue = BinaryHeap::from(sum1);

    for _ in 0..k - queue.len() {
        let v = queue.pop().unwrap();
        queue.push((-value(v.1, v.2 + 1) + value(v.1, v.2), v.1, v.2 + 1));
    }
    let res = queue.iter().map(|v| value(v.1, v.2 - 1)).sum::<i64>();
    println!("{}", res);
}
