#ifndef CHTTPHANDLER4_H
#define CHTTPHANDLER4_H

#include "Taiji/TUtil/CHTTPRequestHandler.h"
#include "Poco/Net/HTTPServerResponse.h"

class CHttpHandler4 : public Poco::Net::HTTPRequestHandler
{
public:
    CHttpHandler4();
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};
#endif // CHTTPHANDLER4_H
