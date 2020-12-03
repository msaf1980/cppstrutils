#ifndef __STRUTILS_HPP__
#define __STRUTILS_HPP__

#include <string_view>
#include <vector>

namespace strutils {
std::vector<std::string_view> split(const std::string_view str,
                                    const char delim = ',');
}

#endif // __STRUTILS_HPP__