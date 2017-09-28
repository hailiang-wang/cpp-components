#ifndef  T_LOG_H_
#define  T_LOG_H_

#include <string>
#include <iostream>
using namespace std;

namespace cpp {
    namespace components {
        class TLOG{
        public:
            TLOG(int level, const std::string trace_id);
            ~TLOG();
            TLOG& operator << (const std::string);
        private:
            int _level = 5;
            std::string _trace_id;
            bool _start = true;
        };
    }
} // TLOG


#endif // T_LOG_H_
