#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
//KHAI BÁO CẤU TRÚC DỮ LIỆU
struct Node {
    string ten;
    bool laThuMuc;
    int cha; // chi so cua node cha
    bool tonTai;
};
// KHAI BÁO BIẾN TOÀN CỤC
Node cay[MAX];
int dem = 0; // so node cua cay và chi so cua node tiep theo

// KHỞI TẠO GỐC
void khoiTao() {
    cay[0] = {"Root", true, -1, true};
    dem = 1;
}

// THÊM THƯ MỤC
void themThuMuc(string cha, string moi) {
    for (int i = 0; i < dem; i++) {
        if (cay[i].ten == cha && cay[i].laThuMuc && cay[i].tonTai) { // tim node cha la thu muc
            //
            cay[dem++] = {moi, true, i, true};
            return;
        }
    }
    cout << "Khong tim thay thu muc cha '" << cha << "' -> Khong the them '" << moi << "'\n";
}
// THÊM TỆP TIN
void themTepTin(string cha, string moi) {
    for (int i = 0; i < dem; i++) {
        if (cay[i].ten == cha && cay[i].laThuMuc && cay[i].tonTai) { //tim node cha la thu muc
            cay[dem++] = {moi, false, i, true};
            return;
        }
    }
    cout << "Khong tim thay thu muc cha '" << cha << "' -> Khong the them '" << moi << "'\n";
}

//IN CÂY THƯ MỤC
void inCay(int chiSo, int muc = 0) { // muc là độ sâu của node, root có độ sâu là 0
    if (!cay[chiSo].tonTai) return;
    for (int i = 0; i < muc; i++) cout << "   "; // lùi 1 ô
    cout << "  [" << (cay[chiSo].laThuMuc ? "Folder" : "File") << "] " << cay[chiSo].ten << endl;

    // duyệt các node con
    for (int i = 0; i < dem; i++) {
        if (cay[i].cha == chiSo && cay[i].tonTai) inCay(i, muc + 1);
    }
}

// TÌM VỊ TRÍ CỦA FILE VÀ THƯ MỤC THEO TÊN
int timChiSo(string ten) {
    for (int i = 0; i < dem; i++)
        if (cay[i].ten == ten && cay[i].tonTai)
            return i;
    // Không tìm thấy trả về -1
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

// XÓA THƯ MỤC VÀ NỘI DUNG BÊN TRONG
void xoaThuMuc(string ten) {
    int idx = timChiSo(ten);
    if (idx == -1 || !cay[idx].laThuMuc || !cay[idx].tonTai) return;

    for (int i = 0; i < dem; i++) {
        if (cay[i].cha == idx && cay[i].tonTai) {
            if (cay[i].laThuMuc)
                xoaThuMuc(cay[i].ten);
            cay[i].tonTai = false;
        }
    }
    cay[idx].tonTai = false;
}

//XÓA TỆP TIN
void xoaTepTin(string ten) {
    int idx = timChiSo(ten);
    if (idx == -1) {
        cout << "Khong tim thay tep tin '" << ten << "'\n";
        return;
    }
    if (cay[idx].laThuMuc) {
        cout << "'" << ten << "' la thu muc, khong the xoa bang ham xoaTepTin!\n";
        return;
    }
    cay[idx].tonTai = false;
    cout << "Da xoa tep tin '" << ten << "' thanh cong.\n";
}

// HÀM MAIN
int main() {
    khoiTao();
    themThuMuc("Root", "Documents");
    themTepTin("Documents", "Resume.docx");
    themThuMuc("Root", "Pictures");
    themTepTin("Pictures", "Photo.jpg");

    themTepTin("Program","Movie.mp4");

    cout << "Da them thu muc va tep tin vao cay thanh cong!\n" << endl;

    cout << "Cay thu muc:\n";
    inCay(0);

    cout << "\n--- Duong dan den tep tin ---\n";
    hienThiDuongDan("Photo.jpg");

    cout << "\n--- Xoa thu muc ---\n";
    xoaThuMuc("Pictures");
    xoaTepTin("Resume.docx");

    cout << "\n Cay thu muc sau khi xoa:\n";
    inCay(0);

    return 0;
}
