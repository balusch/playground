# playground

A personal multi-language playground. Each language is self-contained and managed independently.

## Structure

- `cpp/` - C++ playground (CMake)
- `rust/` - Rust playground (Cargo workspace)
- `go/` - Go playground (Go modules)

## C++

```sh
cmake --preset debug -S cpp
cmake --build --preset debug
```

## Rust

```sh
cd rust
cargo run -p hello
```

## Go

```sh
cd go
go run ./cmd/hello
```
