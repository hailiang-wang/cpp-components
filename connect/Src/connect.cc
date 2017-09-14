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
    std::vector<Middleware* >::iterator it = _middlewares.begin();

    auto glambda = [=]() mutable {
        if (it != _middlewares.end()){
            std::vector<Middleware* >::iterator it2 = it + 1;
            (*it2)->apply(req, res, [=]() mutable {
                if (it2 != _middlewares.end()){
                    std::vector<Middleware* >::iterator it3 = it2 + 1;
                    if(it3 != _middlewares.end()){
                        (*it3)->apply(req, res, [=]() mutable {
                            // ugly code: add more to support more ...
                        });
                    } else {
                        std::cout << "this is end." <<endl;
                    }
                }
            });
        }
    };

    (*it)->apply(req, res, glambda);

    // while(true){
    //     pre = std::distance(_middlewares.begin(), it);
    //     (*it)->apply(req, res, it, [it](std::vector<Middleware* >::iterator& ptr) -> void {
    //         ptr++;
    //     });
    //     post = std::distance(_middlewares.begin(), it);
    //     if(pre == post){
    //         break;
    //     }
    // }
}

Mw1::Mw1(){};
Mw1::~Mw1(){};

void Mw1::apply(std::string& req, std::string& res, std::function<void() > next){
    std::cout<< "Mw1 req:" << req <<", res:" << res << endl;
    next();
    std::cout<< "Mw1 req2:" << req <<", res2:" << res << endl;
}

Mw2::Mw2(){};
Mw2::~Mw2(){};

void Mw2::apply(std::string& req, std::string& res, std::function<void() > next){
    std::cout<< "Mw2 req:" << req <<", res:" << res << endl;
    next();
    std::cout<< "Mw2 req2:" << req <<", res2:" << res << endl;
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
    app.use(mw);
    Connect::Mw2 mw2;
    app.use(mw2);
    std::string req = "query    ...";
    std::string res = "response ...";
    app.handle(req, res);

    return 0;
}