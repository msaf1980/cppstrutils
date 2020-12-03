#include <strutils.hpp>

#include <unistd.h>

namespace strutils {

std::vector<std::string_view> split(const std::string_view str,
                                    const char delim) {
    std::vector<std::string_view> result;

    ssize_t index_left = 0;
    ssize_t index_right = -1;

    for (int i = 0; i < static_cast<int>(str.size()); i++) {
        if (str[i] == delim) {
            index_left = index_right;
            index_right = i;
            ssize_t index = index_left + 1;
            ssize_t length = index_right - index;

            std::string_view column(str.data() + index, length);
            result.push_back(column);
        }
    }
    const std::string_view finalColumn(str.data() + index_right + 1,
                                       str.size() - index_right - 1);
    result.push_back(finalColumn);
    return result;
}

} // namespace strutils