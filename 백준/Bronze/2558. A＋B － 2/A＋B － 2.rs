use std::io::{self, BufRead};

fn main() {
    let mut lines = io::stdin().lock().lines();

    let a: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap();
    let b: i32 = lines.next().unwrap().unwrap().trim().parse().unwrap();
    println!("{}", a + b);
}