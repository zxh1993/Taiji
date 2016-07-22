/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      定时线程
 * @author:    zhangxinhao
 * @date:      2016-06-20
 * Revision Description: initial version
 */
#include "CTimingThread.h"
namespace Taiji
{

namespace TUtil {



CTimingThread::~CTimingThread()
{
    stop();
}

void CTimingThread::start(std::shared_ptr<CTimingTask> ptask)
{
    if (nullptr == ptask)
    {
        return;
    }
    _ptask = ptask;
    if (_ptask->getCyclesTime() < 0)
    {
        return;
    }
    if (!_started)
    {
        _started = true;

        _thread = std::thread(&CTimingThread::__run, this);
    }
}

void CTimingThread::stop()
{
    if (_started)
    {
        _started = false;
        _thread.join();
    }
}

void CTimingThread::__run()
{
    if (_ptask->getCyclesTime() < 0)
    {
        return;
    }
    if (!(_started))
    {
        return;
    }
    _ptask->start();
    auto time = std::chrono::seconds(_ptask->getCyclesTime());
    bool isWait = true;
    if (_ptask->getCyclesTime() == 0)
    {
        isWait = false;
    }
    while(_started)
    {
        _ptask->run();
        if (isWait)
        {
            std::this_thread::sleep_for(time);
        }
    }
    _ptask->stop();
}


}
}
