#include "CHttpHandler4.h"

CHttpHandler4::CHttpHandler4()
{

}

void CHttpHandler4::handleRequest(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &response)
{
    std::ostream &ostr = response.send();
    ostr << "CHttpHandler4::handleRequest" << std::flush;
}
