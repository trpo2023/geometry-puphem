#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <clocale>

using namespace std;

//constexpr int EXIT_CODE = -1;

//extern int ID;

struct todo {
    int id;
    string task;
    string priority;
};

void header (int n);
void addtodo();
void print (todo s);
int searchData();
void readData();
void updateData();
void exit_program();
void deltodo();
void updatePriority();
void clearAllData();
void startMenu();
int lastID();