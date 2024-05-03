#include <iostream>using namespace std;
using namespace std;

// // Pure virtual function
// class A
// {
// public:
//     virtual void s() = 0; // Pure Virtual Function
// };




// //virtual function
// class Base
// {
// public:
//     virtual void print() { cout << "Base Function" << endl; }
// };
// class Derived : public Base
// {
// public:
//     void print() { cout << "Derived Function" << endl; }
// };
// int main()
// {
//     Derived derived1;        // pointer of Base type that points to derived1
//     Base *base1 = &derived1; // calls member function of Derived class
//     base1->print();
//     return 0;
// }









// // //Abstract Class
// class Base
// {
// public:
//     virtual void s() = 0;
//     // Pure Virtual Function
// };
// class Derived : public Base
// {
// public:
//     void s()
//     {
//         cout << "Virtual Function in Derived_class";
//     }
// };
// int main()
// {
//     Base *b;
//     Derived d_obj;
//     b = &d_obj;
//     b->s();
// }






























// //Friend Function
// class Rectangle
// {
// private:
//     int length;

// public:
//     Rectangle() { length = 10; }
//     friend int printLength(Rectangle);
//     // friend function
// };
// int printLength(Rectangle b)
// {
//     b.length += 10;
//     return b.length;
// }
// int main()
// {
//     Rectangle b;
//     cout << "Length of Rectangle: " << printLength(b) << endl;
//      //Output:Length of Rectangle: 20 
//     return 0;
// }
