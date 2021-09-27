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
        4.  insert & delete
            1.  push_back(e);                                       // add element e at the end
            2.  pop_back();                                         // delete the last element
            3.  insert(const_iterator p, e)                         // insert element e at position p
            4.  insert(const_iterator p, int n, e);                 // insert n * element e at position p
            5.  erase(const_iterator p);                            // delete element where iterator points
            6.  erase(const_iterator start, const_iterator end);    // delete elements from start to end
            7.  clear();                                            // delete all
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

    // insert & delete
    vector<int> v9 = v1;
    v9.push_back(999); vectorPrinter(v9);               // add element e at the end
    v9.pop_back(); vectorPrinter(v9);                   // delete the last element
    v9.insert(v9.begin(), 999); vectorPrinter(v9);      // insert element e at position p
    v9.insert(v9.begin(), 2, 999); vectorPrinter(v9);   // insert n * element e at position p
    v9.erase(v9.begin()); vectorPrinter(v9);            // delete element where iterator points
    v9.erase(v9.begin(), v9.end()); vectorPrinter(v9);  // delete elements from start to end
    v9.clear(); vectorPrinter(v9);                      // delete all

    
}

void vectorPrinter(vector <int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}
