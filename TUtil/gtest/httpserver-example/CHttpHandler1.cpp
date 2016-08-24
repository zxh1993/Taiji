#include "CHttpHandler1.h"

CHttpHandler1::CHttpHandler1()
{

}

void CHttpHandler1::handleRequest1(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &response)
{
    std::ostream &ostr = response.send();
    str = "asd";
    ostr << "CHttpHandler1::handleRequest1" + str << std::flush;
}

void CHttpHandler1::handleRequest2(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &response)
{
    std::ostream &ostr = response.send();
    ostr << "CHttpHandler1::handleRequest2" << std::flush;
}

void CHttpHandler1::handleRequest3(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &response)
{
    std::ostream &ostr = response.send();
    ostr << "CHttpHandler1::handleRequest3" << std::flush;
}
