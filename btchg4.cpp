#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class nguoi{
    protected:
        string maso,hoten;
        float luong;
    public:

        nguoi() {};


        nguoi(string maso,string hoten,float luong){
            this->maso=maso;
            this->hoten=hoten;
            this->luong=luong;
        }

        ~nguoi(){};



        float getLuong(){
            return luong;
        }

        void nhap(){
            cout<<endl<<"Nhap ma nhan vien(b: bienche, h:hopdong): ";
            cin.ignore();
            getline(cin, maso);
            cout<<endl<<"Nhap ho ten: "; getline(cin,hoten);
        }

        void in() {
            cout<<setw(8)<<maso<<setw(25)<<hoten<<setw(12)<<luong;
        }


};

class bienche: virtual public nguoi{
    protected:
        float hsl, phucap;
    public:
        void nhap_bc() {
            cout<<endl<<"Nhap he so luong: "; cin>> hsl;
            cout<<endl<<"Nhap phu cap: "; cin>> phucap;
            luong = hsl*10 + phucap;
        }
};

class hopdong: public virtual nguoi{
    protected:
        float ngaycong, tiencong, hsvg;
    public:
        void nhap_hd() {
            cout<<endl<<"Nhap so ngay cong lao dong: "; cin>>ngaycong;
            cout<<endl<<"Nhap so tien cong 1 ngay: "; cin>> tiencong;
            cout<<endl<<"Nhap he so vuot gio: "; cin>> hsvg;
            luong = tiencong*(ngaycong<=26 ? ngaycong : (26+(ngaycong-26)*hsvg));
        }
};

class vienchuc: public bienche, public hopdong {
public:
    void nhap_vc(){
        nhap();// ke thua tu lop nguoi
        if(maso[0]=='b'){
            nhap_bc();
            vienchuc::tsvc++; // Đếm số nhân viên khi nhập
            vienchuc::tsluong += luong; // Cộng dồn tổng lương
        }else if(maso[0]=='h'){
            nhap_hd();
            vienchuc::tsvc++; // Đếm số nhân viên khi nhập
            vienchuc::tsluong += luong; // Cộng dồn tổng lương
        }else{
            cout<<"Ma phong khong hop le";
        }
    }

    bool operator<(vienchuc v2){ //v1 la tham so an
        return(this->luong<v2.luong);
    }

    static int tsvc;
    static float tsluong;
    static void intong(){
        cout<<endl<<"Tong so vien chuc: "<<tsvc<<", Tong so luong: "<<tsluong;
    }
};

int vienchuc::tsvc =0;
float vienchuc::tsluong=0;


int main() {
    int n;
    cout<<endl<<"Nhap so vien chuc: "; cin>>n;
    vienchuc *v = new vienchuc[n];
    cout<<endl<<"Nhap danh sach vien chuc: ";
    for(int i=0;i<n;i++) {
        cout<<endl<<"Nhap vien chuc thu "<<i+1;
        v[i].nhap_vc(); //truy cap tu gan den xa nen co the viet la nhap
    }

    cout<<endl<<"Danh sach vien chuc vua nhap";
    for(int i=0;i<n;i++) {
        cout<<endl<<setw(5)<<i+1<<".";
        v[i].in();
    }

    //Sap xep theo luong
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(v[i]<v[j]){
                vienchuc tg =v[i];
                v[i]=v[j];
                v[j]=tg;
            }
        }
    }

    cout<<endl<<"Dach sach theo thu tu giam dan cua luong";
    for(int i=0;i<n;i++) {
        cout<<endl<<setw(5)<<i+1<<". ";
        v[i].in();
    }

    cout<<endl;
    vienchuc::intong();

    cout<<endl<<"Nhan vien co tien luong cao nhat";


    for(int i=0;i<n;i++) {
        if (v[i].getLuong() == v[0].getLuong()){
            cout<<endl<<setw(5)<<i+1<<". ";
            v[i].in();
        }
    }
}


