#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <strutils.hpp>

#include <string>

TEST_CASE("split", "[strutils::split]") {
    SECTION("A,B,C") {
        const std::string str = "A,B,C";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 3);
        REQUIRE(tokens[0] == "A");
        REQUIRE(tokens[1] == "B");
        REQUIRE(tokens[2] == "C");
    }       
    SECTION(",B,C") {
        const std::string str = ",B,C";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 3);
        REQUIRE(tokens[0] == "");
        REQUIRE(tokens[1] == "B");
        REQUIRE(tokens[2] == "C");
    }
    SECTION("A,B,") {
        const std::string str = "A,B,";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 3);
        REQUIRE(tokens[0] == "A");
        REQUIRE(tokens[1] == "B");
        REQUIRE(tokens[2] == "");
    }
    SECTION("") {
        const std::string str = "";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 1);
        REQUIRE(tokens[0] == "");
    }
    SECTION("A") {
        const std::string str =  "A";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 1);
        REQUIRE(tokens[0] == "A");
    }
    SECTION(",") {
        const std::string str =  ",";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 2);
        REQUIRE(tokens[0] == "");
        REQUIRE(tokens[1] == "");
    }
    SECTION(",,") {
        const std::string str =  ",,";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 3);
        REQUIRE(tokens[0] == "");
        REQUIRE(tokens[1] == "");
        REQUIRE(tokens[2] == "");
    }
    SECTION("A,") {
        const std::string str = "A,";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 2);
        REQUIRE(tokens[0] == "A");
        REQUIRE(tokens[1] == "");
    }
    SECTION(",B") {
        const std::string str = ",B";
        auto tokens = strutils::split(str, ',');
        REQUIRE(tokens.size() == 2);
        REQUIRE(tokens[0] == "");
        REQUIRE(tokens[1] == "B");
    }
}
