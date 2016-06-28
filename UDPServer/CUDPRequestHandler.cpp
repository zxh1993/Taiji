#include "CUDPRequestHandler.h"
#include "iostream"
#include "unistd.h"
CUDPRequestHandler::CUDPRequestHandler()
{

}

bool CUDPRequestHandler::handleRequest(const UString &request, UString &response)
{
    //sleep(1);
    uint8_t recv[] = "recv ";
    response = recv + request;
    return true;
}

