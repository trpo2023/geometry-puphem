#include "functions.h"

const char* output = "todo.txt";
const char* temp_output = "temp.txt";

void header (int n) {
	system("clear");
    if (n == 0) {
        cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
	    cout<<"\t\t\t|              Добро пожаловать в Ваш Персональный ToDo List             |"<<endl;
        cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;

    }
    if (n == 1) {
        system("clear");
        cout << "\t\t\t ------------------------------------------------------------------------" << endl;
        cout << "\t\t\t|                      Ваш персональный ToDo List                        |" << endl;
        cout << "\t\t\t ------------------------------------------------------------------------" << endl << endl;
    }
    if (n == 2) {
        header (1);
        cout << "\n\tВведите новую заметку: ";
    }
    if (n == 3) {
        header (1);
        cout << "\n\tВведите номер задачи: ";
    }
    if (n == 4) {
        system("clear");
        cout << "\n\t\t\t---------------------------Текущие задачи-----------------------------\n";
    }
}


void addtodo_user_choice () {
    string ch;
    cout << "Хотите добавить ещё? (д/н)" << endl;
    cin >> ch;

    if(ch == "д" or "да"){
        header (2);
        addtodo();
    }
    else
    {
        cout << "\n\tЗаметка добавлена!";
        return;
    }
}


void addtodo() {
    int ID = lastID();
    string ch = "д";
    while (ch == "д")
    {
        header (2);
        todo todo;
        cin.get();
        getline(cin, todo.task); 
        ID++; 

        ofstream write;
        write.open(output, ios::app);
        write << "\n" << ID;
        write << "\n " << todo.task ;
        write << "\n" << "не определён";
        write.close();

        write.open("id.txt");
        write << ID;
        write.close();

        cout << "Хотите добавить ещё? (д/н)" << endl;
        cin >> ch;
    }
}


void print(todo s) {
    cout << "\n\t" << s.id << ". " << s.task << "\n\tПриоритет: " << s.priority;
}

void readData() {
    todo todo;
    ifstream read;
    read.open(output);
    
    while (!read.eof()) {
        read >> todo.id;
        if (!todo.id)
        {
            cout << "\n\tЗаметок нет!";
            return;
        } 
        read.ignore(); 
        getline(read, todo.task);
        read.ignore();
        getline(read, todo.priority);
        print(todo); 
    }
    read.close();
}


int searchData() {
    int id; 
    cin >> id; 
    todo todo;
    ifstream read;
    read.open(output); 
    
    while (!read.eof()) {
        read >> todo.id; 
        read.ignore(); 
        getline(read, todo.task);
        read.ignore();
        getline(read, todo.priority); 
        if (todo.id == id) {
            print(todo); 
            return id; 
        }
    }
    return -1;
}

void updateData() {
    int id = searchData(); 
    cout << "\n\tХотите изменить эту заметку? (д/н) : ";
    string ch;
    cin >> ch;
    if (ch == "д") {
        cout << "\n\tВведите новую заметку : ";
        todo newData; 
        cin.get(); 
        getline(cin, newData.task); 
        
        todo todo;
        ofstream tempFile;
        tempFile.open(temp_output); 
        ifstream read;
        read.open(output); 
        
        while (!read.eof()) {
            read >> todo.id;
            read.ignore(); 
            getline(read, todo.task);
            read.ignore();
            getline(read, todo.priority);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
                tempFile << "\n " << todo.priority;
            }
            else {
                tempFile << "\n"<< todo.id;
                tempFile << "\n"<< newData.task;
                tempFile << "\n " << todo.priority;
            }
        }
        read.close(); 
        tempFile.close();
        remove(output);
        rename(temp_output, output); 
        cout << "\n\tЗаметка обновлена!";
    }
    else {
        cout << "\n\tЗаметка не обновлена";
    }
}

void exit_program() {
    exit(0);
}

void updatePriority()
{
    int id = searchData(); 
    cout << "\n\tХотите изменить приоритет заметки? (д/н) : ";
    string ch;
    cin >> ch;
    if (ch == "д") {
        cout << "\n\tУкажите приоритет : ";
        todo newData; 
        cin.get(); 
        getline(cin, newData.priority); 
        
        todo todo;
        ofstream tempFile;
        tempFile.open(temp_output); 
        ifstream read;
        read.open(output); 
        
        while (!read.eof()) {
            read >> todo.id;
            read.ignore(); 
            getline(read, todo.task);
            read.ignore();
            getline(read, todo.priority);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
                tempFile << "\n " << todo.priority;
            }
            else {
                tempFile << "\n"<< todo.id;
                tempFile << "\n"<< todo.task;
                tempFile << "\n " << newData.priority;
            }
        }
        read.close(); 
        tempFile.close();
        remove(output);
        rename(temp_output, output); 
        cout << "\n\tПриоритет изменён!";
    }
    else {
        cout << "\n\tПриоритет не изменён!";
    }
}

void clearAllData()
{
    remove(output);
    remove("id.txt");
}

void deltodo()
{
    int id = searchData(); 
    cout << "\n\tХотите удалить эту заметку? (д/н) : ";
    string ch;
    cin >> ch;
    if (ch == "д") {
        todo todo;
        ofstream tempFile;
        tempFile.open(temp_output); 
        ifstream read;
        read.open(output); 
        
        while (!read.eof()) {
            read >> todo.id;
            read.ignore(); 
            getline(read, todo.task);
            read.ignore();
            getline(read, todo.priority);
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
                tempFile << "\n " << todo.priority;
            }
        }
        read.close(); 
        tempFile.close();
        remove(output);
        rename(temp_output, output); 
        cout << "\n\tЗаметка удалена!";
    }
    else {
        cout << "\n\tЗаметка не удалена!";
    }
}

int lastID()
{
    int ID = 0;
    ifstream read; 
    read.open("id.txt"); 

    if (!read.fail()) { 
        read >> ID; 
    }
    read.close();
    return ID;
}

void startMenu()
{
     while (true) {
        cout << endl << endl;
        cout << "\n\t1.Добавить заметку";
        cout << "\n\t2.Просмотреть заметки";
        cout << "\n\t3.Изменить заметку";
        cout << "\n\t4.Удалить заметку";
        cout << "\n\t5.Удалить все заметки";
        cout << "\n\t6.Изменить приоритет заметки";
        cout << "\n\t0.Выход";

        int choice;
        cout << "\n\tЧто хотите сделать?  ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
        case 2:
            header (4);
            readData();
            break;
        case 3:
            header (3);
            updateData();
            break;
        case 4:
            header (3);
            deltodo();
            break;
        case 5:
            header(4);
            clearAllData();
            break;
        case 6:
            header (3);
            updatePriority();
            break;
        case 0:
            exit_program();
            break;
        }
    }
}

