#include "CSerApp.h"
#include "Taiji/TUtil/CHTTPRequestHandlerFactory.h"
#include "CHttpHandler1.h"
#include "CHttpHandler2.h"
#include "CHttpHandler3.h"
#include "CHttpHandler4.h"
#include <iostream>


void CSerApp::_init()
{
    CHTTPRequestHandlerFactory *factory = new CHTTPRequestHandlerFactory;
    factory->addHandlerAndFun("/url1/handler1", &CHttpHandler1::handleRequest1);
    factory->addHandlerAndFun("/url1/handler2", &CHttpHandler1::handleRequest2);
    factory->addHandlerAndFun("/url1/handler3", &CHttpHandler1::handleRequest3);
    factory->addHandlerAndFun("/url2/handler1", &CHttpHandler2::handleRequest1);
    factory->addHandlerAndFun("/url2/handler2", &CHttpHandler2::handleRequest2);
    factory->addHandlerAndFun("/url2/handler3", &CHttpHandler2::handleRequest3);

    factory->addHandler<CHttpHandler3>("/url3");
    factory->addHandler<CHttpHandler4>("/url4");
    _server.init(factory, 9020, 5, 50, 50);

}

void CSerApp::_start()
{
    _server.start();
}

void CSerApp::_stop()
{
    _server.stop();
}

POCO_SERVER_MAIN(CSerApp)
