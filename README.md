# mathlib

A small, deliberately simple C++ math library used for training purposes
(practicing git workflows, PRs, and CI). It's not meant to be robust or
complete — poke at it, break it, fix it.

## Building and running tests

```sh
cmake -S . -B build
cmake --build build -j
ctest --test-dir build --output-on-failure
```

## Training exercises

A few functions are left unimplemented on purpose, and throw
`std::logic_error` if you call them:

* `mathlib::isPrime` — implement a primality check.
* `mathlib::gcd` — implement Euclid's algorithm (should return a
  non-negative result even for negative inputs).
* `mathlib::power` — works for non-negative exponents already; extend it to
  handle negative exponents too (e.g. `power(2.0, -2) == 0.25`).

Each has a matching test in `tests/` that's currently named with a
`DISABLED_` prefix and already has the expected assertions written in.
Implement the function, remove the `DISABLED_` prefix from its test, and
confirm it passes.
