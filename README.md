# Sieve of Eratosthenes in cpp, java, python, go, node.js

# Results
Results for Array size 100,000,000

| Language | Result sec |
| -------- | ----------:|
| cpp      |      0.457 |
| java     |      0.722 |
| python   |     56.160 |
| pypy     |     12.025 |
| go       |      0.749 |
| node.js  |      5.602 |
| rust     |      0.665 |


Results for Array size 4,000,000,000

| Language | Result sec |
| -------- | ----------:|
| cpp      |       39.8 |
| java     |          - |
| python   |          - |
| pypy     |          - |
| go       |       65.4 |
| node.js  |          - |
| rust     |       66.7 |


# Build and Run

## Rust

```
cargo build --release
cargo run --release N
```
