use std::io::{self, BufRead};

fn main() {
    let mut lines = io::stdin().lock().lines();
    let test_size: usize = lines.next().unwrap().unwrap().parse().unwrap();
    for _ in 0..test_size {
        let line = lines.next().unwrap().unwrap();
        let parts: Vec<&str> = line.split_whitespace().collect();
        let mut num: f64 = parts[0].parse().unwrap();

        for idx in 1..parts.len(){
            let sig: &str = parts[idx];
            if sig == "@"{
                num*=3.0;
            } else if sig=="%" {
                num+=5.0;
            } else if sig=="#" {
                num-=7.0;
            }
        }
        println!("{:.2}",num);
    }


}