#include<iostream>
#include<string>
using namespace std;
//��
class People {
public:
    string number;
    string name;
    string sex;
    string birthday;
    string id;
    People(string nu, string na, string s, string b, string i) :
        number(nu), name(na), sex(s), birthday(b), id(i) {}
    //��ţ��������Ա𣬳������£����֤��
    People(const People& P) :
        number(P.number), name(P.name), sex(P.sex), birthday(P.birthday), id(P.id) {}
    ~People() {}
    void Show()const {
        cout << "���:" << number << endl
            << "����:" << name << endl
            << "�Ա�:" << sex << endl
            << "��������:" << birthday << endl
            << "���֤��:" << id << endl;
        cout << "_______________________________________" << endl;
    }
};
//ѧ��
class Student :virtual public People {
public:
    int classNo;
    Student(string nu, string na, string s, string b, string i, int c) :
        People(nu, na, s, b, i), classNo(c) {}
    //��ţ��������Ա𣬳������£����֤�ţ����
    Student(const Student& S) :People(S), classNo(S.classNo) {}
    ~Student() {}
    void Show()const {
        cout << "���:" << number << endl
            << "����:" << name << endl
            << "�Ա�:" << sex << endl
            << "��������:" << birthday << endl
            << "���֤��:" << id << endl
            << "���:" << classNo << endl;
        cout << "_______________________________________" << endl;
    }
};
//��ʦ
class Teacher :virtual public People {
public:
    string principalship;
    string department;
    Teacher(string nu, string na, string s, string b, string i, string p, string d) :
        People(nu, na, s, b, i), principalship(p), department(d) {}
    //��ţ��������Ա𣬳������£����֤�ţ�ְ�񣬲���
    Teacher(const Teacher& T) :
        People(T), principalship(T.principalship), department(T.department) {}
    ~Teacher() {}
    void Show()const {
        cout << "���:" << number << endl
            << "����:" << name << endl
            << "�Ա�:" << sex << endl
            << "��������:" << birthday << endl
            << "���֤��:" << id << endl
            << "ְ��:" << principalship << endl
            << "����:" << department << endl;
        cout << "_______________________________________" << endl;
    }
};

//������
class TA :virtual public Student, virtual public Teacher {
public:
    TA(string nu, string na, string s, string b, string i, int c, string sub, string p, string d) : Student(nu, na, s, b, i, c), Teacher(nu, na, s, b, i, p, d) ,People(nu,na,s,b,i) {}
    //��ţ��������Ա𣬳������£����֤�ţ���ţ�רҵ��ְ�񣬲���
    TA(const TA& T) : Student(T), Teacher(T), People(T) {}
    ~TA() {}
    void Show()const {
        cout << "���:" << number << endl
            << "����:" << name << endl
            << "�Ա�:" << sex << endl
            << "��������:" << birthday << endl
            << "���֤��:" << id << endl
            << "���:" << classNo << endl
            << "ְ��:" << principalship << endl
            << "����:" << department << endl
            << "____________" << endl;
    }
};

int main() {
    Teacher zhangsan("208", "����", "Ů", "20010504", "2900620105041230", "���������ʦ", "C���Բ�");
    TA t("201131380", "����", "��", "20001230", "290200012300326", 3, "�������", "ѧ��", "�캽");
    t.People::Show();
    t.Student::Show();
    t.Teacher::Show();
    t.TA::Show();
    return 0;
}