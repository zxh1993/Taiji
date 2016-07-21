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

#ifndef CUTILTEST_H
#define CUTILTEST_H
#include "Taiji/TUtil/CLogs.h"
#include "Taiji/TUtil/CSingleton.h"

#include <gtest/gtest.h>


class CUtilTest : public testing::Test
{
public:
    CUtilTest() = default;
    ~CUtilTest() = default;


    static void SetUpTestCase( void );
    static void TearDownTestCase( void );

};

#endif // CUTILTEST_H
