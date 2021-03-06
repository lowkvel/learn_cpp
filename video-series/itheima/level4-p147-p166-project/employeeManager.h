# pragma once

# include <iostream>
# include <fstream>

# include "employeeType.h"
# include "employeeTypeNormal.h"
# include "employeeTypeManager.h"
# include "employeeTypeBoss.h"

# define FILENAME "empFile.txt"

using namespace std;

class EmployeeManager {
public:
    int employeeCount;          // employee count
    EmployeeType ** empArray;   // employee array
    bool fileIsEmpty;

public:
    // constructor
    EmployeeManager();

    // destructor
    ~EmployeeManager();

    // read file 
    void read();

    // save file
    void save();

    // check if the file is empty or not exist
    int checkFileStatus(ifstream &ifs);

    // get employee count
    int get_employeeCount();

    // init employee
    void init_employee();

    // show menu
    void showMenu();

    // 0. quit
    void quit();

    // 1. add
    void add();

    // 2. show
    void show();

    // get index of an employee given specific employee id
    int getIndex(int id);

    // 3. delete
    void del();

    // 4. modify
    void modify();

    // 5. find
    void find();

    // 6. sort
    void sort();

    // 7. clear
    void clear();
};
