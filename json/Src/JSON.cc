#include "JSON.h"

namespace Common
{
namespace Util
{


JSON::JSON(){
};

JSON::~JSON(){
};

bool JSON::parse(const std::string& raw, Json::Value& result){
    bool rc = true;
    Json::Reader *r = new Json::Reader(Json::Features::strictMode());
    if(!r->parse(raw, result))
    {
        rc = false;
    }
    delete r;
    return rc;
}

bool JSON::stringify(const Json::Value& j, std::string& result){
    bool rc = true;
    Json::FastWriter writer;
    result = writer.write(j);
    return rc;
}
}
}