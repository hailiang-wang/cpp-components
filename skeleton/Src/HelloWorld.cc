#include "HelloWorld.h"

#include <iostream>

using namespace std;

namespace mycompany {
    namespace project {
        HelloWorld::HelloWorld(){};
        HelloWorld::~HelloWorld(){};

        void HelloWorld::print(){
            std::cout<<"Hello world" << endl;
        }
    }
} // name

int main(int argc, char const *argv[])
{
    mycompany::project::HelloWorld hw;
    hw.print();
    return 0;
}

