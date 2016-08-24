#ifndef CHTTPHANDLER1_H
#define CHTTPHANDLER1_H
#include "Taiji/TUtil/CHTTPRequestHandler.h"
#include "Poco/Net/HTTPServerResponse.h"
using namespace Taiji::TUtil;

class CHttpHandler1 : public CHTTPRequestHandler
{
public:
    CHttpHandler1();
    void handleRequest1(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    void handleRequest2(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    void handleRequest3(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
private:
    std::string str;

};

#endif // CHTTPHANDLER1_H
