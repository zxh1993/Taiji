#ifndef CSERVERAPPLICATION_H
#define CSERVERAPPLICATION_H

#include <Poco/Util/ServerApplication.h>

#define DEFAULT_CONG_PATH 				"./etc/conf.json"

namespace Taiji
{

namespace TUtil {

class CServerApplication : public Poco::Util::ServerApplication
{
public:
    typedef std::list<Poco::Util::AbstractConfiguration*> ConfList;

    typedef enum
    {
        SIG_TERM ,			///< 终止信号
        SIG_RELOAD			///< 重新加载配置信号，使用系统　SIGUSR1
    } ESIGNAL;

    CServerApplication();
    ~CServerApplication();

protected:
    virtual void _init() = 0;
    virtual void _start() = 0;
    virtual void _stop() = 0;


    ////////////////////////////////////////////////////框架需要的函数/////////////////////////////////////////////////////////////
    /**
     * @brief 程序的初始化部分,继承于 Application 类
     * @param [in] self
     */
    void initialize(Application &self);


    /**
     *@brief 程序的反初始化部分,继承于 Application 类
     */
    void uninitialize();

    /**
     *@brief 业务的的启动函数, 继承于 Application 类。
     */
    int main(const ArgVec&);

    void defineOptions(Poco::Util::OptionSet &options);

    ////////////////////////////////////////////////////自定义函数//////////////////////////////////////////////////////////////////

    bool _addConfig(const std::string &path, ConfigPriority priority);

    ESIGNAL _waitForSignal();

    virtual void _version(const std::string &, const std::string &);

    virtual void _handleHelp(const std::string &, const std::string &);

    virtual void _stopProcess(const std::string &, const std::string &);

    ConfList _cfgList;													///< 存放所有的日志对象地址
    bool _helpRequested;												///< 是否是帮助指令
};


}
}
#endif // CSERVERAPPLICATION_H
