#include <arrayd/arrayd.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>


TEST_CASE("[arrayd] - constructors and size") {
    ArrayD a(5);
    CHECK(a.Size() == 5);
    for (ptrdiff_t i = 0; i < a.Size(); i++) {
        CHECK(a[i] == 0.0);
    }

    ArrayD b;
    CHECK(b.Size() == 0);
}

TEST_CASE("[arrayd] - element access and assignment") {
    ArrayD a(2);
    a[0] = 1.00;
    a[1] = 2.00;

    CHECK(a[0] == 1.00);
    CHECK(a[1] == 2.00);

    const ArrayD b(a);
    CHECK(b[0] == 1.00);
    CHECK(b[1] == 2.00);
}

TEST_CASE("[arrayd] - resize") {
    ArrayD a(3);
    a[0] = 1.0;
    a[1] = 2.0;
    a[2] = 3.0;

    a.Resize(5);
    CHECK(a.Size() == 5);
    CHECK(a[0] == 1.0);
    CHECK(a[1] == 2.0);
    CHECK(a[2] == 3.0);
    CHECK(a[3] == 0.0);
    CHECK(a[4] == 0.0);

    a.Resize(2);
    CHECK(a.Size() == 2);
    CHECK(a[0] == 1.0);
    CHECK(a[1] == 2.0);
}

TEST_CASE("[arrayd] - insert") {
    ArrayD a(3);
    a[0] = 1.0;
    a[1] = 2.0;
    a[2] = 4.0;

    a.Insert(2, 3.0);
    CHECK(a.Size() == 4);
    CHECK(a[0] == 1.0);
    CHECK(a[1] == 2.0);
    CHECK(a[2] == 3.0);
    CHECK(a[3] == 4.0);

    a.Insert(0, 0.0);
    CHECK(a.Size() == 5);
    CHECK(a[0] == 0.0);
    CHECK(a[1] == 1.0);
    CHECK(a[2] == 2.0);
    CHECK(a[3] == 3.0);
    CHECK(a[4] == 4.0);

    a.Insert(5, 5.0);
    CHECK(a.Size() == 6);
    CHECK(a[5] == 5.0);
}

TEST_CASE("[arrayd] - remove") {
    ArrayD a(5);
    for (ptrdiff_t i = 0; i < a.Size(); ++i) {
        a[i] = i + 1;
    }

    a.Remove(2);
    CHECK(a.Size() == 4);
    CHECK(a[0] == 1.0);
    CHECK(a[1] == 2.0);
    CHECK(a[2] == 4.0);
    CHECK(a[3] == 5.0);

    a.Remove(0);
    CHECK(a.Size() == 3);
    CHECK(a[0] == 2.0);
    CHECK(a[1] == 4.0);
    CHECK(a[2] == 5.0);

    a.Remove(2);
    CHECK(a.Size() == 2);
    CHECK(a[0] == 2.0);
    CHECK(a[1] == 4.0);
}

TEST_CASE("[arrayd] - copy constructor and assignment") {
    ArrayD a(4);
    a[0] = 100.73;
    a[1] = 20.5;
    a[2] = 67.3;
    a[3] = 5.0;

    ArrayD b = a;
    CHECK(b.Size() == 4);
    CHECK(b[0] == 100.73);
    CHECK(b[1] == 20.5);
    CHECK(b[2] == 67.3);
    CHECK(b[3] == 5.0);

    ArrayD c;
    c = a;
    CHECK(c.Size() == 4);
    CHECK(c[0] == 100.73);
    CHECK(c[1] == 20.5);
    CHECK(c[2] == 67.3);
    CHECK(c[3] == 5.0);
}

TEST_CASE("[arrayd] - edge cases") {
    ArrayD a;
    CHECK(a.Size() == 0);

    CHECK_THROWS_AS(a[0], std::exception);

    ArrayD b(0);
    CHECK(b.Size() == 0);

    ArrayD c(10);
    CHECK_NOTHROW(c[9] = 1.0);
    CHECK_THROWS_AS(c[10] = 2.0, std::exception);
}
