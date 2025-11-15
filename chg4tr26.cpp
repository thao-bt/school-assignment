#include <iostream>
2. #include <string>
3. using namespace std;
4. template <typename T>
5. inline T const& Max (T const& a, T const& b)
6. { return a < b ? b:a; }
7. int main ()
8. {
9. int i = 39; int j = 20;
10. cout << "Max(i, j): " << Max(i, j) << endl;
11. double f1 = 13.5; double f2 = 20.7;
12. cout << "Max(f1, f2): " << Max(f1, f2) << endl;
13. string s1 = "Hello"; string s2 = "World";
14. cout << "Max(s1, s2): " << Max(s1, s2) << endl;
15. return 0;
16. }
