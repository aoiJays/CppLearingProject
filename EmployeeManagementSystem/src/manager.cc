#include "manager.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;

Manager::Manager(int id, string name) {
    this->worker_id = id;
    this->worker_name = name;
}


void Manager::ShowInfo() const {
    cout << "职工编号: " << this->worker_id << "\t";
    cout << "职工姓名: " << this->worker_name << "\t";
    cout << "岗位: " << this->GetRoleName() << "\t";
    cout << "职责: " << "完成老板交给的任务 为员工布置任务" << "\n";
}

string Manager::GetRoleName() const {
    return string("经理");
}