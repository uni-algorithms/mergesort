#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "sort.hpp"

TEST_CASE("test provided : { 2, 32, 12, 8, 7 }") {
    std::vector<int> expected = {2, 7, 8, 12, 32};
    std::istringstream in("5\n"
                          "2 32 12 8 7");
    REQUIRE (expected == mergesort(in));
}

TEST_CASE("{ 1, 2, 3, 4, 5 }") {
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> actual = {1, 2, 3, 4, 5};
    mergesort(actual);
    REQUIRE (expected == actual);
}

TEST_CASE("{ 1, 2, 5, 4, 3 }") {
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> actual = {1, 2, 5, 4, 3};
    mergesort(actual);
    REQUIRE (expected == actual);
}

TEST_CASE("{ 5, 4, 3, 2, 1 }") {
    std::vector<int> expected = {1, 2, 3, 4, 5};
    std::vector<int> actual = {5, 4, 3, 2, 1};
    mergesort(actual);
    REQUIRE (expected == actual);
}