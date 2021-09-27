# include <iostream>
# include <vector>

using namespace std;

void func1();
void vectorPrinter(vector <int> &v);

// p197-p203, stl vector
int main() {

    cout << "stl vector" << endl;

    /*
        stl vector
        
        1.  constructor
            1.  vector<T> v;                    // default constructor
            2.  vector(v.begin(), v.end());     // copy [v.begin(), v.end()), closed-open range
            3.  vector(n, element);             // construct n * element
            4.  vector(const vector &vec);      // copy constructor
        2.  assignment
            1.  vector& operator=(const vector &vec);   // overload =
            2.  assign(begin, end);                     // assign [v.begin(), v.end()), closed-open range
            3.  assign(n, element);                     // assign n * element
        3.  capacity & size
            1.  empty();                        // is empty?
            2.  capacity();                     // max size
            3.  size();                         // current size
            4.  resize(int n);                  // resize capacity into n, delete the oversized element at the end or fill with default value
            5.  resize(int n, element);         // resize capacity into n, delete the oversized element at the end or fill with given value element
    */

    func1();

    //system("pause");    // use it in windows, effect [press any key to continue], no such command in linux/mac

    return 0;
}

void func1() {
    // constructor
    vector<int> v1;                                                     // default constructor
    for (int i = 0; i < 10; i++) v1.push_back(i);   vectorPrinter(v1);
    vector<int> v2(v1.begin(), v1.end());           vectorPrinter(v2);  // copy [v.begin(), v.end()), closed-open range
    vector<int> v3(10, 1);                          vectorPrinter(v3);  // construct n * element
    vector<int> v4(v3);                             vectorPrinter(v4);  // copy constructor

    // assignment
    vector<int> v5 = v1;                                vectorPrinter(v5);  // overload =
    vector<int> v6; v6.assign(v5.begin(), v5.end());    vectorPrinter(v6);  // assign [v.begin(), v.end()), closed-open range
    vector<int> v7; v7.assign(10, 1);                   vectorPrinter(v7);  // assign n * element

    // capacity & size
    vector<int> v8 = v1; 
    cout << v8.empty() << endl;
    cout << v8.capacity() << " " << v8.size() << ": "; vectorPrinter(v8);
    v8.resize(20); cout << v8.capacity() << " " << v8.size() << ": "; vectorPrinter(v8);    // expansion with default int value 0
    v8.resize(14); cout << v8.capacity() << " " << v8.size() << ": "; vectorPrinter(v8);    // shrinking and delete the oversized element at the end
    v8.resize(18, 3); cout << v8.capacity() << " " << v8.size() << ": "; vectorPrinter(v8); // expansion with given int value 1
}

void vectorPrinter(vector <int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}
