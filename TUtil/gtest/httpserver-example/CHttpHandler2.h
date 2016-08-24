#ifndef CHTTPHANDLER2_H
#define CHTTPHANDLER2_H

#include "Taiji/TUtil/CHTTPRequestHandler.h"
#include "Poco/Net/HTTPServerResponse.h"
using namespace Taiji::TUtil;

class CHttpHandler2 : public CHTTPRequestHandler
{
public:
    CHttpHandler2();
    void handleRequest1(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    void handleRequest2(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    void handleRequest3(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

};

#endif // CHTTPHANDLER2_H
