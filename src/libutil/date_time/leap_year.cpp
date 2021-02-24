#include "libutil/date_time/leap_year.hpp"

namespace date_time {
auto is_leap_year(int year) -> bool {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
} // namespace date_time
