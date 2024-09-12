#include "replace_util.hpp"
#include <string>

std::string replaceOccurrences(const std::string& content, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;
    size_t lastPos = 0;
    size_t s1Len = s1.length();

    while ((pos = content.find(s1, lastPos)) != std::string::npos)
    {
        result.append(content, lastPos, pos - lastPos);
        result.append(s2);
        lastPos = pos + s1Len;
    }

    result.append(content, lastPos, std::string::npos);
    return result;
}
