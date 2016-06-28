/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      发送队列
 * @author:    zhangxinhao
 * @date:      2016-06-13
 * Revision Description: initial version
 */
#include "CUDPData.h"
#include "Poco/Thread.h"
CUDPData &CUDPData::instance()
{
    static CUDPData x;
    return x;
}

void CUDPData::init(const Poco::Net::DatagramSocket &sendSocket, std::shared_ptr<CUDPSendCb> pSendCb)
{
    _sendSocket = sendSocket;
    _pSendCb = pSendCb;
}



void CUDPData::start()
{
    if (!_started)
    {
        _started = true;
        _serverThread.start(__server, this);
    }
}

void CUDPData::stop()
{
    if (_started)
    {
        _started = false;
        _serverThread.join();
    }
}


void CUDPData::send(const Poco::Net::SocketAddress &addr, const UString &data)
{
     Poco::Mutex::ScopedLock lock(_mutex);
    _listPairs.push_back(DataPairs(addr, data));
    _cond.signal();
}


void CUDPData::__server(void *arg)
{
    CUDPData* p= static_cast<CUDPData *>(arg);
    try
    {
        while (p->_started)
        {
            p->_mutex.lock();
            if (p->_listPairs.size() == 0)
            {
                p->_cond.tryWait(p->_mutex, 2000);
            }
            std::list<DataPairs> tmp = std::move(p->_listPairs);
            p->_mutex.unlock();

            for (auto &x : tmp)
            {
                UString &data = std::get<1>(x);
                Poco::Net::SocketAddress &addr = std::get<0>(x);
                int n = p->_sendSocket.sendTo(data.c_str(), data.size(), addr);
                if (nullptr != p->_pSendCb)
                {
                    p->_pSendCb->_cb(data, n, addr);
                }
            }
        }
    }
    catch(...)
    {
        //std::cout << "error" <<std::endl;
    }

}

