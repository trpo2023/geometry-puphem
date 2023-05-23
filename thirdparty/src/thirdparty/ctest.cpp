#include "../functions/functions.h"
#include "ctest.h"

CTEST(addtodo, test_addtodo){
    int ID = lastID();
    addtodo();
    int result = lastID();
    ASSERT_EQUAL(ID + 1, result);
}

CTEST(updateData,test_updateData)
{
    int test = 1, result = 1;
    ifstream ifs, ifs2;
    ifs.open("todo.txt");
    ofstream ofs;
    ofs.open("todo_temp.txt");
    string str, str2;
    while (std::getline(ifs,str))
        ofs << str << '\n';
    ifs.close();
    ofs.close();
    updateData();
    ifs.open("todo.txt");
    ifs2.open("todo_temp.txt");
    while(result == 1 && std::getline(ifs,str))
    {
        std::getline(ifs2,str2);
        if (str != str2) result = 0;
    }
    ifs.close();
    ifs2.close();
    ASSERT_NOT_EQUAL(test,result);
}

CTEST(updatePriority,test_updatePriority)
{
    int test = 1, result = 1;
    ifstream ifs, ifs2;
    ifs.open("todo.txt");
    ofstream ofs;
    ofs.open("todo_temp.txt");
    string str, str2;
    while (std::getline(ifs,str))
        ofs << str << '\n';
    ifs.close();
    ofs.close();
    updatePriority();
    ifs.open("todo.txt");
    ifs2.open("todo_temp.txt");
    while(result == 1 && std::getline(ifs2,str2))
    {
        std::getline(ifs,str);
        if (str != str2) result = 0;
    }
    ifs.close();
    ifs2.close();
    ASSERT_NOT_EQUAL(test,result);
}

CTEST(deltodo,test_deltodo)
{
    int test = 1, result = 1;
    ifstream ifs, ifs2;
    ifs.open("todo.txt");
    ofstream ofs;
    ofs.open("todo_temp.txt");
    string str, str2;
    while (std::getline(ifs,str))
        ofs << str << '\n';
    ifs.close();
    ofs.close();
    deltodo();
    ifs.open("todo.txt");
    ifs2.open("todo_temp.txt");
    while(result == 1 && std::getline(ifs2,str2))
    {
        if(!std::getline(ifs2,str2)) result = 0;
        else
            if (str != str2) result = 0;
    }
    ifs.close();
    ifs2.close();
    ASSERT_NOT_EQUAL(test,result);
}