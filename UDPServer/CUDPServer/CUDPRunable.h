/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      线程池的线程
 * @author:    zhangxinhao
 * @date:      2016-06-13
 * Revision Description: initial version
 */
#ifndef CUDPRUNABLE_H
#define CUDPRUNABLE_H
#include <iostream>
#include <string>
#include <memory>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Runnable.h>
class CUDPRequestBaseHandler;
using UString = std::basic_string<uint8_t>;

class CUDPRunable : public Poco::Runnable
{
public:
    CUDPRunable() = delete;
    CUDPRunable(const CUDPRunable &) = delete;
    CUDPRunable(CUDPRunable &&) = delete;
    CUDPRunable & operator =(const CUDPRunable &) = delete;
    CUDPRunable & operator =(CUDPRunable &&) = delete;
    CUDPRunable(UString &data, const Poco::Net::SocketAddress &addr, std::shared_ptr<CUDPRequestBaseHandler> phandler);
    ~CUDPRunable() = default;

    void run();

private:
    UString _data;
    Poco::Net::SocketAddress _addr;
    std::shared_ptr<CUDPRequestBaseHandler> _phandler;

};

#endif // CUDPRUNABLE_H
