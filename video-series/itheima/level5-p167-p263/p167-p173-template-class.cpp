# include <iostream>

using namespace std;

template <typename NameType, typename AgeType = int>
class Person {
public:
    NameType name;
    AgeType age;

public:
    Person() { }
    Person(NameType name, AgeType age) {
        this->name = name;
        this->age = age;
    }

    void showPerson() { cout << this->name << " " << this->age << endl; }
    void showTypeName() {
        //cout << typeid(NameType).name << endl;
        //cout << typeid(AgeType).name << endl;
    }
};

// inherited class Teacher becomes a concrete class now
class Teacher: public Person <string, int> {

};

// inherited class Teacher remains a template class
template <typename IdType, typename NameType, typename AgeType>
class Student: public Person <NameType, AgeType> {
public:
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