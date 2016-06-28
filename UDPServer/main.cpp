#include <iostream>
#include "CUDPRequestHandler.h"
#include "CUDPServer/CUDPServer.h"
#include "CUDPServer/CUDPData.h"
using namespace std;

class CB : public CUDPSendCb
{
public:
    CB() {}
    void _cb(const UString &data, int realSent, const Poco::Net::SocketAddress &)
    {
        if (realSent > 0)
        {
            sentOK ++;
        }
        else
        {
            sentErr ++;
            std::cout << "sendData:" <<(const char *) data.c_str() << std::endl;
        }
    }
    int sentOK = 0;
    int sentErr = 0;
};

int main()
{
    CUDPServer server;

    std::shared_ptr<CUDPSendCb> p(new CB);

    server.init(std::shared_ptr<CUDPRequestHandler>(new CUDPRequestHandler), p, 9999, 5, 500, 600, 30);
    server.start();
    string tmp;

    while(true)
    {
        std::cin >> tmp;
        if ("quit" == tmp)
        {
            break;
        }

    }
    std::cout << "stop...." <<std::endl;
    server.stop();
    return 0;
}

