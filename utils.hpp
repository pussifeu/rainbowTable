#ifndef UTILS_H
#define UTILS_H 

#include <sstream>
#include <string>
#include <vector>
#include "math.h"

namespace Utils
{
    void split(const std::string &source, char delim, std::vector<std::string> &elems);
}
#endif /* ifndef UTILS_H */
