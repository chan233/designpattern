#ifndef COMPOSITE_H
#define COMPOSITE_H
#include <list>
#include <algorithm>
#include <QList>
class component{
public:
    virtual void process() = 0;
    virtual ~component();
};

component * finder(){


}
class root : public component{

    component *cs;
    std::list<component *> vecComp;
public:

    void add(component *cs){

        vecComp.push_back(cs);

    }
    void remove(component *cs){
        vecComp.remove(cs);
    }
    void find(component *cs){
        std::find(vecComp.begin(),vecComp.end(),cs);

        std::find_if(vecComp.begin(),vecComp.end(),[cs](component *n){return cs == n;});




    }
     void process() override
     {
        for(auto &c : vecComp){

         c->process();

        }
     }


};

class leaf : public component{


public:
    void process() override{
        //do sth
    }

};
void mainprocess(component &c){

    c.process();
}
int mainx(){
    root a;
    root b;
    root c;
    leaf d;
    leaf e;
    leaf g;

    a.add(&b);
    a.add(&c);

    b.add(&d);
    c.add(&e);
    c.add(&g);
    mainprocess(a);

    return 0;
    QList<int> ql;

}
#endif // COMPOSITE_H
