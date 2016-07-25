#include "CHTTPRequestHandler.h"
namespace Taiji {
namespace TUtil {


void CHTTPRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    (this->*_realHandler)(request, response);
}

void CHTTPRequestHandler::setRealHandler(const HandlerRequest &realHandler)
{
    _realHandler = realHandler;
}

}
}
