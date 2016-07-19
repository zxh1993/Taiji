#include "CApplication.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

#include <Poco/Exception.h>
#include "Poco/Util/JSONConfiguration.h"
#include <Poco/Util/HelpFormatter.h>

using Poco::Util::LayeredConfiguration;
using Poco::Util::AbstractConfiguration;
using Poco::Util::OptionCallback;
using Poco::Util::Option;
using std::string;
using namespace Taiji::TUtil;


CApplication::CApplication()
    :_helpRequested(false)
{

}

CApplication::~CApplication()
{

}

void CApplication::initialize(Application &self)
{
    try
    {
        ServerApplication::initialize(self);
        if ( _helpRequested )
        {
            return;
        }

        if( !_addConfig(DEFAULT_CONG_PATH, PRIO_APPLICATION))
        {
            exit(Application::EXIT_CONFIG);
        }

        init();


    }catch( Poco::Exception& e )
    {
        std::cerr << "Init Failed:  " << e.displayText() << std::endl;
        exit (Application::EXIT_CONFIG);
    }
    catch( std::exception& e )
    {
        std::cerr << "Init Failed:  " << e.what() << std::endl;
        exit (Application::EXIT_CONFIG);
    }
}



void CApplication::defineOptions(Poco::Util::OptionSet &options)
{
    ServerApplication::defineOptions(options);

    options.addOption(Option("help", "h","Display help information on command line arguments")
                      .required(false).repeatable(false)
                      .callback(OptionCallback<CApplication>(this, &CApplication::_handleHelp)));

    options.addOption(Option("version", "v", "Display application version")
                      .required(false).repeatable(false)
                      .callback(OptionCallback<CApplication>(this, &CApplication::_version)));

    options.addOption(Option("stop", "s", "Stop server")
                      .required(false).repeatable(false)
                      .callback(OptionCallback<CApplication>(this, &CApplication::_stopProcess)));

}




int CApplication::main(const Poco::Util::Application::ArgVec &)
{
    if ( _helpRequested )
    {
        return 0;
    }

    start();
    while (true)
    {
        ESIGNAL sig = _waitForSignal();
        if ( SIG_RELOAD != sig )
        {
            break;
        }
    }
    stop();

    return Application::EXIT_OK;
}



void CApplication::uninitialize()
{
    if ( _helpRequested )
    {
        return;
    }

}


bool CApplication::_addConfig( const std::string& path, enum  ConfigPriority priority  )
{
    Poco::Path confPath( path );
    string ext = confPath.getExtension();
    if ( ext != "json" )
    {
        return false;
    }

    AbstractConfiguration* pCnf = new Poco::Util::JSONConfiguration(confPath.toString());
    // 设置为不共享的话不需要 delete
    config().add(pCnf, priority, false, false);
    _cfgList.push_back(pCnf);
    return true;
}


CApplication::ESIGNAL CApplication::_waitForSignal()
{
    sigset_t sset;
    sigemptyset(&sset);

    sigaddset(&sset, SIGINT);
    sigaddset(&sset, SIGQUIT);
    sigaddset(&sset, SIGTERM);
    sigaddset(&sset, SIGUSR1 );

    sigprocmask(SIG_BLOCK, &sset, NULL);
    int sig;
    sigwait(&sset, &sig);

    if ( sig == SIGINT || sig == SIGQUIT || sig == SIGTERM )
    {
        return SIG_TERM;
    }else
    {
        return SIG_RELOAD;
    }
}



void CApplication::_version(const std::string&, const std::string&)
{
    _helpRequested = true;
    stopOptionsProcessing();
}


void CApplication::_handleHelp(const std::string& , const std::string &)
{
    _helpRequested = true;
    Poco::Util::HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("");
    helpFormatter.setHeader("====================================");
    helpFormatter.format(std::cout);
    stopOptionsProcessing();
}

void CApplication::_stopProcess(const string &, const string &)
{
     stopOptionsProcessing();
}


