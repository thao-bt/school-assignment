#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string bienSo;
    string loaiXe;
    string hang;
    int namSX;
    string ngayDangKiem;
    string ngayBaoDuong;

public:
    Vehicle() {}
    Vehicle(string bs, string lx, string h, int nsx, string dk, string bd)
        : bienSo(bs), loaiXe(lx), hang(h), namSX(nsx),
          ngayDangKiem(dk), ngayBaoDuong(bd) {}

    void nhap() {
        cout << "Nhap bien so: ";
        cin >> bienSo;
        cin.ignore();
        cout << "Nhap loai xe: ";
        getline(cin, loaiXe);
        cout << "Nhap hang xe: ";
        getline(cin, hang);
        cout << "Nhap nam san xuat: ";
        cin >> namSX;
        cin.ignore();
        cout << "Nhap ngay dang kiem (dd/mm/yyyy): ";
        getline(cin, ngayDangKiem);
        cout << "Nhap ngay bao duong (dd/mm/yyyy): ";
        getline(cin, ngayBaoDuong);
    }

    void xuat() const {
        cout << "Bien so: " << bienSo
             << " | Loai: " << loaiXe
             << " | Hang: " << hang
             << " | Nam SX: " << namSX
             << " | Dang kiem: " << ngayDangKiem
             << " | Bao duong: " << ngayBaoDuong << endl;
    }

    string getBienSo() const { return bienSo; }
    string getLoaiXe() const { return loaiXe; }
    string getHang() const { return hang; }
    int getNamSX() const { return namSX; }
    string getNgayDangKiem() const { return ngayDangKiem; }
    string getNgayBaoDuong() const { return ngayBaoDuong; }

    void sua() {
        cout << "Sua thong tin xe " << bienSo << ":\n";
        cout << "Nhap loai xe moi: ";
        cin.ignore();
        getline(cin, loaiXe);
        cout << "Nhap hang xe moi: ";
        getline(cin, hang);
        cout << "Nhap nam san xuat moi: ";
        cin >> namSX;
        cin.ignore();
        cout << "Nhap ngay dang kiem moi: ";
        getline(cin, ngayDangKiem);
        cout << "Nhap ngay bao duong moi: ";
        getline(cin, ngayBaoDuong);
    }
};
