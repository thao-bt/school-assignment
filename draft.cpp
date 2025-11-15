#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class nguoi {
protected:
    string maso, hoten;
    float luong;
public:

    nguoi(string maso,string hoten,float luong){
        this->maso=maso;
        this->hoten=hoten;
        this->luong=luong;
    }

    ~nguoi(){};


    float getLuong() { return luong; }

    void nhap() {
        cout << endl << "Nhap ma nhan vien (b: bienche, h: hopdong): ";
        cin.ignore();
        getline(cin, maso);
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
    }

    string getMaSo() { return maso; }

    void in() {
        cout << setw(8) << maso << setw(25) << hoten << setw(12) << luong;
    }
};

class bienche : virtual public nguoi {
protected:
    float hsl, phucap;
public:
    void nhap_bc() {
        cout << "Nhap he so luong: "; cin >> hsl;
        cout << "Nhap phu cap: "; cin >> phucap;
        luong = hsl * 10 + phucap;
    }
};

class hopdong : virtual public nguoi {
protected:
    float ngaycong, tiencong, hsvg;
public:
    void nhap_hd() {
        cout << "Nhap so ngay cong lao dong: "; cin >> ngaycong;
        cout << "Nhap so tien cong 1 ngay: "; cin >> tiencong;
        cout << "Nhap he so vuot gio: "; cin >> hsvg;
        luong = tiencong * (ngaycong <= 26 ? ngaycong : (26 + (ngaycong - 26) * hsvg));
    }
};

class vienchuc : public bienche, public hopdong {
public:
    void nhap_vc() {
        nhap();
        if (maso[0] == 'b') nhap_bc();
        else if (maso[0] == 'h') nhap_hd();
        else cout << " Ma nhan vien khong hop le! Nhan vien nay se bi loai bo.\n";
    }

    bool maHopLe() {
        return (maso[0] == 'b' || maso[0] == 'h');
    }

    bool operator<(vienchuc v2) {
        return this->luong < v2.luong;
    }

    static int tsvc;
    static float tsluong;
    static void intong() {
        cout << endl << "Tong so vien chuc: " << tsvc << ", Tong so luong: " << tsluong;
    }
};

int vienchuc::tsvc = 0;
float vienchuc::tsluong = 0;

int main() {
    int n;
    cout << "Nhap so vien chuc: ";
    cin >> n;

    vienchuc *v = new vienchuc[n];
    int dem = 0; // đếm số nhân viên hợp lệ

    cout << endl << "=== NHAP DANH SACH VIEN CHUC ===\n";
    for (int i = 0; i < n; i++) {
        cout << endl << "Nhap vien chuc thu " << i + 1 << ":\n";
        v[i].nhap_vc();

        // ✅ Chỉ giữ lại nếu mã hợp lệ
        if (v[i].maHopLe()) {
            vienchuc::tsvc++;
            vienchuc::tsluong += v[i].getLuong();
            dem++;
        }
    }

    if (dem == 0) {
        cout << "\nKhong co vien chuc hop le nao duoc nhap.\n";
        return 0;
    }

    // Sắp xếp theo lương giảm dần
    for (int i = 0; i < dem - 1; i++) {
        for (int j = i + 1; j < dem; j++) {
            if (v[i] < v[j]) {
                vienchuc tg = v[i];
                v[i] = v[j];
                v[j] = tg;
            }
        }
    }

    cout << endl << "=== DANH SACH VIEN CHUC HOP LE ===\n";
    for (int i = 0; i < dem; i++) {
        cout << setw(3) << i + 1 << ". ";
        v[i].in();
        cout << endl;
    }

    vienchuc::intong();

    cout << endl << "\nNhan vien co tien luong cao nhat:\n";
    float maxLuong = v[0].getLuong();
    for (int i = 0; i < dem; i++) {
        if (v[i].getLuong() == maxLuong) {
            cout << setw(3) << i + 1 << ". ";
            v[i].in();
            cout << endl;
        }
    }

    delete[] v;
    return 0;
}
