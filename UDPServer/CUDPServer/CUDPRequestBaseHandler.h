/**
 * Copyright (c) 2016, iwifi (Copyright statement)
 * @brief      业务的基类
 * @author:    zhangxinhao
 * @date:      2016-06-13
 * Revision Description: initial version
 */
#ifndef CUDPREQUESTBASEHANDLER_H
#define CUDPREQUESTBASEHANDLER_H
#include <string>
using UString = std::basic_string<uint8_t>;
class CUDPRequestBaseHandler
{
public:
    CUDPRequestBaseHandler() = default;
    virtual ~CUDPRequestBaseHandler() = default;
    //返回true表示有返回，false无返回
    virtual bool handleRequest(const UString &request , UString &response) = 0;
};

#endif // CUDPREQUESTBASEHANDLER_H
