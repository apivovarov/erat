# Sieve of Eratosthenes in cpp, java, python, go, node.js, rust, c

# Results
Results for Array size 100,000,000

| Language | Result sec |
| -------- | ----------:|
| cpp      |      0.433 |
| java     |      0.684 |
| python   |     56.160 |
| pypy     |     12.025 |
| go       |      0.749 |
| node.js  |      5.602 |
| rust     |      0.665 |
| c        |      0.702 |


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
| c        |       64.6 |


# Build and Run

## C++

```
g++ -O3 -march=native erat.cpp
./a.out <N>
```

## Java

```
javac Erat.java
java -client Erat <N>
```

## Go

```
go clean
go build erat.go
./erat <N>
```

## Rust

```
cargo build --release
cargo run --release <N>
```

## C

```
gcc -O3 erat.c
./a.out <N>
```
