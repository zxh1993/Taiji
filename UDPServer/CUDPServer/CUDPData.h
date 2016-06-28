/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      发送队列
 * @author:    zhangxinhao
 * @date:      2016-06-13
 * Revision Description: initial version
 */
#ifndef CUDPDATA_H
#define CUDPDATA_H
#include <list>
#include <tuple>
#include <string>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Thread.h>
#include <Poco/Condition.h>
#include <Poco/Net/DatagramSocket.h>
#include <memory>

using UString = std::basic_string<uint8_t>;

class CUDPSendCb
{
public:
    CUDPSendCb() = default;
    virtual void _cb(const UString &data, int realSent, const Poco::Net::SocketAddress &addr) = 0;
    virtual ~CUDPSendCb() = default;
};

class CUDPData
{
public:
    CUDPData(const CUDPData &) = delete;
    CUDPData(CUDPData &&) = delete;
    CUDPData & operator =(const CUDPData &) = delete;
    CUDPData & operator =(CUDPData &&) = delete;

    static CUDPData &instance();

    void init(const Poco::Net::DatagramSocket &sendSocket, std::shared_ptr<CUDPSendCb> pSendCb);

    void start();

    void stop();

    void send(const Poco::Net::SocketAddress &addr, const UString &data);

private:
    using DataPairs = std::tuple<Poco::Net::SocketAddress, UString>;
    std::shared_ptr<CUDPSendCb> _pSendCb = nullptr;
    CUDPData() = default;
    ~CUDPData() = default;

    static void __server(void *arg);
    Poco::Thread _serverThread;

    std::list<DataPairs> _listPairs;
    Poco::Mutex _mutex;
    Poco::Condition _cond;
    Poco::Net::DatagramSocket _sendSocket;
    bool _started = false;
};

#endif // CUDPDATA_H
