fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let t: i32 = s.trim().parse().unwrap();
    for _ in 0..t {
        std::io::stdin().read_line(&mut s).unwrap();
        s.clear();
        let mut map = std::collections::HashSet::new();
        std::io::stdin().read_line(&mut s).unwrap();

        let mut result = || {
            for i in s.split_whitespace() {
                if map.contains(i) {
                    return "YES";
                } else {
                    map.insert(i);
                }
            }
            "NO"
        };
        println!("{}", result());
    }
}
