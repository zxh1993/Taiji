/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      http工厂
 * @author:    zhangxinhao
 * @date: 	   2016-07-19
 * Revision Description: initial version
 */
#ifndef CHTTPREQUESTHANDLERFACTORY_H
#define CHTTPREQUESTHANDLERFACTORY_H

#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include <map>
#include <functional>
#include "Taiji/TExcept/Except.h"

namespace Taiji {
namespace TUtil {

class CHTTPRequestHandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
public:
    CHTTPRequestHandlerFactory() = default;
    virtual ~CHTTPRequestHandlerFactory() = default;

    virtual Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &);

    template <class Handler>
    void addHandler(const std::string &url)
    {
        if (_map.end() == _map.find(url))
        {
            _map.insert(std::make_pair(url, [](){return new Handler;}));
        }
        else
        {
            throw Taiji::ExceptTUtil("CHTTPRequestHandlerFactory " + url + " is exist!");
        }

    }

private:
    std::map<std::string, std::function<Poco::Net::HTTPRequestHandler *()>> _map;


};


}

}


#endif // CHTTPREQUESTHANDLERFACTORY_H
