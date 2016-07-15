/**
 * @file		CHttpServer.cpp
 * @brief 		CHttpServer 的实现
 *
 * @author: 	yuhaiyang
 * @date: 	2015/11/4  2015
 */
#include "CHttpServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"

using Poco::Net::ServerSocket;
using Poco::Net::HTTPServerParams;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPRequestHandlerFactory;
using namespace Taiji::TUtil;


CHttpServer::~CHttpServer()
{
    stop();
}

void CHttpServer::init(Poco::Net::HTTPRequestHandlerFactory::Ptr factory, uint16_t port, uint16_t timeout, uint16_t maxQueue, uint16_t maxThreads)
{
    if (!_started)
    {
        if (nullptr == factory)
        {
            return;
        }

        ServerSocket svs(port);
        HTTPServerParams* pParams = new HTTPServerParams;
        pParams->setMaxQueued(maxQueue);
        pParams->setMaxThreads(maxThreads);
        pParams->setTimeout(Poco::Timespan (timeout, 0));
        _pHttpser = new Poco::Net::HTTPServer(factory, svs, pParams);
    }
}


void CHttpServer::start()
{
    if (!_started)
    {
        if (nullptr == _pHttpser)
        {
            return;
        }
        _pHttpser->start();
        _started = true;
    }

}


void CHttpServer::stop()
{
    if (_started)
    {
        _pHttpser->stop();
        delete _pHttpser;
        _pHttpser = nullptr;
        _started = false;
    }
}
