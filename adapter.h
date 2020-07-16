#ifndef ADAPTER_H
#define ADAPTER_H
//适配器模式（接口隔离）
/*Movitation
 * 用于实现旧类的复用,应对迁移的变化
 * 将一个类的接口转换为另一个类的接口，使得原本不兼容的接口变得兼容
 * 充电器/转接头
 *
*/
//把 IAdapter 转成 Itarget



//遗留接口
class IAdapter {

public:
    virtual void foo(int a) = 0;
    virtual int bar() = 0;
};

//新接口
class Itarget {

public:
    virtual void process() = 0;
};

class oldclass : public IAdapter {

public:
    oldclass();
public:
    virtual void foo(int a){};
    virtual int bar(){};
};

class Adapter : public Itarget{
protected:
    IAdapter * pIAdapter;
public:
    Adapter(IAdapter * pIAdapter){
        this->pIAdapter = pIAdapter;
    }
    virtual void process(){
        int a = pIAdapter->bar();
        pIAdapter->foo(a);
    }
};

int m(){
    IAdapter *pIAdapter = new oldclass;
    Itarget *pItarget = new Adapter(pIAdapter);
    pItarget->process();
}
#endif // ADAPTER_H
