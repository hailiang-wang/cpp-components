#ifndef  CONNECT_MW_H_
#define  CONNECT_MW_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<typename Lambda>
bool callback(std::string& Arg1, std::string& Arg2, Lambda Arg3){ // or Lambda&&, which is usually better
    Arg3(Arg1, Arg2);
    return false; // remember, all control paths must return a value
}

namespace Common {
namespace Connect {
class Middleware 
{
 public:
    Middleware();
    virtual ~Middleware();
    virtual void apply(std::string& req, std::string& res) = 0;
};

class Connect{
 private:
    std::vector<Middleware* > _middlewares;

 public:
    Connect();
    ~Connect();
    void use(Middleware& mw);
    void handle(std::string& req, std::string& res);
};

class Mw1: public Middleware
{
public: // constructor
    Mw1();
    ~Mw1();
public: // functions
    void apply(std::string& req, std::string& res);
};

class Mw2: public Middleware
{
public: // constructor
    Mw2();
    ~Mw2();
public: // functions
    void apply(std::string& req, std::string& res);
};

}
} // Connect


#endif // CONNECT_MW_H_