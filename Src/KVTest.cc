#include "KVSchedule.h"

#include "Common/Base/flags.h"
#include "Common/Base/logging.h"

using namespace std;
using namespace common;


int main(int argc, char *argv[])
{
    common::ParseCommandLineFlags(&argc, &argv, false);
    VLOG(3) << "run KVTest";
    int* p = new int(1);
    delete p;
    return 0;
}

