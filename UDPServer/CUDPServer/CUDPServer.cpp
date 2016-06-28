/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      接受数据的服务
 * @author:    zhangxinhao
 * @date:      2016-06-13
 * Revision Description: initial version
 */
#include "CUDPServer.h"
#include "CUDPRunable.h"
#include "CUDPRequestBaseHandler.h"
#include "CUDPData.h"

void CUDPServer::init(std::shared_ptr<CUDPRequestBaseHandler> phandler, std::shared_ptr<CUDPSendCb> psendCb,
                      uint16_t port, uint16_t timeout, int minCapacity, int maxCapacity, int idleTime)
{
    _phandler = phandler;
    Poco::Net::SocketAddress addr(port);
    _socket.bind(addr);
    _socket.setReceiveTimeout(Poco::Timespan(timeout, 0));
    _ppool = std::shared_ptr<Poco::ThreadPool>(new Poco::ThreadPool(minCapacity, maxCapacity, idleTime));

     CUDPData::instance().init(_socket, psendCb);

}

void CUDPServer::start()
{
    if (!_started)
    {
        _started = true;
        CUDPData::instance().start();
        _serverThread.start(__server, this);
    }
}

void CUDPServer::stop()
{
    if (_started)
    {
        _started = false;
        _serverThread.join();
        CUDPData::instance().stop();
    }
}

void CUDPServer::__server(void * arg)
{
    CUDPServer *p = static_cast<CUDPServer *>(arg);
    uint8_t buf[2048];
    while (p->_started)
    {
        try
        {
            Poco::Net::SocketAddress addr;
            int ret = p->_socket.receiveFrom(buf, 2048, addr);
            if (ret > 0)
            {
                UString data(buf, ret);
                CUDPRunable *prun =new CUDPRunable(data, addr, p->_phandler);
                p->_ppool->start(*prun);
            }
        }
        catch(...)
        {

        }
    }
}

