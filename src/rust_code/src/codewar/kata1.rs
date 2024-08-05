use std::collections::VecDeque;

fn alphabet_position_my(text: &str) -> String {
    // Code here...
    let mut res: VecDeque<i32> = VecDeque::new();
    for c in text.bytes() {
        if b'a' <= c && c <= b'z' {
            res.push_back((c - b'a' + 1) as i32);
        } else if b'A' <= c && c <= b'Z' {
            res.push_back((c - b'A' + 1) as i32);
        }
    }
    if let Some(e) = res.pop_front() {
        let mut s: String = e.to_string();
        for e in res {
            s += &*format!(" {}", e);
        }
        s
    } else {
        "".into()
    }
}

fn alphabet_position(text: &str) -> String {
    text.chars()
        .filter(|c| c.is_alphabetic())
        .map(|c| (c.to_ascii_lowercase() as u32 - 96).to_string())
        .collect::<Vec<String>>()
        .join(" ")
}

#[test]
fn returns_expected() {
    assert_eq!(
        alphabet_position("The sunset sets at twelve o' clock."),
        "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11".to_string()
    );
    assert_eq!(
        alphabet_position("The narwhal bacons at midnight."),
        "20 8 5 14 1 18 23 8 1 12 2 1 3 15 14 19 1 20 13 9 4 14 9 7 8 20".to_string()
    );
}