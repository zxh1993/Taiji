/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      http工厂
 * @author:    zhangxinhao
 * @date: 	   2016-07-19
 * Revision Description: initial version
 */
#include "CHTTPRequestHandlerFactory.h"
using namespace Poco::Net;
using namespace Taiji::TUtil;

HTTPRequestHandler *CHTTPRequestHandlerFactory::createRequestHandler(const HTTPServerRequest &request)
{

    try
    {
        std::string uri = request.getURI();
        if (request.getMethod() == "GET")
        {
            int pos = uri.find('?');
            uri = uri.substr(0, pos);
        }
        auto pair = _map.find(uri);
        if (_map.end() != pair)
        {
            return pair->second();
        }
    }catch(...)
    {

    }
    return nullptr;
}

