#include "CHttpHandler2.h"

CHttpHandler2::CHttpHandler2()
{

}

void CHttpHandler2::handleRequest1(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &response)
{
    std::ostream &ostr = response.send();
    ostr << "CHttpHandler2::handleRequest1" << std::flush;
}

void CHttpHandler2::handleRequest2(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &response)
{
    std::ostream &ostr = response.send();
    ostr << "CHttpHandler2::handleRequest2" << std::flush;
}

void CHttpHandler2::handleRequest3(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &response)
{
    std::ostream &ostr = response.send();
    ostr << "CHttpHandler2::handleRequest3" << std::flush;
}
