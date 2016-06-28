/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      线程池的线程
 * @author:    zhangxinhao
 * @date:      2016-06-13
 * Revision Description: initial version
 */
#include "CUDPRunable.h"
#include "CUDPData.h"
#include "CUDPRequestBaseHandler.h"
CUDPRunable::CUDPRunable(UString &data, const Poco::Net::SocketAddress &addr, std::shared_ptr<CUDPRequestBaseHandler> phandler):
    _addr(addr), _phandler(phandler)
{
    _data = std::move(data);
}

void CUDPRunable::run()
{
    try
    {
        UString reply;
        if (_phandler->handleRequest(_data, reply))
        {
            CUDPData::instance().send(_addr, reply);
        }
    }
    catch(...)
    {

    }
    delete this;
}
