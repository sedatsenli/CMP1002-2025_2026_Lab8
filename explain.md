# More Details about Classes

## 1. Concept Overview

This lab explores four advanced class features in C++ that go beyond basic constructor/getter patterns. These features are essential for writing correct, efficient, and well-encapsulated code in real-world projects.

- **const member functions** — prevent unintended mutation and allow use with const objects
- **Member initializer lists** — the correct way to initialize members, especially composed objects
- **friend functions/classes** — controlled access to private data from outside the class
- **Composition** — building complex types from simpler ones by embedding objects as members

---

## 2. Key Concepts

- A `const` method cannot modify any member variable of the class
- A `const` object can **only** call `const` methods — the compiler enforces this
- Member initializer lists run **before** the constructor body executes
- When a class member has no default constructor, initializer lists are **required**, not optional
- A `friend` declaration gives a specific external function or class access to `private` members
- `friend` is declared **inside** the class that is granting access
- Composition means an object of one class is a **member** of another class
- Composition expresses a "has-a" relationship (Rectangle **has-a** Point)

---

## 3. Important Keywords

| Keyword / Concept | Explanation |
|---|---|
| `const` (on method) | Appended after `()` — means the method won't modify the object |
| `const` (on object) | A variable declared `const MyClass obj` — only const methods may be called |
| Member initializer list | Syntax `: member(value)` between `:` and `{` in a constructor |
| `friend` function | Non-member function allowed to access private data of a class |
| `friend` class | All methods of the named class can access private data |
| Composition | A class holds another class as a data member |
| `std::abs()` | Returns absolute value — needed for width/height with arbitrary coordinates |

---

## 4. Common Mistakes

1. **Forgetting `const` on getters** — the method compiles fine on regular objects, but calling it on a `const` object causes a compile error.

2. **Using `=` assignment in constructor body for composed objects** — if `Point` has no default constructor, writing `topLeft = Point(x,y)` in the body fails. You must use an initializer list.

3. **Declaring `friend` outside the class** — `friend` must appear *inside* the class body that is granting access.

4. **Thinking `friend` is mutual** — if `A` declares `B` as a friend, `B` can see `A`'s private members, but `A` cannot see `B`'s private members.

5. **Returning negative width/height** — when coordinates are given in reversed order (e.g., `x2 < x1`), use `std::abs()` to get a positive dimension.

6. **Calling a non-const method on a const object** — `doubleValue()` mutates the object, so it cannot be called on a `const ConstDemo`.

---

## 5. Mini Examples

### const method and const object

```cpp
class Counter {
    int count;
public:
    Counter(int c) : count(c) {}

    int getCount() const { return count; }   // const method
    void increment() { count++; }            // non-const method
};

const Counter c(5);
c.getCount();    // OK
c.increment();   // COMPILE ERROR — non-const method on const object
```

---

### Member initializer list — required for composition

```cpp
class Engine {
    int hp;
public:
    Engine(int h) : hp(h) {}   // no default constructor
    int getHP() const { return hp; }
};

class Car {
    Engine engine;   // composed member
public:
    // MUST use initializer list — Engine has no Engine() constructor
    Car(int hp) : engine(hp) {}
};
```

---

### friend function

```cpp
class Wallet {
    double balance;
public:
    Wallet(double b) : balance(b) {}
    friend double getBalance(const Wallet& w);
};

double getBalance(const Wallet& w) {
    return w.balance;   // allowed because of friend declaration
}
```

---

### friend class

```cpp
class Safe {
    int code;
public:
    Safe(int c) : code(c) {}
    friend class Locksmith;
};

class Locksmith {
public:
    void reveal(const Safe& s) {
        std::cout << s.code;   // OK — Locksmith is a friend of Safe
    }
};
```

---

## 6. When to Use This

| Feature | When to use |
|---|---|
| `const` methods | Any getter or method that only reads state — makes your class safe to use with const references and const objects |
| Member initializer list | Always — but **required** when composing objects that have no default constructor |
| `friend` function | When an operator or utility function needs access to internals without being a method (e.g., `operator<<`, comparison helpers) |
| `friend` class | When two classes are tightly coupled and one needs full access (e.g., iterator + container) |
| Composition | When one class logically "contains" another — prefer over inheritance for "has-a" relationships |
