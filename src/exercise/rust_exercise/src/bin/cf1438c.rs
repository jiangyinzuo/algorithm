fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let t = s.trim().parse::<i32>().unwrap();
    for _ in 0..t {
        s.clear();
        std::io::stdin().read_line(&mut s).unwrap();
        let mut nums = s.split_whitespace();
        let row: u32 = nums.next().unwrap().parse().unwrap();
        let col: u32 = nums.next().unwrap().parse().unwrap();
        for i in 0..row {
            s.clear();
            std::io::stdin().read_line(&mut s).unwrap();
            for (j, n) in s.split_whitespace().enumerate() {
                let mut value = n.parse::<u32>().unwrap();
                if ((j as u32 ^ i ^ value) & 1u32) == 1 {
                    value += 1;
                }
                print!("{} ", value);
            }
            println!();
        }
    }
}
