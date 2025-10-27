#include <iostream>
#include <string>
using namespace std;

class Owner {
private:
    string maChu;
    string hoTen;
    string diaChi;

public:
    Owner() {}
    Owner(string mc, string ht, string dc)
        : maChu(mc), hoTen(ht), diaChi(dc) {}

    void nhap() {
        cout << "Nhap ma chu so huu: ";
        cin >> maChu;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    void xuat() const {
        cout << "Ma chu: " << maChu
             << " | Ho ten: " << hoTen
             << " | Dia chi: " << diaChi << endl;
    }

    string getMaChu() const { return maChu; }
};
