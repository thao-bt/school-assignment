#include <iostream>

using namespace std;
class Count
{
private:
static int counter;
int obj_id;
public:
Count();
static void display_total();
void display();
~Count();
};

int Count::counter;
Count::Count()
{
counter++;
obj_id = counter;
}
Count::~Count()
{
counter--;
cout<<"Doi tuong "<<obj_id<<" duoc huy bo\n";
}

void Count::display_total()
{
cout <<"So cac doi tuong duoc tao ra la = "<< counter <<
endl;
}
void Count::display()
{
cout << "Object ID la "<<obj_id<<endl;
}

int main()
{
Count a1;
Count::display_total();
Count a2, a3;
Count::display_total();
a1.display();
a2.display();
a3.display();
}
