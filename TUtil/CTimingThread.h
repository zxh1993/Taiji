/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      定时线程
 * @author:    zhangxinhao
 * @date:      2016-06-20
 * Revision Description: initial version
 */
#ifndef CTIMINGTHREAD_H
#define CTIMINGTHREAD_H

#include <iostream>
#include <thread>
#include <memory>

namespace Taiji
{

namespace TUtil {

class CTimingTask
{
public:
    CTimingTask() = default;
    virtual ~CTimingTask() = default;
    virtual void start() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;
    virtual int getCyclesTime() = 0;
};

class CTimingThread
{
public:
    CTimingThread() = default;
    CTimingThread(const CTimingThread &) = delete;
    CTimingThread & operator =(const CTimingThread &) = delete;
    ~CTimingThread();
    void start(std::shared_ptr<CTimingTask> ptask);
    void stop();
private:
    void __run();
    std::thread _thread;
    bool _started = false;
    std::shared_ptr<CTimingTask> _ptask;
};

}
}
#endif // CTIMINGTHREAD_H
