#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/CafeMoi.h"
#include "../src/Logging.h"

// Test to make sure that catch2 works. If this fails then we're doomed I guess.

TEST_CASE("Catch2 works", "[catch2]")
{
    REQUIRE(1 + 2 == 3);
};

// Game states

TEST_CASE("Game states and switching states", "[cafemoi]")
{

    CafeMoi cafemoi;
    cafemoi.get_logging().set_logging_level("off");

    SECTION("The default state is the main menu")
    {
        REQUIRE(cafemoi.get_current_state() == "MainMenu");
    }

    SECTION("Switching state from the main menu to in game works")
    {
        cafemoi.set_state("InGame");

        REQUIRE(cafemoi.get_current_state() == "InGame");
    }

    SECTION("Won't switch state if unknown state is given")
    {
        cafemoi.set_state("MainMenu");
        REQUIRE(cafemoi.get_current_state() == "MainMenu");

        cafemoi.set_state("THIS IS NOT A STATE");

        REQUIRE(cafemoi.get_current_state() == "MainMenu");
    }

}

// Logging

TEST_CASE("Logging utility class", "[logging]")
{
    Logging logging;

    SECTION("Can change logging levels")
    {
        logging.set_logging_level("off");

        REQUIRE(logging.get_logging_level() == "off");
    }

    SECTION("Can not set to an unknown logging level")
    {
        logging.set_logging_level("THIS IS NOT A LOGGING LEVEL");

        REQUIRE(logging.get_logging_level() != "THIS IS NOT A LOGGING LEVEL");
    }

}