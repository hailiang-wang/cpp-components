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
    for(auto it = _middlewares.cbegin(); it != _middlewares.cend();){
        (*it)->apply(res, req);
        ++it;
    }
}

ParseMw::ParseMw(){};
ParseMw::~ParseMw(){};

void ParseMw::apply(std::string& req, std::string& res){
    std::cout<< "ParseMw req:" << req <<", res:" << res << endl;
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
    Connect::ParseMw mw;
    app.use(mw);
    std::string req = "query ...";
    std::string res = "response ...";
    app.handle(req, res);

    return 0;
}

