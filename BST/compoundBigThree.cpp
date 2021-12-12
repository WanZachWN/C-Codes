#include <iostream>

using namespace std;

class MyClass {
public:
  MyClass (string s_in) : s(s_in) {
    cout << "MyClass ctor " << s
         << endl;
  }

  ~MyClass ()
  {cout << "MyClass dtor " << s << endl;}
  
  MyClass (const MyClass& other) : s(other.s) {
    cout << "MyClass copy ctor " << s
         << endl;
  }
  
  const MyClass& operator = (const MyClass& other) {
    cout << "MyClass assign " << other.s << " to be "
         << s << endl;
    return *this;
  }

private:
  string s;
};

//----------------------------------------------------------
void func(MyClass &x,
          MyClass y) {
  MyClass z = x;
}

//----------------------------------------------------------

int main() {
  MyClass a("apple");
  MyClass b("pineapple");
  MyClass c("pen");
  
  func(a, b);

  // Careful!
  MyClass c2 = c;
  c2 = c;
  return 0;
}

