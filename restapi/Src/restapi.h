#ifndef  REST_API_H_
#define  REST_API_H_

#include "Common/ThirdParty/jsoncpp-0.5.0/include/json/json.h"

class RESt{
public:
    RESt();
    ~RESt();
    void print();
    bool get(const std::string& baseUrl, 
        const std::string& path, 
        Json::Value& result);
    bool post(const std::string& baseUrl, 
        const std::string& path, 
        const Json::Value& body, 
        Json::Value& result);
};


#endif // REST_API_H_