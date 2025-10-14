#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Node {
    string ten;
    bool laThuMuc;
    int cha;
    bool tonTai;
};

Node cay[MAX];
int dem = 0;

// Initialize root
void khoiTao() {
    cay[0] = {"Root", true, -1, true};
    dem = 1;
}

// Add folder
void themThuMuc(string cha, string moi) {
    for (int i = 0; i < dem; i++) {
        if (cay[i].ten == cha && cay[i].laThuMuc && cay[i].tonTai) {
            cay[dem++] = {moi, true, i, true}; // for folder
            return;
        }
    }
}

// Add file
void themTepTin(string cha, string moi) {
    for (int i = 0; i < dem; i++) {
        if (cay[i].ten == cha && cay[i].laThuMuc && cay[i].tonTai) {
            cay[dem++] = {moi, false, i, true}; // for file
            return;
        }
    }
}

// Print folder hierarchy (recursive)
void inCay(int chiSo, int muc = 0) {
    if (!cay[chiSo].tonTai) return;
    for (int i = 0; i < muc; i++) cout << "   ";
    cout << "|- [" << (cay[chiSo].laThuMuc ? "Folder" : "File") << "] " << cay[chiSo].ten << endl;
    for (int i = 0; i < dem; i++) {
        if (cay[i].cha == chiSo && cay[i].tonTai) inCay(i, muc + 1);
    }
}

// Find index by name
int timChiSo(string ten) {
    for (int i = 0; i < dem; i++)
        if (cay[i].ten == ten && cay[i].tonTai)
            return i;
    return -1;
}

// Delete folder and its contents
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

// Show full path to a file
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

int main() {
    khoiTao();
    themThuMuc("Root", "Documents");
    themTepTin("Documents", "Resume.docx");
    themThuMuc("Root", "Pictures");
    themTepTin("Pictures", "Photo.jpg");

    cout << "Disk Hierarchy:\n";
    inCay(0);

    cout << "\n--- Duong dan den tep tin ---\n";
    hienThiDuongDan("Photo.jpg");

    cout << "\n--- Xoa thu muc ---\n";
    xoaThuMuc("Pictures");

    cout << "\nDisk Hierarchy sau khi xoa:\n";
    inCay(0);

    return 0;
}
