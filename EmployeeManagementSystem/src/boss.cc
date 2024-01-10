#include "boss.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;

Boss::Boss(int id, string name) {
    this->worker_id = id;
    this->worker_name = name;
}


void Boss::ShowInfo() const {
    cout << "职工编号: " << this->worker_id << "\t";
    cout << "职工姓名: " << this->worker_name << "\t";
    cout << "岗位: " << this->GetRoleName() << "\t";
    cout << "职责: " << "管理公司" << "\n";
}

string Boss::GetRoleName() const {
    return string("老板");
}