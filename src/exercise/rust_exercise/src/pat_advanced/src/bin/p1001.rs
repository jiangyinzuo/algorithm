extern "C" {
    fn scanf(fmt: *const u8, ...) -> i32;
}

fn main() {
    unsafe {
        let mut a: i32 = 0;
        let mut b: i32 = 0;
        scanf("%d %d".as_ptr(), &a, &b);
        let is_pos = a + b >= 0;
        let mut c = (a + b).abs();
        let mut vec = Vec::new();
        let mut dot_count = 0;
        while c != 0 {
            vec.push((c % 10).to_string());
            c /= 10;
            if (vec.len() - dot_count) % 3 == 0 {
                vec.push(",".to_string());
                dot_count += 1;
            }
        }
        if !vec.is_empty() && vec.last().unwrap().eq(",") {
            vec.pop();
        }
        if !is_pos {
            print!("-");
        }
        vec.reverse();
        for ch in vec.iter() {
            print!("{}", ch);
        }
        if vec.is_empty() {
            print!("0");
        }
        println!();
    }
}
