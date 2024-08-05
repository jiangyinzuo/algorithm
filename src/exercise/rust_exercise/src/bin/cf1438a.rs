fn main() {
    let mut s: String = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let t = s.trim().parse::<i32>().unwrap();
    for i in 0..t {
        s.clear();
        std::io::stdin().read_line(&mut s).unwrap();
        let n: i32 = s.trim().parse().unwrap();
        for _ in 0..n - 1 {
            print!("1 ");
        }
        println!("1");
    }
}
