// dependency header
#include "catch2/catch.hpp"

#include "libutil/date_time/leap_year.hpp"

using namespace date_time;

TEST_CASE("A year is a leap year", "[date_time][Leap year specification]") {
    SECTION("if it is divisble by 4 but not by 100") {
        CHECK(is_leap_year(2020));
        CHECK(is_leap_year(2024));
        CHECK(is_leap_year(2028));
        CHECK(is_leap_year(2032));
        CHECK(is_leap_year(4));
        CHECK(is_leap_year(8));
    }

    SECTION("if it is divisble by 400") {
        CHECK(is_leap_year(1600));
        CHECK(is_leap_year(2000));
    }
}

TEST_CASE("A year is not a leap year", "[date_time][Leap year specification]") {
    SECTION("if it is not divisble by 4") {
        CHECK_FALSE(is_leap_year(2018));
        CHECK_FALSE(is_leap_year(2017));
        CHECK_FALSE(is_leap_year(42));
        CHECK_FALSE(is_leap_year(1));
    }

    SECTION("if it is divisble by 100 but not by 400") {
        CHECK_FALSE(is_leap_year(1700));
        CHECK_FALSE(is_leap_year(1800));
        CHECK_FALSE(is_leap_year(1900));
    }
}
