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

#include "CUtilUnitTest.h"
#include "Taiji/TUtil/CLogs.h"
#include "Taiji/TUtil/CSingleton.h"

using namespace Taiji::TUtil;


void CUtilUnitTest::SetUpTestCase()
{

}

void CUtilUnitTest::TearDownTestCase()
{

}




TEST_F( CUtilUnitTest, Logs_test )
{
    CLogs::instance().createLog( "./log/","test.log","TEST_LOG" );
    CLogs::instance().createLog( "./log/","test2.log","TEST_LOG2" );


    CLog& log1 = CLogs::instance().getLog( "TEST_LOG" );
    log1.information( ELogType::IN, typeid(*this).name(),__func__, "", "","This is %s\n", std::string("test") );

    CLog& log2 = CLogs::instance().getLog( "TEST_LOG2" );
    log2.information( ELogType::IN, typeid(*this).name(),__func__,"mac", "12345678901","This is %s\n", std::string("test") );
}




TEST_F( CUtilUnitTest, CUtil_Log )
{

    CSingleton<CLog>::instance().initLog("./log/","unitTest.log","UNIT_TEST_LOG");

    CSingleton<CLog>::instance().information( ELogType::IN, typeid(*this).name(),__func__,"indexName", "indexValue","This is %s\n", std::string("test") );
}



