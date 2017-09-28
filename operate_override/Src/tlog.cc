#include "tlog.h"

#include <string>
#include <iostream>
using namespace std;

namespace cpp {
namespace components {
TLOG::TLOG(int level, const std::string trace_id = "default"){
    _level = level;
    _trace_id = trace_id;
};
TLOG::~TLOG(){};

TLOG& TLOG::operator << (const std::string trace) 
{
    if(_start){
        _start = false;
        std::cout << _trace_id << " " << trace;
    } else {
        std::cout << trace;
    }
    return *this;

}

}
} // name

int main(int argc, char const *argv[])
{
    cpp::components::TLOG(5, "default2") << "waht ..." << " fooo ";
    return 0;
}

