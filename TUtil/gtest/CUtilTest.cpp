/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file xxxxxxx
* @brief 文件的简单介绍
*
* 文件的详细介绍
*
* @author: yuhaiyang
* @date: 2016/5/13
*/

#include "CUtilTest.h"

#define LOG_IN Taiji::TUtil::ELogType::IN, typeid(*this).name(), __func__

#define LOG_IN_NOINDEX Taiji::TUtil::ELogType::IN, typeid(*this).name(), __func__, "", ""

using namespace Taiji::TUtil;


void CUtilTest::SetUpTestCase()
{

}

void CUtilTest::TearDownTestCase()
{

}


TEST_F(CUtilTest, CLogs)
{
    CLogs::instance().createLog("./log/","CLogs_test1.log", "TEST_LOG1");
    CLogs::instance().createLog("./log/","CLogs_test2.log", "TEST_LOG2");


    CLog& log1 = CLogs::instance().getLog( "TEST_LOG1" );
    log1.information(LOG_IN_NOINDEX, std::string("test") );

    CLog& log2 = CLogs::instance().getLog( "TEST_LOG2" );
    log2.information(LOG_IN, "indexName", "indexValue","This is %s\n", std::string("test"));
}

template class CSingleton<CLog, 1>;
template class CSingleton<CLog, 2>;

extern template class CSingleton<CLog, 1>;
extern template class CSingleton<CLog, 2>;

using Log1 = CSingleton<CLog, 1>;
using Log2 = CSingleton<CLog, 2>;



TEST_F(CUtilTest, CLog_CSingleton)
{

    Log1::instance().initLog("./log/","singleton_log1.log","singleton_log1");
    Log2::instance().initLog("./log/","singleton_log2.log","singleton_log2");


    Log1::instance().information(LOG_IN, "indexName", "indexValue","This is %s\n", std::string("test1"));
    Log2::instance().information(LOG_IN, "indexName", "indexValue","This is %s\n", std::string("test2"));
}

TEST_F(CUtilTest, CLog_Num)
{
    CLog log;
    log.initLog("./log/","lognum.log","lognum");
    std::string logNum = CLog::getLogNumber();
    log.information(LOG_IN, "logNum", logNum, "xxxx1");
    log.information(LOG_IN, "logNum", logNum, "xxxx2");
    log.information(LOG_IN, "logNum", logNum, "xxxx3");
    log.information(LOG_IN, "logNum", logNum, "xxxx4");
    logNum = CLog::getLogNumber();
    log.information(LOG_IN, "logNum", logNum, "yyyy1");
    log.information(LOG_IN, "logNum", logNum, "yyyy2");
    log.information(LOG_IN, "logNum", logNum, "yyyy3");
    log.information(LOG_IN, "logNum", logNum, "yyyy4");
}

