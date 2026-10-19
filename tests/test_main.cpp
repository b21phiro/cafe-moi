#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/CafeMoi.h"

// Test to make sure that catch2 works. If this fails then we're doomed I guess.

TEST_CASE("Catch2 works", "[catch2]")
{
    REQUIRE(1 + 2 == 3);
};

// Game states

TEST_CASE("Game states and switching states", "[cafemoi]")
{

    CafeMoi cafemoi;

    SECTION("The default state is the main menu")
    {
        REQUIRE(cafemoi.get_current_state() == "MainMenu");
    }

    SECTION("Switching state from the main menu to in game works")
    {
        cafemoi.set_state("InGame");

        REQUIRE(cafemoi.get_current_state() == "InGame");
    }

}