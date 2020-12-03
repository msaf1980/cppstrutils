/* inlined functions */
namespace strutils {

/* Check string if starts with prefix */
inline bool starts_with(const std::string &s, const std::string &prefix) {
    return s.size() >= prefix.size() &&
           s.compare(0, prefix.size(), prefix) == 0;
}

} // namespace strutils
