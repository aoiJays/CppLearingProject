#include "employee.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;

Employee::Employee(int id, string name) {
    this->worker_id = id;
    this->worker_name = name;
}


void Employee::ShowInfo() const {
    cout << "职工编号: " << this->worker_id << "\t";
    cout << "职工姓名: " << this->worker_name << "\t";
    cout << "岗位: " << this->GetRoleName() << "\t";
    cout << "职责: " << "完成经理交给的任务" << "\n";
}

string Employee::GetRoleName() const {
    return string("员工");
}