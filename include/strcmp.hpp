/* inlined functions */
namespace strutils {

/* Check string if starts with prefix string */
inline bool starts_with(const std::string &s, const std::string &prefix) {
    return s.size() >= prefix.size() &&
           s.compare(0, prefix.size(), prefix) == 0;
}

/* Check string if starts with prefix char */
inline bool first_is(const std::string &s, char prefix) {
    return s.size() > 0 && s[0] == prefix;
}

/* Check string if ends with postfix string */
inline bool ends_with(const std::string &s, const std::string &postfix) {
    return s.size() >= postfix.size() &&
           s.compare(s.size() - postfix.size(), postfix.size(), postfix) == 0;
}

/* Check string if ends with postfix char */
inline bool last_is(const std::string &s, char postfix) {
    return s.size() > 0 && s[s.size() - 1] == postfix;
}

} // namespace strutils
