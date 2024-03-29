//
//  connect.h
//  Connect
//
//  Created by Hai Liang Wang<hailiang.hl.wang@gmail.com> on 17/09/14.
//  Copyright © 2017. All rights reserved.
//
#ifndef  CONNECT_MW_H_
#define  CONNECT_MW_H_

#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

namespace Common {
namespace Connect {
class Middleware 
{
 public:
    Middleware();
    virtual ~Middleware();
    virtual void apply(std::string& req, std::string& res, std::function<void() >& next) = 0;
};

class Connect{
 private:
    std::vector<Middleware* > _middlewares;
    std::vector<Middleware* >::iterator _end;

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
    // void apply(std::string& req, std::string& res, std::vector<Middleware* >::iterator& next);
    void apply(std::string& req, std::string& res, std::function<void() >& next);
    
};

class Mw2: public Middleware
{
public: // constructor
    Mw2();
    ~Mw2();
public: // functions
    void apply(std::string& req, std::string& res, std::function<void() >& next);
};

}
} // Connect


#endif // CONNECT_MW_H_