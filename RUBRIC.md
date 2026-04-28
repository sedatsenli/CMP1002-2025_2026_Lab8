# Grading Rubric — More Details about Classes

**Total: 100 points**  
Run `make test` and use the test output to assign points per group.

---

## Group A — Point Class (15 points)

| Test | Description | Points |
|---|---|---|
| A1 | getX() and getY() return correct values | 4 |
| A2 | Negative coordinates handled correctly | 3 |
| A3 | Origin coordinates (0,0) | 3 |
| A4 | getX/getY callable on a const Point object | 5 |

**Key const requirement:** A4 verifies that getX() and getY() are declared `const`. If a student forgets `const`, A4 will not compile/pass even if A1–A3 pass.

---

## Group B — Rectangle Dimensions and Area (30 points)

| Test | Description | Points |
|---|---|---|
| B1 | getWidth() correct for standard input | 4 |
| B2 | getHeight() correct for standard input | 4 |
| B3 | getArea() correct for standard input | 4 |
| B4 | All three methods with non-zero origin | 5 |
| B5 | Reversed coordinates — abs() used | 5 |
| B6 | Degenerate rectangle (zero width) | 4 |
| B7 | All methods callable on const Rectangle | 4 |

**Key composition requirement:** Rectangle has no default Point constructor, so a member initializer list is **required**. If absent, the class will not compile and all B tests will fail.

---

## Group C — friend function isSameSize (20 points)

| Test | Description | Points |
|---|---|---|
| C1 | Returns false for different areas | 4 |
| C2 | Returns true for equal areas (different dimensions) | 4 |
| C3 | Returns true for identical rectangles | 4 |
| C4 | Both rectangles have zero area | 4 |
| C5 | Result is symmetric (r1,r2) == (r2,r1) | 4 |

**Key requirement:** `isSameSize` must be a non-member function declared `friend` inside Rectangle.

---

## Group D — ConstDemo: const correctness (35 points)

| Test | Description | Points |
|---|---|---|
| D1 | getValue() returns correct initial value | 4 |
| D2 | doubleValue() mutates the object | 4 |
| D3 | doubleValue() called twice produces correct result | 4 |
| D4 | constGetDouble() returns value*2 without mutating | 5 |
| D5 | getValue() callable on a const ConstDemo object | 5 |
| D6 | constGetDouble() callable on a const object | 5 |
| D7 | Handles value = 0 correctly | 4 |
| D8 | Handles negative initial values | 4 |

**Key const correctness requirement:** D5 and D6 test that `getValue()` and `constGetDouble()` are declared `const`. D4 verifies that `constGetDouble()` does **not** modify the object (the value must remain unchanged after calling it).

---

## Deduction Guidelines

| Issue | Deduction |
|---|---|
| Code does not compile at all | –50 (partial credit for sections that compile) |
| Member initializer list not used (but workaround works) | –5 |
| `friend` declaration missing but logic works via public access | –5 |
| No `#include <cmath>` but abs() logic works another way | –2 |
| main() crashes or throws during tests | –5 per group affected |
