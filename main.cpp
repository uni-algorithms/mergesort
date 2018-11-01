#include <cassert>
#include "sort.hpp"

auto main() -> int {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    assert(input);
    assert(output);

    auto result = mergesort(input);
    for (auto it : result) {
        output << it << " ";
    }

    input.close();
    output.close();
    return 0;
}