#include <iostream>
#include "../common/smart_pointer.h"
using namespace std;
int main() {
  int* p1 = new int();
  *p1 = 1111;
  cout << sizeof(p1) << endl;
  int* p2 = new int();
  *p2 = 2222;
  SmartPointer<int> sp1(p1);
  SmartPointer<int> sp2(p2);
  SmartPointer<int> sp3 = sp1;
  sp2 = sp3;
  cout << sp1.GetCount() << "    " << sp2.GetCount() << "   " << sp3.GetCount()
       << endl;
  cout << sp1.GetPointer() << "    " << sp2.GetPointer() << "   "
       << sp3.GetPointer() << endl;
  return 0;
}