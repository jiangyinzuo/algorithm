extern "C" {
    fn scanf(fmt: *const u8, ...) -> i32;
}

const N: usize = 10000;
struct TreeLikeArray {
    sum1: [i32; N],
}

impl TreeLikeArray {
    fn low_bit(x: i32) -> i32 {
        x & -x
    }

    fn new() -> TreeLikeArray {
        TreeLikeArray { sum1: [0; N] }
    }

    fn init(&mut self, start: &[i32; N], n: usize) {
        for i in 1..n {
            self.sum1[i] += start[i];
            let father: i32 = i as i32 + Self::low_bit(i as i32);
            if father as usize <= n {
                self.sum1[get_father as usize] += start[i];
            }
        }
    }
}

fn main() {
    unsafe {
        let heap = std::collections::BinaryHeap::new();
        let t = 0;
        scanf("%d".as_ptr(), &t);
        for _ in 0..t {
            let s = [0u8; 15];
            scanf("%s".as_ptr(), &s);
            if s[1] == b'o' {
                if heap.is_empty() {
                    println!("Invalid");
                } else {
                    let num = heap.pop().unwrap();
                    println!("{}", num);
                }
            } else if s[1] == b'u' {
                let n;
                scanf("%s".as_ptr(), &n);
                heap.p
            }
        }
    }
}
