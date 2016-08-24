#include "CHttpHandler3.h"

CHttpHandler3::CHttpHandler3()
{

}

void CHttpHandler3::handleRequest(Poco::Net::HTTPServerRequest &, Poco::Net::HTTPServerResponse &response)
{
    std::ostream &ostr = response.send();
    ostr << "CHttpHandler3::handleRequest" << std::flush;
}

