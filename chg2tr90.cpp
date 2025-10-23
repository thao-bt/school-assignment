# include <iostream>

using namespace std;

class mhang{
    int maso;
    float gia;

    public:
    // Tạo 1 hàm trung gian để truyền giá trị cho 2 biến maso và gia qua biến trung gian a,b
    void Setdata(int a, float b){
        maso = a; gia = b;
    }

    // tạo 1 hàm để tái sử dụng cho từng mặt hàng
    void show(){
        cout <<"\n Ma so: " << maso << endl;
        cout << "Gia: " << gia << endl;
    }
};

main(){

    int k;

    cout<<"\n Nhap tong so mat hang:";
    cin>>k;
    mhang *p = new mhang[k]; // tạo ra 1 mảng và mỗi phần tử là 1 đối tượng của lớp
    mhang *d = p;
    int x,i;
    float y;

    cout<<"\nNhap vao du lieu "<<k<<" mat hang :";

    for (i = 0; i <k; i++){
        cout <<"\n Nhap ma hang va don gia cho mat hang thu " <<i+1;
        cin>>x>>y;
        p -> Setdata(x,y);
        p++;
    }

    for (i = 0; i <k; i++) {
        cout<<"\nMat hang thu: "<<(i+1)<<endl;
        d -> show(); // sử dụng con trỏ thứ hai vì cón trỏ thứ nhất đã trỏ tới đối tượng cuối cùng của lớp ở vòng for trước
        d++;
    }
}
