use std::env;
use std::time::Instant;

fn main() {
  let max: usize;
  if let Some(arg1) = env::args().nth(1) {
    match arg1.parse::<usize>() {
      Ok(v) => max = v,
      Err(_) => max = 0,
    }
  } else {
    max = 0;
  }
  println!("Max: {:?}", max);

  let now = Instant::now();

  let mut sieve = vec![true; max];
  sieve[0] = false;
  sieve[1] = false;

  let lim = (max as f64).sqrt() as usize;

  for n in 2..lim {
    if sieve[n] {
    let mut j = 2 * n;
    let mut j_go = true;
      while j_go {
        sieve[j] = false;
        j = j + n;
        if j >= max {
          j_go = false;
        }
      }
    }
  }

  let t2 = now.elapsed();
  let tt = (t2.as_secs() as f64) + (t2.subsec_nanos() as f64) / 1000000000.0;
  println!("Duration: {} sec", tt);

  //println!("sieve: {:?}", sieve);
}
