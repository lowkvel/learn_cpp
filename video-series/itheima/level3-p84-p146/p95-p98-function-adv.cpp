#include <iostream>

using namespace std;

void func1(int a, int b, int c);
//void func2(int a, int b, int c);
//void func3(int a, int b = 10, int c = 10);
void func4(int a, int b = 10, int c = 10);

void func5(int a, int);
void func6(int a, int);

void func7(int a);
void func7(double a, int b);
//void func7(int a, int b);
//void func7(int &a);
//void func7(const int &a);

// p95-p98, function adv
int main() {

    cout << "function adv" << endl;

    /*
        function adv

        default argument of parameter
            1.  void func(int a, int b, int c);
                void func(int a, int b = 10, int c = 10){   // all parameters [b, c] after the first parameter [b] with default argument requires default arguments 
                    ...
                }
            2.  void func(int a, int b = 10, int c = 10);
                void func(int a, int b, int c){             // do not redefine default argument defined in declaration
                    ...
                }

        placeholder parameter
            1.  void func1(int a, int);
                void func1(int a, int) {
                    ...
                }
                func1(10, 10);
            2.  void func1(int a, int);
                void func2(int a, int = 10) {               // weird
                    ...
                }
                func2(10, 10);

        function overload:  same function name, but different parameter set [type, number, sequence]

    */

    // default argument of parameter
    //func1(10);          // ?
    func1(10, 20, 30);  // default argument overload
    func4(10, 20, 30);

    // placeholder parameter
    func5(10, 10);      // have to fill a value for placeholder parameter
    func6(10, 10);

    // function overload
    int a = 10;
    double b = 10.01;
    func7(a);
    func7(b, a);

    //system("pause");    // use it in windows, effect [press any key to continue], no such command in linux/mac

    return 0;
}

void func1(int a, int b = 10, int c = 10) {
    cout << (a + b + c) << endl;
}

/*
// starting from b, all parameters need default argument
void func2(int a, int b = 10, int c) {
    cout << (a + b + c) << endl;
}
*/

/*
// cannot redefine default arguments defined in declaration
void func3(int a, int b = 10, int c = 10) {
    cout << (a + b + c) << endl;
}
*/

void func4(int a, int b, int c) {
    cout << (a + b + c) << endl;
}

void func5(int a, int) {
    cout << "why do we need placeholder parameter? idk." << endl;
}

void func6(int a, int = 10) {
    cout << "placeholder parameter with default argument? weird." << endl;
}

void func7(int a) {
    cout << a << endl;
}

void func7(double a, int b) {
    cout << a << " " << b << endl;
}

/*
void func7(int a, int b = 10) {
    cout << a << " " << b << endl;
}
*/

/*
void func7(int &a) {
    cout << a << endl;
}
*/

/*
void func7(const int &a) {
    cout << a << endl;
}
*/