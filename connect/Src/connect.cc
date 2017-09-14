#include "connect.h"

#include <iostream>

using namespace std;
using namespace Common;

namespace Common {
namespace Connect {

Middleware::Middleware(){};
Middleware::~Middleware(){};

Connect::Connect(){};
Connect::~Connect(){};

void Connect::use(Middleware& mw)
{
    _middlewares.push_back(&mw);
}

void Connect::handle(std::string& req, std::string& res){
    std::cout << "handle: " << req <<endl;
    std::string nx = "next";
    for(std::vector<Middleware* >::iterator it = _middlewares.begin(); it != _middlewares.end();){
        (*it)->apply(res, req);
        ++it;
    }
}

Mw1::Mw1(){};
Mw1::~Mw1(){};

void Mw1::apply(std::string& req, std::string& res){
    std::cout<< "Mw1 req:" << req <<", res:" << res << endl;
}

Mw2::Mw2(){};
Mw2::~Mw2(){};

void Mw2::apply(std::string& req, std::string& res){
    std::cout<< "Mw2 req:" << req <<", res:" << res << endl;
}

}
} // name

int main(int argc, char const *argv[])
{
    // auto glambda = [](int D) -> bool {
    //     std::cout << "Print int " << D << endl;
    //     return D < 0;
    // };

    // callback(12, glambda);
    
    Connect::Connect app;
    Connect::Mw1 mw;
    Connect::Mw2 mw2;
    app.use(mw);
    app.use(mw2);
    std::string req = "query ...";
    std::string res = "response ...";
    app.handle(req, res);

    return 0;
}

