#ifndef CHTTPREQUESTHANDLER_H
#define CHTTPREQUESTHANDLER_H
#include "Poco/Net/HTTPRequestHandler.h"
namespace Taiji {
namespace TUtil {



class CHTTPRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    typedef void (CHTTPRequestHandler::*HANDLER) (Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
    CHTTPRequestHandler() = default;
    virtual ~CHTTPRequestHandler() = default;

    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    void setRealHandler(const HANDLER &realHandler);

protected:
    HANDLER _realHandler;
};


}
}

#endif // CHTTPREQUESTHANDLER_H
