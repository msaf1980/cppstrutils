#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <string>

#include <strcmp.hpp>

TEST_CASE("prefix string", "[strutils::starts_with]") {
    REQUIRE(strutils::starts_with("testString", "test"));
    REQUIRE(!strutils::starts_with("testString", "testA"));

    REQUIRE(strutils::starts_with("test", "test"));
    REQUIRE(!strutils::starts_with("tes", "test"));

    REQUIRE(strutils::starts_with("test", ""));
    REQUIRE(strutils::starts_with("", ""));
    REQUIRE(!strutils::starts_with("", "test"));
}

TEST_CASE("prefix char", "[strutils::first_is]") {
    REQUIRE(strutils::first_is("testString", 't'));
    REQUIRE(!strutils::first_is("testString", 'T'));
    REQUIRE(!strutils::first_is("testString", 'a'));

    REQUIRE(!strutils::first_is("", 't'));
}

TEST_CASE("postfix string", "[strutils::ends_with]") {
    REQUIRE(strutils::ends_with("testString", "ng"));
    REQUIRE(!strutils::ends_with("testString", "test"));
    REQUIRE(!strutils::ends_with("testString", "hng"));

    REQUIRE(strutils::ends_with("test", "test"));
    REQUIRE(!strutils::ends_with("tes", "test"));

    REQUIRE(strutils::ends_with("test", ""));
    REQUIRE(strutils::ends_with("", ""));
    REQUIRE(!strutils::ends_with("", "test"));
}

TEST_CASE("postfix char", "[strutils::last_is]") {
    REQUIRE(strutils::last_is("testString", 'g'));
    REQUIRE(!strutils::last_is("testString", 'G'));
    REQUIRE(!strutils::last_is("testString", 'a'));

    REQUIRE(!strutils::last_is("", 't'));
}