// dependency header
#include "catch2/catch.hpp"

#include "libutil/date_time/leap_year.hpp"

using namespace date_time;

TEST_CASE("A year is a leap year", "[date_time][Leap year performance]") {
    SECTION("if it is divisble by 4 but not by 100") {
        BENCHMARK("2020") {
            return is_leap_year(2020);
        };

        BENCHMARK("4") {
            return is_leap_year(4);
        };
    }

    SECTION("if it is divisble by 400") {
        BENCHMARK("1600") {
            return is_leap_year(1600);
        };

        BENCHMARK("2000") {
            return is_leap_year(2000);
        };
    }
}

TEST_CASE("A year is not a leap year", "[date_time][Leap year specification]") {
    SECTION("if it is not divisble by 4") {
        BENCHMARK("2018") {
            return is_leap_year(2018);
        };

        BENCHMARK("1") {
            return is_leap_year(1);
        };
    }

    SECTION("if it is divisble by 100 but not by 400") {
        BENCHMARK("1700") {
            return is_leap_year(1700);
        };

        BENCHMARK("1900") {
            return is_leap_year(1900);
        };
    }
}
