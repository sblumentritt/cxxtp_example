#include "meta_information.hxx"

#include <cstdlib>
#include <ios>
#include <iostream>

#include "libutil/core/stack.hpp"
#include "libutil/date_time/leap_year.hpp"

auto main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) -> int {
    // print meta information
    std::cout << "> Name: " << meta_info::project_name << '\n';
    std::cout << "> Description: " << meta_info::project_description << '\n';

    std::cout << "> Version: " << meta_info::version << '\n';
    std::cout << "> Revision: " << meta_info::version_revision << '\n';

    std::cout << "> Build type: " << meta_info::build_type << '\n';
    std::cout << "> Compiler: " << meta_info::compiler << '\n';

    std::cout << '\n';

    // just some random usage of the libutil
    auto stack = core::Stack<std::string>{};
    stack.push("topping :)");
    std::cout << "stack top = " << stack.top() << '\n';

    std::cout << "is 2020 a leap year? -> " << std::boolalpha << date_time::is_leap_year(2020)
              << '\n';
    std::cout << "is 2021 a leap year? -> " << std::boolalpha << date_time::is_leap_year(2021)
              << '\n';

    // preferred over return 0
    return EXIT_SUCCESS;
}
