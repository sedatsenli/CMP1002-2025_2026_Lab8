// ============================================================
// test.cpp — Combined Test File
// Lab: More Details about Classes
// ============================================================
// Groups:
//   [point]     Group A — 4 tests  — 15 pts
//   [rectangle] Group B — 7 tests  — 30 pts
//   [friend]    Group C — 5 tests  — 20 pts
//   [constdemo] Group D — 8 tests  — 35 pts
//
// Run all:             ./test
// Run one group only:  ./test [point]
//                      ./test [rectangle]
//                      ./test [friend]
//                      ./test [constdemo]
// ============================================================

#include "catch_amalgamated.hpp"

#define main student_main
#include "MainProgram.cpp"
#undef main

// ============================================================
// GROUP A — Point Class (15 points)
// ============================================================

TEST_CASE("A1 - getX and getY return correct values", "[point]") {
    Point p(3.0, 4.0);
    CHECK(p.getX() == 3.0);
    CHECK(p.getY() == 4.0);
}

TEST_CASE("A2 - Negative coordinates", "[point]") {
    Point p(-5.0, -2.5);
    CHECK(p.getX() == -5.0);
    CHECK(p.getY() == -2.5);
}

TEST_CASE("A3 - Origin point (0, 0)", "[point]") {
    Point p(0.0, 0.0);
    CHECK(p.getX() == 0.0);
    CHECK(p.getY() == 0.0);
}

TEST_CASE("A4 - getX and getY callable on const Point object", "[point]") {
    // FAILS TO COMPILE if getX/getY are not marked const
    const Point p(7.0, 8.0);
    CHECK(p.getX() == 7.0);
    CHECK(p.getY() == 8.0);
}

// ============================================================
// GROUP B — Rectangle (30 points)
// ============================================================

TEST_CASE("B1 - getWidth returns correct width", "[rectangle]") {
    Rectangle r(0, 0, 4, 3);
    CHECK(r.getWidth() == Catch::Approx(4.0));
}

TEST_CASE("B2 - getHeight returns correct height", "[rectangle]") {
    Rectangle r(0, 0, 4, 3);
    CHECK(r.getHeight() == Catch::Approx(3.0));
}

TEST_CASE("B3 - getArea returns correct area", "[rectangle]") {
    Rectangle r(0, 0, 4, 3);
    CHECK(r.getArea() == Catch::Approx(12.0));
}

TEST_CASE("B4 - Non-zero origin rectangle", "[rectangle]") {
    Rectangle r(1, 1, 4, 4);
    CHECK(r.getWidth()  == Catch::Approx(3.0));
    CHECK(r.getHeight() == Catch::Approx(3.0));
    CHECK(r.getArea()   == Catch::Approx(9.0));
}

TEST_CASE("B5 - Reversed coordinates still give positive dimensions", "[rectangle]") {
    Rectangle r(4, 3, 0, 0);
    CHECK(r.getWidth()  == Catch::Approx(4.0));
    CHECK(r.getHeight() == Catch::Approx(3.0));
    CHECK(r.getArea()   == Catch::Approx(12.0));
}

TEST_CASE("B6 - Degenerate rectangle with zero width", "[rectangle]") {
    Rectangle r(2, 0, 2, 5);
    CHECK(r.getWidth()  == Catch::Approx(0.0));
    CHECK(r.getHeight() == Catch::Approx(5.0));
    CHECK(r.getArea()   == Catch::Approx(0.0));
}

TEST_CASE("B7 - All dimension methods callable on const Rectangle", "[rectangle]") {
    // FAILS TO COMPILE if getWidth/getHeight/getArea are not marked const
    const Rectangle r(0, 0, 6, 2);
    CHECK(r.getWidth()  == Catch::Approx(6.0));
    CHECK(r.getHeight() == Catch::Approx(2.0));
    CHECK(r.getArea()   == Catch::Approx(12.0));
}

// ============================================================
// GROUP C — Friend Function isSameSize (20 points)
// ============================================================

TEST_CASE("C1 - isSameSize returns false for different areas", "[friend]") {
    Rectangle r1(0, 0, 4, 3);
    Rectangle r2(1, 1, 4, 4);
    CHECK(isSameSize(r1, r2) == false);
}

TEST_CASE("C2 - isSameSize returns true for equal areas", "[friend]") {
    Rectangle r1(0, 0, 4, 3);
    Rectangle r2(0, 0, 6, 2);
    CHECK(isSameSize(r1, r2) == true);
}

TEST_CASE("C3 - isSameSize with identical rectangles", "[friend]") {
    Rectangle r1(0, 0, 5, 5);
    Rectangle r2(0, 0, 5, 5);
    CHECK(isSameSize(r1, r2) == true);
}

TEST_CASE("C4 - isSameSize with two zero-area rectangles", "[friend]") {
    Rectangle r1(0, 0, 0, 5);
    Rectangle r2(0, 0, 3, 0);
    CHECK(isSameSize(r1, r2) == true);
}

TEST_CASE("C5 - isSameSize result is symmetric", "[friend]") {
    Rectangle r1(0, 0, 3, 4);
    Rectangle r2(0, 0, 2, 6);
    CHECK(isSameSize(r1, r2) == isSameSize(r2, r1));
}

// ============================================================
// GROUP D — ConstDemo / const correctness (35 points)
// ============================================================

TEST_CASE("D1 - getValue returns the initial value", "[constdemo]") {
    ConstDemo cd(7);
    CHECK(cd.getValue() == 7);
}

TEST_CASE("D2 - doubleValue multiplies value by 2", "[constdemo]") {
    ConstDemo cd(5);
    cd.doubleValue();
    CHECK(cd.getValue() == 10);
}

TEST_CASE("D3 - doubleValue called twice gives value * 4", "[constdemo]") {
    ConstDemo cd(3);
    cd.doubleValue();
    cd.doubleValue();
    CHECK(cd.getValue() == 12);
}

TEST_CASE("D4 - constGetDouble returns value*2 and does NOT mutate", "[constdemo]") {
    ConstDemo cd(6);
    int result = cd.constGetDouble();
    CHECK(result == 12);
    CHECK(cd.getValue() == 6);
}

TEST_CASE("D5 - getValue callable on const ConstDemo object", "[constdemo]") {
    // FAILS TO COMPILE if getValue is not marked const
    const ConstDemo cd(9);
    CHECK(cd.getValue() == 9);
}

TEST_CASE("D6 - constGetDouble callable on const ConstDemo object", "[constdemo]") {
    // FAILS TO COMPILE if constGetDouble is not marked const
    const ConstDemo cd(4);
    CHECK(cd.constGetDouble() == 8);
}

TEST_CASE("D7 - ConstDemo with value 0", "[constdemo]") {
    ConstDemo cd(0);
    CHECK(cd.getValue() == 0);
    cd.doubleValue();
    CHECK(cd.getValue() == 0);
    CHECK(cd.constGetDouble() == 0);
}

TEST_CASE("D8 - ConstDemo with negative initial value", "[constdemo]") {
    ConstDemo cd(-3);
    CHECK(cd.getValue() == -3);
    CHECK(cd.constGetDouble() == -6);
    cd.doubleValue();
    CHECK(cd.getValue() == -6);
}
