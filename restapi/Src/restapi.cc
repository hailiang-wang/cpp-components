#include "restapi.h"

#include <Common/Base/time.h>
#include "Common/Base/stringUtil.h"
#include <Common/Util/HttpClient/curlWrapper.h>
#include "Common/Util/Encode/encodeUtil.h"

#include <string>
#include <map>

using namespace std;
using encode::GBK2UTF8;
using encode::UTF82GBK;
using std::map;
using std::string;
using std::vector;

RESt::RESt(){};
RESt::~RESt(){};

// Send RESt PUT request
bool RESt::post(const std::string& baseUrl, 
    const std::string& path, 
    const Json::Value& body, 
    Json::Value& result){
    bool rc = true;
    Json::FastWriter writer;
    string data = writer.write(body);
    string response, errorInfo;
    int64 startTime=common::GetTimeInMs();
    int status=CurlWrapper::GetPostRespondData(baseUrl+path, data, &response, &errorInfo);
    int64 time=common::GetTimeInMs()-startTime;
    // parse response as Json
    VLOG(5)<<"es search time:\t"<<time << "ms status "<< status;

    if(status!=0){
    VLOG(2)<<"es search fail:"<<errorInfo;
    rc = false;
    } else {
    Json::Reader *reader = new Json::Reader(Json::Features::strictMode());
    if(!reader->parse(response, result))
    {
    VLOG(0) << "json format error!";
    rc = false;
    } else if(!result["created"]){
    VLOG(0) << "object is not created.";
    rc = false;
    }
    delete reader;
    }
    return rc;
}

bool RESt::get(const std::string& baseUrl, 
    const std::string& path, 
    Json::Value& result){
    bool rc = true;
    string response, errorInfo;
    int status = CurlWrapper::GetRespondData(baseUrl+path, &response, &errorInfo);

    if(status!=0){
    VLOG(2)<<"es search fail:"<<errorInfo;
    rc = false;
    } else {
    Json::Reader *reader = new Json::Reader(Json::Features::strictMode());
    if(!reader->parse(response, result))
    {
    VLOG(0) << "json format error!";
    rc = false;
    }
    delete reader;
    }
    return rc;
}