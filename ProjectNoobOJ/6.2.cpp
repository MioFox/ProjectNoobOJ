#include<iostream>
#include<string>
using namespace std;
//人
class People {
public:
    string number;
    string name;
    string sex;
    string birthday;
    string id;
    People(string nu, string na, string s, string b, string i) :
        number(nu), name(na), sex(s), birthday(b), id(i) {}
    //编号，姓名，性别，出生年月，身份证号
    People(const People& P) :
        number(P.number), name(P.name), sex(P.sex), birthday(P.birthday), id(P.id) {}
    ~People() {}
    void Show()const {
        cout << "编号:" << number << endl
            << "姓名:" << name << endl
            << "性别:" << sex << endl
            << "出生年月:" << birthday << endl
            << "身份证号:" << id << endl;
        cout << "_______________________________________" << endl;
    }
};
//学生
class Student :virtual public People {
public:
    int classNo;
    Student(string nu, string na, string s, string b, string i, int c) :
        People(nu, na, s, b, i), classNo(c) {}
    //编号，姓名，性别，出生年月，身份证号，班号
    Student(const Student& S) :People(S), classNo(S.classNo) {}
    ~Student() {}
    void Show()const {
        cout << "编号:" << number << endl
            << "姓名:" << name << endl
            << "性别:" << sex << endl
            << "出生年月:" << birthday << endl
            << "身份证号:" << id << endl
            << "班号:" << classNo << endl;
        cout << "_______________________________________" << endl;
    }
};
//老师
class Teacher :virtual public People {
public:
    string principalship;
    string department;
    Teacher(string nu, string na, string s, string b, string i, string p, string d) :
        People(nu, na, s, b, i), principalship(p), department(d) {}
    //编号，姓名，性别，出生年月，身份证号，职务，部门
    Teacher(const Teacher& T) :
        People(T), principalship(T.principalship), department(T.department) {}
    ~Teacher() {}
    void Show()const {
        cout << "编号:" << number << endl
            << "姓名:" << name << endl
            << "性别:" << sex << endl
            << "出生年月:" << birthday << endl
            << "身份证号:" << id << endl
            << "职务:" << principalship << endl
            << "部门:" << department << endl;
        cout << "_______________________________________" << endl;
    }
};

//助教生
class TA :virtual public Student, virtual public Teacher {
public:
    TA(string nu, string na, string s, string b, string i, int c, string sub, string p, string d) : Student(nu, na, s, b, i, c), Teacher(nu, na, s, b, i, p, d) ,People(nu,na,s,b,i) {}
    //编号，姓名，性别，出生年月，身份证号，班号，专业，职务，部门
    TA(const TA& T) : Student(T), Teacher(T), People(T) {}
    ~TA() {}
    void Show()const {
        cout << "编号:" << number << endl
            << "姓名:" << name << endl
            << "性别:" << sex << endl
            << "出生年月:" << birthday << endl
            << "身份证号:" << id << endl
            << "班号:" << classNo << endl
            << "职务:" << principalship << endl
            << "部门:" << department << endl
            << "____________" << endl;
    }
};

int main() {
    Teacher zhangsan("208", "张三", "女", "20010504", "2900620105041230", "程序设计老师", "C语言部");
    TA t("201131380", "李四", "男", "20001230", "290200012300326", 3, "软件工程", "学生", "领航");
    t.People::Show();
    t.Student::Show();
    t.Teacher::Show();
    t.TA::Show();
    return 0;
}