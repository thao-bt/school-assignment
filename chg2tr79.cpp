#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;
class SN{
    int m,n;
    public :
    void nhap( ){
        cout<<endl<<"\nNhap hai so nguyen: " ;
        cin>>m>>n ;
    }

    int max(){
        return m>n?m:n;
    }

    void hienthi(){
        cout<<endl<<"Thanh phan du lieu lon nhat: "<<max()<<endl;
    }

    int getm() {return m;}
    int getn() {return n;}
};

int main (){
    SN ob;
    ob.nhap();
    cout<<endl<<"So nguyen vua nhap la:";
    cout<<ob.getm()<<" - "<<ob.getn();
    ob.hienthi();
    getch();
    return 0;
}
