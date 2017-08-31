#include "KVSchedule.h"
#include "Common/Base/logging.h"
#include <thread>

using namespace std;
using namespace common;

namespace Common
{
namespace Util
{

KVJob::KVJob(){
};

KVJob::~KVJob(){
};

KVSchedule::KVSchedule(){
    _interval = 0;
};

KVSchedule::~KVSchedule(){
};

void KVSchedule::addJob(boost::shared_ptr<KVJob> shared_kvj){
    _joblist.push_back(shared_kvj);
};

void KVSchedule::init(const int interval){
    _interval = interval;
    std::thread reloader(&KVSchedule::liveload, this);
    reloader.detach();
};

void KVSchedule::load(){
    common::MutexLock lock(&_lock);
    VLOG(3) << "load joblist size: " << _joblist.size() << ", interval: "<< _interval << "s.";
    // do the reload job
    for(std::vector<boost::shared_ptr<KVJob> >::iterator it = _joblist.begin(); it != _joblist.end(); ++it){
        VLOG(3) << "get host:" << (*it)->esHost;
        (*it)->esHost = "foo";
        VLOG(3) << "Change host to foo.";
    }
};

void KVSchedule::liveload(){
    // Live load kb data
    while(true){
        // usleep take microseconds in parameters, not milliseconds.
        // usleep(_interval * 60 * 1000 * 1000);
        usleep(_interval * 1000 * 1000);
        VLOG(3) << "reload data after sleeping ...";
        load();
    }
}
}
}