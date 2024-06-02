#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

namespace raylib
{
#include <raylib.h>
#include "setka.h"
#include "setka.cpp"
#include "colors.cpp"
}

TEST_CASE("Testing ProverkaNaVilet outside")
{
    raylib::Setka setka;
    CHECK(setka.ProverkaNaVilet(-1, 0) == true);
    CHECK(setka.ProverkaNaVilet(0, -1) == true);
    CHECK(setka.ProverkaNaVilet(20, 0) == true);
    CHECK(setka.ProverkaNaVilet(0, 10) == true);
    CHECK(setka.ProverkaNaVilet(20, 10) == true);
}

TEST_CASE("Testing ProverkaNaVilet inside")
{
    raylib::Setka setka;
    CHECK(setka.ProverkaNaVilet(0, 0) == false);
    CHECK(setka.ProverkaNaVilet(10, 5) == false);
    CHECK(setka.ProverkaNaVilet(19, 9) == false);
}

TEST_CASE("Testing ProverkaNaPystoty with empty cells")
{
    raylib::Setka setka;
    setka.setka[0][0] = 0;
    setka.setka[1][1] = 0;
    setka.setka[2][2] = 0;

    CHECK(setka.ProverkaNaPystoty(0, 0) == true);
    CHECK(setka.ProverkaNaPystoty(1, 1) == true);
    CHECK(setka.ProverkaNaPystoty(2, 2) == true);
}

TEST_CASE("Testing ProverkaNaPystoty with non-empty cells")
{

    raylib::Setka setka;
    setka.setka[0][1] = 1;
    setka.setka[1][2] = 2;
    setka.setka[2][3] = 3;

    CHECK(setka.ProverkaNaPystoty(0, 1) == false);
    CHECK(setka.ProverkaNaPystoty(1, 2) == false);
    CHECK(setka.ProverkaNaPystoty(2, 3) == false);
}

TEST_CASE("Testing ProverkaNaPolnoty method")
{
    raylib::Setka setka;

    CHECK(setka.ProverkaNaPolnoty(0) == false);

    for (int j = 0; j < 10; ++j)
    {
        setka.setka[1][j] = 1;
    }

    CHECK(setka.ProverkaNaPolnoty(1) == true);

    setka.setka[2][0] = 1;
    setka.setka[2][1] = 1;
    setka.setka[2][2] = 1;
    CHECK(setka.ProverkaNaPolnoty(2) == false);
}
