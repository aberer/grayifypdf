#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "fillpoles.hxx"

#include <sstream>


TEST_CASE("fill poles works", "[fillpoles]")
{
    REQUIRE_THROWS_AS(fillGaps(2, 1, "A", "B", {3,4}, std::cout),
                      std::logic_error);

    REQUIRE_THROWS_AS(fillGaps(2, 2, "A", "B", {3}, std::cout),
                      std::logic_error);

    std::stringstream ss;

    fillGaps(1,1, "A", "B", {}, ss);
    REQUIRE(ss.str() == "A1");

    ss.str("");
    fillGaps(1,1, "A", "B", {1}, ss);
    REQUIRE(ss.str() == "B1");

    ss.str("");
    fillGaps(1,100, "A", "B", {50}, ss);
    REQUIRE(ss.str() == "A1-49,B50,A51-100");

    ss.str("");
    fillGaps(1,100, "A", "B", {1}, ss);
    REQUIRE(ss.str() == "B1,A2-100");

    ss.str("");
    fillGaps(1,100, "A", "B", {100}, ss);
    REQUIRE(ss.str() == "A1-99,B100");

    ss.str("");
    fillGaps(1,100, "A", "B", {50,52}, ss);
    REQUIRE(ss.str() == "A1-49,B50,A51,B52,A53-100");
}
