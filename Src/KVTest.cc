#include "KVSchedule.h"

#include "Common/Base/flags.h"
#include "Common/Base/logging.h"
#include "Common/ThirdParty/boost/boost/shared_ptr.hpp"
#include "Common/ThirdParty/boost/boost/make_shared.hpp"

using namespace std;

void keepAlive(boost::shared_ptr<Common::Util::KVJob>& kvj){
    while(true){
        usleep(3 * 1000 * 1000);
        VLOG(3) << "main check esHost:" << kvj->esHost;
        VLOG(3) << "main check count:" << kvj.use_count();
    }
}

int main(int argc, char *argv[])
{
    common::ParseCommandLineFlags(&argc, &argv, false);
    VLOG(3) << "run KVTest";
    Common::Util::KVSchedule kvSchedule;
    kvSchedule.init(1);
    kvSchedule.load();

    boost::shared_ptr<Common::Util::KVJob> kvj = boost::make_shared<Common::Util::KVJob>();
    kvj->esHost = "bar";
    kvj->esPort = "bar";
    kvj->esIndex = "bar";
    kvSchedule.addJob(kvj);

    // force the main process does not exit
    keepAlive(kvj);
    return 0;
}