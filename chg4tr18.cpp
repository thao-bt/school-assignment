#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
class A{
    float x,y;
    public:
        void set(float x1, float y1) { x = x1; y = y1;}
        float getx() { return x; }
        float gety() { return y; }
};

class B : virtual public A{

};
class C : virtual public A{

};
class D : public B, public C{

};

main(){
    D d;
    cout<<endl<<"d.B::set(2,3)\n"; d.B::set(2,3);
    cout<<endl<<"d.C::getx() = "; cout<<d.C::getx();
    cout<<endl<<"d.B::getx() = "; cout<<d.B::getx();
    cout<<endl<<"d.C::gety() = "; cout<<d.C::gety();
    cout<<endl<<"d.B::gety() = "; cout<<d.B::gety();

    cout<<endl<<"d.C::set(2,3)"; d.C::set(2,3);
    cout<<endl<<"d.C::getx() = "; cout<<d.C::getx();
    cout<<endl<<"d.B::getx() = "; cout<<d.B::getx();
    cout<<endl<<"d.C::gety() = "; cout<<d.C::gety();
    cout<<endl<<"d.B::gety() = "; cout<<d.B::gety();
}
