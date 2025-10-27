#include <iostream>
#include <iomanip>
#include "Registration.cpp"

using namespace std;

const int MAX = 100;

void tachNgay(const string &ngay, int &d, int &m, int &y) {
    if (ngay.size() < 10) { d = m = y = 0; return; }
    d = stoi(ngay.substr(0, 2));
    m = stoi(ngay.substr(3, 2));
    y = stoi(ngay.substr(6, 4));
}

bool truocNgay(const string &ngay1, const string &ngay2) {
    int d1, m1, y1, d2, m2, y2;
    tachNgay(ngay1, d1, m1, y1);
    tachNgay(ngay2, d2, m2, y2);
    if (y1 != y2) return y1 < y2;
    if (m1 != m2) return m1 < m2;
    return d1 < d2;
}


class System {
private:
    Registration danhSach[MAX];
    int soLuong;

public:
    System() { soLuong = 0; }

    void themPhuongTien() {
        if (soLuong >= MAX) {
            cout << "Danh sach da day!\n";
            return;
        }
        Registration r;
        r.nhap();
        danhSach[soLuong++] = r;
        cout << "Them thanh cong!\n";
    }

    void xoaPhuongTien() {
        string bienSo;
        cout << "Nhap bien so xe can xoa: ";
        cin >> bienSo;
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i].getXe().getBienSo() == bienSo) {
                for (int j = i; j < soLuong - 1; j++)
                    danhSach[j] = danhSach[j + 1];
                soLuong--;
                cout << "Da xoa xe co bien so " << bienSo << endl;
                return;
            }
        }
        cout << "Khong tim thay xe nay!\n";
    }

    void suaPhuongTien() {
        string bienSo;
        cout << "Nhap bien so xe can sua: ";
        cin >> bienSo;
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i].getXe().getBienSo() == bienSo) {
                Vehicle v = danhSach[i].getXe();
                v.sua();
                cout << "Da sua thong tin xe " << bienSo << endl;
                return;
            }
        }
        cout << "Khong tim thay xe!\n";
    }

    void traCuuChuSoHuu() {
    string maChu;
    cout << "Nhap ma chu so huu can tra cuu: ";
    cin >> maChu;

    bool found = false;
    Owner chuTimThay;

    // Tìm chủ sở hữu và thu thập thông tin
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].getChu().getMaChu() == maChu) {
            if (!found) {
                chuTimThay = danhSach[i].getChu();
                found = true;
                cout << "\n--- Thong tin chu so huu ---\n";
                chuTimThay.xuat();
                cout << "\n--- Danh sach phuong tien ---\n";
            }
            // Hiển thị thông tin phương tiện
            Vehicle xe = danhSach[i].getXe();
            cout << "Bien so: " << xe.getBienSo()
                 << " | Loai xe: " << xe.getLoaiXe()
                 << " | Hang: " << xe.getHang()
                 << " | Nam san xuat: " << xe.getNamSX() << endl;
        }
    }

    if (!found) {
        cout << "Khong tim thay chu so huu voi ma: " << maChu << endl;
    }
}

    void thongKeTheoLoai() {
        cout << "\n--- Thong ke phuong tien theo loai ---\n";
        string loai[100];
        int dem[100] = {0};
        int count = 0;
        for (int i = 0; i < soLuong; i++) {
            string lx = danhSach[i].getXe().getLoaiXe();
            int found = -1;
            for (int j = 0; j < count; j++)
                if (loai[j] == lx) found = j;
            if (found == -1) {
                loai[count] = lx;
                dem[count++] = 1;
            } else dem[found]++;
        }
        for (int i = 0; i < count; i++)
            cout << "Loai: " << loai[i] << " | So luong: " << dem[i] << endl;
    }

    void thongKeTheoHang() {
        cout << "\n--- Thong ke phuong tien theo hang ---\n";
        string hang[100];
        int dem[100] = {0};
        int count = 0;
        for (int i = 0; i < soLuong; i++) {
            string h = danhSach[i].getXe().getHang();
            int found = -1;
            for (int j = 0; j < count; j++)
                if (hang[j] == h) found = j;
            if (found == -1) {
                hang[count] = h;
                dem[count++] = 1;
            } else dem[found]++;
        }
        for (int i = 0; i < count; i++)
            cout << "Hang: " << hang[i] << " | So luong: " << dem[i] << endl;
    }

    void quanLyDangKiem() {
        string bienSo;
        cout << "Nhap bien so xe can xem ngay dang kiem, bao duong: ";
        cin >> bienSo;
        for (int i = 0; i < soLuong; i++) {
            if (danhSach[i].getXe().getBienSo() == bienSo) {
                cout << "Ngay dang kiem: " << danhSach[i].getXe().getNgayDangKiem()
                     << " | Ngay bao duong: " << danhSach[i].getXe().getNgayBaoDuong() << endl;
                return;
            }
        }
        cout << "Khong tim thay xe nay!\n";
    }

    void canhBaoHetHanDangKiem() {
        cout << "\n--- Danh sach xe het han dang kiem (trc 01/10/2023) ---\n";
        for (int i = 0; i < soLuong; i++) {
            string ngay = danhSach[i].getXe().getNgayDangKiem();
            if (truocNgay(ngay, "01/10/2023")) {
                danhSach[i].getXe().xuat();
            }
        }
    }

    void menu() {
        int chon;
        do {
            cout << "\n===== MENU =====\n";
            cout << "1. Them phuong tien\n";
            cout << "2. Xoa phuong tien\n";
            cout << "3. Sua phuong tien\n";
            cout << "4. Tra cuu chu so huu\n";
            cout << "5. Thong ke theo loai\n";
            cout << "6. Thong ke theo hang\n";
            cout << "7. Quan ly dang kiem, bao duong\n";
            cout << "8. Canh bao xe het han dang kiem\n";
            cout << "0. Thoat\n";
            cout << "Chon: ";
            cin >> chon;

            switch (chon) {
                case 1: themPhuongTien(); break;
                case 2: xoaPhuongTien(); break;
                case 3: suaPhuongTien(); break;
                case 4: traCuuChuSoHuu(); break;
                case 5: thongKeTheoLoai(); break;
                case 6: thongKeTheoHang(); break;
                case 7: quanLyDangKiem(); break;
                case 8: canhBaoHetHanDangKiem(); break;
                case 0: cout << "Thoat chuong trinh!\n"; break;
                default: cout << "Lua chon khong hop le!\n";
            }
        } while (chon != 0);
    }
};
