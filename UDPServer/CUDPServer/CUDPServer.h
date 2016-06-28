/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      接受数据的服务
 * @author:    zhangxinhao
 * @date:      2016-06-13
 * Revision Description: initial version
 */
#ifndef CUDPSERVER_H
#define CUDPSERVER_H

#include <memory>
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Thread.h>
#include <Poco/ThreadPool.h>


class CUDPRequestBaseHandler;
class CUDPSendCb;

class CUDPServer
{
public:
    CUDPServer() = default;
    ~CUDPServer() = default;

    void init(std::shared_ptr<CUDPRequestBaseHandler> phandler, std::shared_ptr<CUDPSendCb> psendCb, uint16_t port, uint16_t timeout = 5,
              int minCapacity = 500, int maxCapacity = 600, int idleTime = 60);

    void start();

    void stop();

private:
    static void __server(void *arg);
    Poco::Thread _serverThread;

    Poco::Net::DatagramSocket _socket;
    std::shared_ptr<CUDPRequestBaseHandler> _phandler;
    uint16_t _port;
    Poco::Timespan _timeout = 0 ;
    bool _started = false;
    std::shared_ptr<Poco::ThreadPool> _ppool;
};

#endif // CUDPSERVER_H
