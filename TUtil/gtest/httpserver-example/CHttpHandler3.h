#ifndef CHTTPHANDLER3_H
#define CHTTPHANDLER3_H
#include "Taiji/TUtil/CHTTPRequestHandler.h"
#include "Poco/Net/HTTPServerResponse.h"

class CHttpHandler3 : public Poco::Net::HTTPRequestHandler
{
public:
    CHttpHandler3();
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};

#endif // CHTTPHANDLER3_H
