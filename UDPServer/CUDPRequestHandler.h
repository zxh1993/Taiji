#ifndef CUDPREQUESTHANDLER_H
#define CUDPREQUESTHANDLER_H
#include "CUDPServer/CUDPRequestBaseHandler.h"

class CUDPRequestHandler : public CUDPRequestBaseHandler
{
public:
    CUDPRequestHandler();
    bool handleRequest(const UString &request, UString &response);

};

#endif // CUDPREQUESTHANDLER_H
