#include "utils.hpp"

using namespace std;

namespace Utils
{
    void split(const string &source, char delim, vector<string> &elems) {
        stringstream ss;
        string item;
        ss.str(source);
        while( getline(ss, item, delim) ) {
            elems.push_back(item);
        }
    }
}
