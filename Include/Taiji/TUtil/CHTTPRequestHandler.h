#ifndef CHTTPREQUESTHANDLER_H
#define CHTTPREQUESTHANDLER_H
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"

namespace Taiji {
namespace TUtil {

class CHTTPRequestHandler;
typedef void (CHTTPRequestHandler::*HandlerRequest) (Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

class CHTTPRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:

    CHTTPRequestHandler() = default;
    virtual ~CHTTPRequestHandler() = default;

    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    void setRealHandler(const HandlerRequest &realHandler);

protected:
    HandlerRequest _realHandler;
};


}
}

#endif // CHTTPREQUESTHANDLER_H
