#include <iostream>
#include <string>
#include "Vehicle.cpp"
#include "Owner.cpp"
using namespace std;

class Registration {
private:
    string maDK;
    Vehicle xe;
    Owner chu;

public:
    Registration() {}
    Registration(string md, Vehicle v, Owner o)
        : maDK(md), xe(v), chu(o) {}

    void nhap() {
        cout << "Nhap ma dang ky: ";
        cin >> maDK;
        cout << "--- Nhap thong tin chu so huu ---\n";
        chu.nhap();
        cout << "--- Nhap thong tin phuong tien ---\n";
        xe.nhap();
    }

    void xuat() const {
        cout << "Ma DK: " << maDK << endl;
        chu.xuat();
        xe.xuat();
    }

    Vehicle getXe() const { return xe; }
    Owner getChu() const { return chu; }
};
