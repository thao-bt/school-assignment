#include <iostream>
using namespace std;

class Father{
     public:
     void area(){
        cout << "This is Father!" <<endl;
    }
};

class Son: public Father{
 public:
     void area (){
        cout << "This is Son!" <<endl;
     }
};

 class Daughter: public Father{
     public:
        void area (){
            cout << "This is Daughter!" <<endl;
        }
 };

int main( ){
     Father *fa;
     Son son;
     Daughter dau;
     fa = &son; // lưu trữ địa chỉ của son
     fa->area(); // gọi hàm area() của son fa = &dau; // lưu trữ địa chỉ của dau
     fa->area(); // gọi hàm area của daughter

     return 0;
}
