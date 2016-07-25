/**
 * Copyright (c) 2016, 爱wifi（版权声明）
 *
 * @file	Except.h
 * @brief 此文件的简单描述。(必填字段)
 *
 * 此文件的详细功能描述。(可选字段)
 *
 * @author: 		cj
 * @date: 		2016年1月6日
 *
 * 修订说明:初始版本
 */
#ifndef TAIJI_EXCEPT_H_
#define TAIJI_EXCEPT_H_

#include <exception>
#include <string>

#define TAIJI_NEW_EXCEPTION( name,parent ) \
    class name : public parent \
    { \
        public: 	\
            name( const std::string& pErrInfo) \
            : parent( pErrInfo) \
            { \
            } \
            \
            ~name( ) noexcept\
            { \
                \
            }\
    }

namespace Taiji
{



class Except: public std::exception
{
public:
    Except( const std::string &errInfo ) :
        _errInfo(errInfo)
    {

    }

    virtual ~Except( ) noexcept
    {

    }

    virtual const char* what( ) const noexcept
    {
        return _errInfo.c_str();
    }

private:
	std::string _errInfo;
};







////////////////////////////////////基本模块异常///////////////////////////////////
//协议模块的基类异常
TAIJI_NEW_EXCEPTION(ExceptProtocal, Except);
//TUtil模块的基类异常
TAIJI_NEW_EXCEPTION(ExceptTUtil, Except);
//业务模块的基类异常
TAIJI_NEW_EXCEPTION(ExceptBusiness, Except);

/////////////////////////////////////////////////////////////////////////////////

}//namespace Taiji

#endif /* CEXCEPTION_H_ */

