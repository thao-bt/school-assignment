#include <iostream>
#include <cstdlib>
#include <conio.h>

/*
using namespace std;

class SN{
    int m,n;
    public :

    void nhap( ) {
    cout<<endl<<"\nNhap hai so nguyen: " ;
    cin>>m>>n ;
    }

    int max(){
        return m>n?m:n;
    }

    void hienthi( ){
        cout<<endl<<"Thanh phan du lieu lon nhat: "<<max()<<endl;}
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
}

*/

#include <iostream>
#include <iomanip>

//chg1tr39

using namespace std;

int main()
{
    int num;
    cout<< "Nhap so hoc sinh: ";
    cin >> num;

    int *total;
    total = new int[num];
    int i,j;

    if (num <=0) {
        cout << "So hsinh phai lon hon 1";
    }

    struct {
        char ht[25];
        int sbd;
        float td;
    }hs[num],temp;

    for (i=0; i<num;i++){
        cout<< "\n thi sinh thu" << i+1;
        cout << "\n Nhap sbd ";
        cin >>hs[i].sbd;
        cout << "\n Nhap tong diem: ";
        cin >>hs[i].td;
    }

    for (i=0;i<num;i++){
        for (j=0;j<num-i-1;j++){
            if (hs[j].td < hs[j+1].td){
                temp = hs[j];
                hs[j] = hs[j+1];
                hs[j+1]= temp;
            }
        }
    }

    cout<< "\n day sau khi sap xep: ";
    for (i=0;i<num;i++){
        cout<<"\n"<< "Hoc sinh" <<hs[i].sbd << setw(15)<<"diem so"<< hs[i].td;
    }

    cout<< " \n Hsinh co diem cao nhat la";
    for (i=0;i<num-1;i++){
        if (hs[i].td =hs[i+1].td){
            cout<<"\n"<< "Hoc sinh" <<hs[i].sbd << setw(15)<<"diem so"<< hs[i].td;
        }
    }


    return 0;
}
