#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class hinhhoc{
    int ma;
    string ten;
    float dientich;
    public:

        static int tshinh;

        hinhhoc() {
            tshinh++;
        }

        ~hinhhoc(){
            tshinh--;
        }

        static void ints(){
            cout<<endl<<"Tong so hinh la: "<<tshinh;
        }

        void nhap(){
            cout<<"Nhap ma hinh";cin>>ma;
            cout<<endl<<"Nhap ten hinh"; cin.ignore(); getline(cin,ten);
            cout<<endl<<"Nhap dien tich"; cin>>dientich;
        }


        void in(){
            cout<<setw(5)<<ma<<setw(20)<<ten<<setw(10)<<dientich;
        }

        hinhoc *next;
};

int hinhhoc::tshinh=0;

int main(){

    hinhhoc::ints();

    hinhhoc *dau=NULL, *cuoi=NULL, *node=NULL;
    char tiep = 'c';
    while (tiep =='c'){
        node = new hinhoc();
        node->nhap();
        node->next=NULL;


        if (dau==NULL){
            dau = cuoi; cuoi = node;}
        else{
            cuoi->next=node;
            cuoi = node;
        }
        cout<<endl<<"Co nhap hinh tiep khong(c: tiep)"; cin>>tiep;
    }

    cout<<endl<<"Danh sach hinh vua tao: ";
    hinhoc *duyet = dau;
    while(duyet!=NULL){
        duyet->in();
        duyet=duyet->next;
    }

    hinhhoc::ints();
}
