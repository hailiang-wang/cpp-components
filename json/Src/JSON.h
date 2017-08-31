#ifndef  COMMON_JSON_H_
#define  COMMON_JSON_H_

#include "Common/ThirdParty/jsoncpp-0.5.0/include/json/json.h"

using namespace std;

namespace Common
{
    namespace Util
    {
        class JSON{
            
        public:
            JSON();
            ~JSON();

            static bool parse(const std::string& raw, Json::Value& result);
            static bool stringify(const Json::Value& j, std::string& result);

        };
    }
}

#endif // COMMON_JSON_H_