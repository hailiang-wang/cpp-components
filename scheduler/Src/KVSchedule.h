#ifndef  COMMON_KV_SCHEDULE_H_
#define  COMMON_KV_SCHEDULE_H_

#include <map>
#include <vector>
#include <string>

#include "Common/ThirdParty/boost/boost/shared_ptr.hpp"
#include "Common/Util/Thread/mutex.h"

using namespace std;
using namespace common;

namespace Common
{
namespace Util
{
class KVJob{
private:
    std::map<std::string, std::string> obj;

public:
    std::string esHost;
    std::string esPort;
    std::string esIndex;

public:
    KVJob();
    ~KVJob();
};

class KVSchedule{
private:
    int _interval;
    std::vector<boost::shared_ptr<KVJob> > _joblist;
    common::Mutex _lock;

public:
    KVSchedule();
    ~KVSchedule();
    void init(const int interval);
    void load();
    void liveload();
    void addJob(boost::shared_ptr<KVJob> kvj);
};
}
}

#endif // COMMON_KV_SCHEDULE_H_