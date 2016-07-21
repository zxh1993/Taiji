/**
 * Copyright (c) 2015, 爱wifi（版权声明）
 *
 * @file	HttpServer.h
 * @brief 基于　Poco::HTTPServer 的http 服务器。
 *
 * @author: 		yhy
 * @date: 		May 6, 2015
 *
 * 修订说明:初始版本
 */
#ifndef CHTTPSERVER_H
#define CHTTPSERVER_H

#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServer.h"
namespace Taiji
{

namespace TUtil {



class CHttpServer
{
public:
    CHttpServer() = default;

    ~CHttpServer();

    void init(Poco::Net::HTTPRequestHandlerFactory::Ptr factory,
              uint16_t port, uint16_t timeout, uint16_t maxQueue, uint16_t maxThreads);

    void start();

    void stop( );

private:
    Poco::Net::HTTPServer * _pHttpser = nullptr;
    bool _started = false;
};


}
}

#endif //CHTTPSERVER_H
