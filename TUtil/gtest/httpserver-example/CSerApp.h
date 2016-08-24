#ifndef CSERAPP_H
#define CSERAPP_H

#include "Taiji/TUtil/CServerApplication.h"
#include "Taiji/TUtil/CHttpServer.h"

using namespace Taiji::TUtil;
class CSerApp : public CServerApplication
{
public:
    CSerApp() = default;
protected:
    void _init();
    void _start();
    void _stop();
private:
    CHttpServer _server;
};

#endif // CSERAPP_H
