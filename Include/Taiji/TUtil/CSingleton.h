#ifndef CSINGLETON
#define CSINGLETON
namespace Taiji
{

namespace TUtil {


template<typename T, int index = 0>
class CSingleton
{
public:
    CSingleton() = delete;
    CSingleton(const CSingleton &) = delete;
    CSingleton & operator =(const CSingleton &) = delete;
    static T& instance()
    {
        static T x;
        return x;
    }
};


}
}

#endif // CSINGLETON

