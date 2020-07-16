#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H
#include <string>
#include <map>
//享元模式
/*Motivation
 * 应对大量细粒度对象创建的开销问题
 * 运用共享的技术有效支持大量细粒度的对象
 * 例如 线程池
*/
class font{
private:
    std::string str;
public:
    font();
};

class fontfactory{
private:
    std::map<std::string,font*> pool;
public:
    font* get(std::string str){

        auto it = pool.find(str);
        if(it != pool.end())
        {
            return pool[str];
        }
        else{
            pool[str] = new font;
            return pool[str];
        }
    }

};

#endif // FLYWEIGHT_H
