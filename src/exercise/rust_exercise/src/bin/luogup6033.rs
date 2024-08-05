use std::collections::{LinkedList, VecDeque};

static mut ARR: [i32; 100001] = [0; 100001];

trait Queue<T> {
    fn pop_front(&mut self) -> Option<T>;
    fn push_back(&mut self, elt: T);
    fn is_empty(&self) -> bool;
    fn front(&self) -> Option<&T>;
}

impl<T> Queue<T> for VecDeque<T> {
    #[inline(always)]
    fn pop_front(&mut self) -> Option<T> {
        Self::pop_front(self)
    }

    #[inline(always)]
    fn push_back(&mut self, elt: T) {
        Self::push_back(self, elt);
    }

    #[inline(always)]
    fn is_empty(&self) -> bool {
        Self::is_empty(self)
    }

    #[inline(always)]
    fn front(&self) -> Option<&T> {
        Self::front(self)
    }
}

impl<T> Queue<T> for LinkedList<T> {
    #[inline(always)]
    fn pop_front(&mut self) -> Option<T> {
        Self::pop_front(self)
    }

    #[inline(always)]
    fn push_back(&mut self, elt: T) {
        Self::push_back(self, elt);
    }

    #[inline(always)]
    fn is_empty(&self) -> bool {
        Self::is_empty(self)
    }

    #[inline(always)]
    fn front(&self) -> Option<&T> {
        Self::front(self)
    }
}

fn take<T: PartialOrd, Q: Queue<T>>(q1: &mut Q, q2: &mut Q) -> T {
    if q2.is_empty() {
        q1.pop_front().unwrap()
    } else if q1.is_empty() || q1.front().unwrap() > q2.front().unwrap() {
        q2.pop_front().unwrap()
    } else {
        q1.pop_front().unwrap()
    }
}

fn main() {
    let mut s: String = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let n: usize = s.trim().parse::<usize>().unwrap();

    s.clear();
    std::io::stdin().read_line(&mut s).unwrap();
    unsafe {
        for c in s.split_whitespace().into_iter() {
            ARR[c.parse::<usize>().unwrap()] += 1;
        }
    }

    let mut q1 = VecDeque::<usize>::new();
    let mut q2 = VecDeque::<usize>::new();
    for i in 1..100001 {
        unsafe {
            for _ in 0..ARR[i] {
                q1.push_back(i);
            }
        }
    }
    let mut ans = 0usize;
    for _ in 1..n {
        let e1 = take::<usize, VecDeque<usize>>(&mut q1, &mut q2);
        let e2 = take::<usize, VecDeque<usize>>(&mut q1, &mut q2);
        ans += e1 + e2;
        q2.push_back(e1 + e2);
    }
    println!("{}", ans);
}
