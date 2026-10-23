#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>

// Test to make sure that catch2 works. If this fails then we're doomed I guess.

TEST_CASE("Catch2 works", "[catch2]")
{
    REQUIRE(1 + 2 == 3);
};