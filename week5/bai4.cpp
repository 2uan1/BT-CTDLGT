#include <iostream>
#include <map>

using namespace std;

struct Student{
    int ID;
    string name;
    string cls;

    Student()
    {
        ID = -1;
        name = nullptr;
        cls = nullptr;
    }

    Student(int ID_, string name_, string cls_)
    {
        ID = ID_;
        name = name_;
        cls = cls_;
    }
};

class StudentManagement{
private:
    map<int, Student*> studentList;

public:
    StudentManagement()
    {

    }

    void Insert(int ID, string name, string Class)
    {
        studentList.insert(pair<int, Student*>(ID, new Student(ID, name, Class)));
    }

    void Delete(int ID)
    {
        studentList[ID] = nullptr;
        studentList.erase(ID);
    }

    void Infor(int ID)
    {
        if (studentList[ID] == nullptr)
        {
            cout << "NA,NA" << endl;
            return;
        }
        cout <<  studentList[ID]->name + "," + studentList[ID]->cls << endl;
    }
};

int main()
{
    StudentManagement* oasis = new StudentManagement();
    oasis->Insert(1, "nam", "K67");
    oasis->Insert(2, "dmquan","K68");
    oasis->Insert(3, "vu", "K67");
    oasis->Infor(1);
    oasis->Infor(2);
    oasis->Infor(3);
    oasis->Delete(2);
    oasis->Infor(2);
    oasis->Infor(3);
}
