#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
//KHAI BÁO CẤU TRÚC DỮ LIỆU
struct Node {
    string ten;
    bool laThuMuc;
    int cha;
};
// KHAI BÁO BIẾN TOÀN CỤC
Node cay[MAX];
int dem = 0;

// KHỞI TẠO GỐC
void khoiTao() {
    cay[0] = {"Root", true, -1};
    dem = 1;
}

// THÊM THƯ MỤC
void themThuMuc(string cha, string moi) {
    for (int i = 0; i < dem; i++) {
        if (cay[i].ten == cha && cay[i].laThuMuc) {
            cay[dem++] = {moi, true, i};
            return;
        }
    }
    cout << "Khong tim thay thu muc cha '" << cha << "' -> Khong the them '" << moi << "'\n";
}
// THÊM TỆP TIN
void themTepTin(string cha, string moi) {
    for (int i = 0; i < dem; i++) {
        if (cay[i].ten == cha && cay[i].laThuMuc) {
            cay[dem++] = {moi, false, i};
            return;
        }
    }
    cout << "Khong tim thay thu muc cha '" << cha << "' -> Khong the them '" << moi << "'\n";
}

//IN CÂY THƯ MỤC
void inCay(int chiSo, int muc = 0) {
    for (int i = 0; i < muc; i++) cout << "   ";
    cout << "  [" << (cay[chiSo].laThuMuc ? "Folder" : "File") << "] " << cay[chiSo].ten << endl;
    for (int i = 0; i < dem; i++) {
        if (cay[i].cha == chiSo ) inCay(i, muc + 1);
    }
}

// TÌM VỊ TRÍ CỦA FILE VÀ THƯ MỤC THEO TÊN
int timChiSo(string ten) {
    for (int i = 0; i < dem; i++)
        if (cay[i].ten == ten)
            return i;
    return -1;
}

// HIỆN THỊ ĐƯỜNG DẪN CỦA FILE VÀ THƯ MỤC
void hienThiDuongDan(string ten) {
    int idx = timChiSo(ten);
    if (idx == -1) {
        cout << "Khong tim thay tep tin " << ten << endl;
        return;
    }
    string duongDan = cay[idx].ten;
    while (cay[idx].cha != -1) {
        idx = cay[idx].cha;
        duongDan = cay[idx].ten + "/" + duongDan;
    }
    cout << "Duong dan: " << duongDan << endl;
}

// XÓA THƯ MỤC/ TỆP TIN VÀ NỘI DUNG BÊN TRONG
//Xóa file/folder
void xoaNodeTaiViTri(int viTriXoa) {
    if (viTriXoa < 0 || viTriXoa >= dem) return;
    for (int i = viTriXoa; i < dem - 1; i++) {
        cay[i] = cay[i + 1];
    }
    dem--;
    for (int i = 0; i < dem; i++) {
        if (cay[i].cha > viTriXoa)
            cay[i].cha--;
    }
}


//Xóa con của folder (nếu có)
void xoaNode(int idx) {
    if (idx < 0 || idx >= dem) return;
    for (int i = dem - 1; i >= 0; i--) {
        if (cay[i].cha == idx) {
            xoaNode(i);
        }
    }
    // Sau khi các con được xóa hết thì xóa folder đó
    xoaNodeTaiViTri(idx);
}

//Tìm chỉ số của file/folder cần xóa
void xoaVinhVien(string ten) {
    int idx = timChiSo(ten);
    if (idx == -1) {
        cout << "Khong tim thay '" << ten << "' de xoa.\n";
        return;
    }
    // Bắt đầu xóa file/folder
    xoaNode(idx);
}

// HÀM MAIN
int main() {
    khoiTao();
    themThuMuc("Root", "Documents");
    themTepTin("Documents", "Resume.docx");
    themThuMuc("Documents", "Works.docx");

    themThuMuc("Root", "Pictures");
    themTepTin("Pictures", "Photo.jpg");
    themTepTin("Program","Movie.mp4");

    cout << "Da them thu muc va tep tin vao cay thanh cong!\n" << endl;

    cout << "Cay thu muc:\n";
    inCay(0);

    cout << "\n--- Duong dan den tep tin ---\n";
    hienThiDuongDan("Photo.jpg");

    cout << "\n--- Xoa vinh vien thu muc ---\n";
    xoaVinhVien("Pictures");

    cout << "Da xoa vinh vien thu muc 'Pictures' va noi dung ben trong.\n";
    cout << "\nCay thu muc sau khi xoa:\n";
    inCay(0);

    return 0;
}


