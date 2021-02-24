// dependency header
#include "catch2/catch.hpp"

#include "libutil/core/stack.hpp"

using namespace core;

TEST_CASE("A new stack", "[core][Stack specification]") {
    SECTION("is empty") {
        Stack<std::string> stack{};
        REQUIRE(stack.depth() == 0);
    }
}

TEST_CASE("An empty stack", "[core][Stack specification]") {
    SECTION("acquires depth by retaining a pushed item as its top") {
        Stack<std::string> stack{};
        stack.push("test");

        REQUIRE(stack.depth() == 1);
        REQUIRE(stack.top() == "test");
    }
}

TEST_CASE("A non-empty stack", "[core][Stack specification]") {
    SECTION("becomes deeper by retaining a pushed item as its top") {
        Stack<std::string> stack{};
        stack.push("test");
        REQUIRE(stack.depth() == 1);

        stack.push("test");
        REQUIRE(stack.depth() == 2);

        stack.push("test");
        REQUIRE(stack.depth() == 3);

        stack.push("test");
        REQUIRE(stack.depth() == 4);
    }
    SECTION("on popping reveals tops in reverse order of pushing") {
        Stack<int> stack{};
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        REQUIRE(stack.top() == 4);

        stack.pop();
        REQUIRE(stack.top() == 3);

        stack.pop();
        REQUIRE(stack.top() == 2);

        stack.pop();
        REQUIRE(stack.top() == 1);
    }
}
