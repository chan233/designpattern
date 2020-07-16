#ifndef PROXY_H
#define PROXY_H
//代理模式
/*Motivation
 * 使用接口进行隔离 控制对象的访问
 * 增加一层间接层 是软件系统中对许多复杂问题的常用解决方法
 * webservice 生成工具
 */
class Isubject{

public:
    virtual void process();
};
class subjectProxy: public Isubject{

public:
    virtual void process(){
        //实现对realsubject的间接访问
    }
};

class client{

public:
    Isubject *sb;
    client(){
        sb = new subjectProxy();
    }
    void Dotask()
    {
        sb->process();
    }
};

#endif // PROXY_H
