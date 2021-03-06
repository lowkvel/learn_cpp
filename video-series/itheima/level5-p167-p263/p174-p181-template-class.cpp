# include <iostream>

// 7.1  include the source code, not recommended
//# include "p167-p173-template-class-person.cpp"
// 7.2  put .h and .cpp together and include the renamed .hpp file, recommended
# include "p174-p181-template-class-person.hpp"

using namespace std;

// template <typename NameType, typename AgeType = int>
// class Person {
// public:
//     NameType name;
//     AgeType age;

// public:
//     Person() { }
//     Person(NameType name, AgeType age);
//     // Person(NameType name, AgeType age) {
//     //     this->name = name;
//     //     this->age = age;
//     // }

//     void showPerson();
//     // void showPerson() { cout << this->name << " " << this->age << endl; }

//     void showTypeName() {
//         // cout << typeid(NameType).name << endl;
//         // cout << typeid(AgeType).name << endl;
//     }
// };

// // outside class member function implementation
// template <typename NameType, typename AgeType>
// Person<NameType, AgeType>::Person(NameType name, AgeType age) {
//     this->name = name;
//     this->age = age;
// }

// // outside class member function implementation
// template <typename NameType, typename AgeType>
// void Person<NameType, AgeType>::showPerson() {
//     cout << this->name << " " << this->age << endl;
// }

// inherited class Teacher becomes a concrete class now
class Teacher: public Person <string, int> {

};

// global function as friend outside of class
template <typename IdType, typename NameType, typename AgeType> class Student;  // so the following implementation knows about Student
template <typename IdType, typename NameType, typename AgeType>                 // so the following declaration knows about implementation
void printStudent2(Student<IdType, NameType, AgeType> s) {
    cout << s.id << " " << s.name << " " << s.age << endl;
}

// inherited class Teacher remains a template class
template <typename IdType, typename NameType, typename AgeType>
class Student: public Person <NameType, AgeType> {
    // global function as friend inside of class
    friend void printStudent1(Student<IdType, NameType, AgeType> s) {
        cout << s.id << " " << s.name << " " << s.age << endl;
    }
    // global function as friend outside of class
    friend void printStudent2<>(Student<IdType, NameType, AgeType> s);

private:
    IdType id;

public:
    Student(IdType id, NameType name, AgeType age) {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    void showStudent() { cout << this->id << " " << this->name << " " << this->age << endl; }
};

void func1();
void printPerson31(Person<string, int> &p);
template<typename NameType, typename AgeType> void printPerson32(Person<NameType, AgeType> &p);
template<typename T> void printPerson33(T &p);

// global function as friend inside of class
template <typename IdType, typename NameType, typename AgeType> 
void printStudent1(Student<IdType, NameType, AgeType> s);

// build command:
// /usr/bin/clang++ -std=c++11 -g p167-p173-template-class.cpp p167-p173-template-class-person.cpp -o p167-p173-template-class
/*
    p167-p173-template-class.cpp p167-p173-template-class-person.cpp
*/

// p167-p173, template class
int main() {

    cout << "template class" << endl;

    /*
        template class

        0.  purpose
            parameterize typename
        1.  grammar
            1.  declaration/definition: 
                template <typename T, ...>
                class declaration/definition
        2.  difference between function and class template
            1.  class template does not have implicit type conversion, type has to be specified
                Person<string, int> p1("Ada", 1);
            2.  class template's can have default type 
                Person<string> p2("Bob", 2);    // int is omitted within <...> because of default type specified
        3.  class member function of template class will be created while running, not in compling stage
            because the typename will be specified during running phase
        4.  template class object as a parameter for function
            1.  parameter type is specified directly within <...> in function parameter list
                void printPerson31(Person<string, int> &p) {...}
            2.  parameter type is specified as template within <...> in function parameter list
                template<typename NameType, typename AgeType> void printPerson32(Person<NameType, AgeType> &p) {...}
            3.  parameter type is specified as pure template within <...> in function parameter list
                template<typename T> void printPerson33(T &p) {...}
        5.  inheritance for template class
            the declaration of child class of a template parent class need to explicitly specify the concrete type of T
            otherwise make the child class to be a template class as well
        6.  implementation of class member function outside of class
            template <typename NameType, typename AgeType>          // copy this from class definition without default typename
            void Person<NameType, AgeType>::showPerson() {          // specify scope with typename <>
                cout << this->name << " " << this->age << endl;
            }
        7.  template class separated in .h and .cpp files
            1.  we create .h and .cpp file like usual
                but we include the separated file as .cpp instead of the usual way .h
                    because class member function of template class will be created while running, not in compling stage
                    so the compiler will compile the .h code only during compiling phase 
                in this way, the compiler will compile the included .cpp file first
                then the included .cpp file will have its included .h file compiled as well
            2.  put .h and .cpp together and include the renamed .hpp file, recommended way for template class separation
        8.  friend
            1.  implemented inside of class, just add friend without using scope
            2.  implemented outside of class
                1st, declare the class before the friend implementation
                2nd, implement the friend before the definition of the class
                3rd, then define the class
            tedious
    */

    func1();

    //system("pause");    // use it in windows, effect [press any key to continue], no such command in linux/mac

    return 0;
}

void func1() {
    // difference
    // 1. class template does not have implicit type conversion, type has to be specified inside of <...>
    Person<string, int> p1("Ada", 1);   p1.showPerson();
    // 2. class template's can have default type 
    Person<string> p2("Bob", 2);        p2.showPerson(); 
    
    // template class object as a parameter for function
    Person<string, int> p3("Clara", 3);
    printPerson31(p3);  // 1. parameter type is specified directly (<string, int>) within <...> in function parameter list
    printPerson32(p3);  // 2. parameter type is specified as template (Person<NameType, AgeType>) within <...> in function parameter list
    printPerson33(p3);  // 3. parameter type is specified as pure template (T &p) within <...> in function parameter list

    // inheritance for template class
    Student<int, string, int> s1(4, "David", 4);    s1.showStudent();

    // friend
    Student<int, string, int> s2(5, "Friend", 5);
    s2.showStudent();
    printStudent1(s2);
    printStudent2(s2);
}

// template class object as a parameter for function
// 1. parameter type is specified directly (<string, int>) within <...> in function parameter list
void printPerson31(Person<string, int> &p) {
    p.showPerson();
}
// 2. parameter type is specified as template (Person<NameType, AgeType>) within <...> in function parameter list
template<typename NameType, typename AgeType>
void printPerson32(Person<NameType, AgeType> &p) {
    p.showPerson();
    
    // https://stackoverflow.com/questions/789402/typeid-returns-extra-characters-in-g 
    // ./p167-p173-template-class | c++filt -t
    cout << typeid(NameType).name() << endl;
    cout << typeid(AgeType).name() << endl;
}
// 3. parameter type is specified as pure template (T &p) within <...> in function parameter list
template<typename T>
void printPerson33(T &p) {
    p.showPerson();
    
    // https://stackoverflow.com/questions/789402/typeid-returns-extra-characters-in-g 
    // ./p167-p173-template-class | c++filt -t
    cout << typeid(T).name() << endl;
}

// inheritance for template class
