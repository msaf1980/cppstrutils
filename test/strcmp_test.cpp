#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <string>

#include <strcmp.hpp>

TEST_CASE("starts_with", "[strutils::starts_with]") {
    REQUIRE(strutils::starts_with("testString", "test"));
    REQUIRE(!strutils::starts_with("testString", "testA"));

    REQUIRE(strutils::starts_with("test", "test"));
    REQUIRE(!strutils::starts_with("tes", "test"));

    REQUIRE(strutils::starts_with("test", ""));
    REQUIRE(strutils::starts_with("", ""));
    REQUIRE(!strutils::starts_with("", "test"));
}
