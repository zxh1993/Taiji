/**
* Copyright (c) 2015, 爱wifi（版权声明）
*
* @file CUtil.cpp
* @brief 通用的类集合
*
* @author: yuhaiyang
* @date: 2015/12/25
*/

#include "CUtil.h"
#include <sstream>
#include <Poco/Data/MySQL/Connector.h>
#include <string>

namespace  Taiji {
namespace TUtil {


CUtil::~CUtil()
{
    __uninitMysql();
    __uninitRedis();
}

CUtil &CUtil::instance()
{
    static CUtil singleton;
    return singleton;
}

void CUtil::createLog(const std::string &dir, const std::string &file, const std::string &name,
                      const std::string &level, const std::string &rotation, const std::string &purgeAge)
{
    std::shared_ptr<CLog> pLog( new CLog( dir, file, name, level, rotation, purgeAge) );
    _logMap.insert( std::pair<std::string,std::shared_ptr<CLog>>( name, pLog ) );
}

CLog &CUtil::getLog(const std::string &logName )
{
    auto itLog = _logMap.find( logName );
    if ( itLog == _logMap.end() )
    {
        throw ExceptNotFindLog("not find Clog object" );
    }
    return *(itLog->second);
}

void CUtil::initMysql( const string& host, uint16_t port, const string& user, const string&pass,
                       const string& db, uint16_t minSession,uint16_t maxSession )
{
    std::stringstream ss;
    ss << port;
    std::string sPort = ss.str();
    std::string connectInfo = "host=" + host + " ; " + "port=" +sPort + " ; "
                    + "user=" + user + " ; " + "password=" +pass + " ; " + "db="
                    + db + " ; " + "auto-reconnect=" + "true";
    //------------------------初始化数据库连接池-------------------------
    Poco::Data::MySQL::Connector::registerConnector();
    _pSessionPool =std::unique_ptr<Poco::Data::SessionPool>( new Poco::Data::SessionPool("MySQL", connectInfo, minSession, maxSession) );
}

Poco::Data::Session CUtil::getMysql( void )
{
    return _pSessionPool->get();
}

void CUtil::__uninitMysql()
{
    if ( _pSessionPool.get() )
    {
        _pSessionPool->shutdown();
        Poco::Data::MySQL::Connector::unregisterConnector();
    }
}

void CUtil::initRedis(const std::string& host, uint16_t port, uint16_t maxSession)
{
    _redisPool.init( host, port, 5, maxSession, 20);
}

void CUtil::__uninitRedis()
{
    _redisPool.closeConnPool();
}

std::shared_ptr<TRedis::CRedisClient> CUtil::getRedis( long millisecond )
{
//    int32_t place = -1;
//     CRedisClient* predis = _redisPool.getConn( place,millisecond );
//     //智能指针的析构器。把 redis 对象 putBack() 回去。
//     auto deleter = [ place,this ]( CRedisClient * pConn )
//     {
//         if( place >= 0 && nullptr != pConn  )
//         {
//             this->_redisPool.pushBackConn( place );
//         }
//     };
//     return std::shared_ptr <CRedisClient>( predis,deleter );
    return _redisPool.getConn(millisecond);
}

}
} //namespace Taiji
