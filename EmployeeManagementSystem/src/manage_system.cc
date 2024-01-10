#include "manage_system.h"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "worker.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

using std::cin;
using std::cout;
using std::string;

ManageSystem::ManageSystem() {
    
    std::ifstream open(load_file_path);

    int worker_id; string worker_name, worker_role;  
    while (open >> worker_id >> worker_name >> worker_role) {
        Worker * p_temp = NULL;
        if ( worker_role == "老板" ) {
            p_temp = new Boss(worker_id, worker_name);
        }  
        else if ( worker_role == "经理" ) {
            p_temp = new Manager(worker_id, worker_name);
        }  
        else if ( worker_role == "员工" ) {
            p_temp = new Employee(worker_id, worker_name);
        }  

        worker_list.emplace_back(p_temp);
    }
    cout << "数据载入成功！\n";
    open.close();
}

void ManageSystem::ShowMenu() const {

    cout << "****************************************" << std::endl;
    cout << "****************职工管理系统*************" << std::endl;
    cout << "**************0. 退出管理系统************" << std::endl;
    cout << "**************1. 增加职工信息************" << std::endl;
    cout << "**************2. 显示职工信息************" << std::endl;
    cout << "**************3. 删除职工信息************" << std::endl;
    cout << "**************4. 修改职工信息************" << std::endl;
    cout << "**************5. 查找职工信息************" << std::endl;
    cout << "**************6. 按照编号排序************" << std::endl;
    cout << "**************7. 清空所有文档************" << std::endl;
    cout << "****************************************" << std::endl;
    cout << std::endl;
}

void ManageSystem::Save() const {

    std::ofstream save(load_file_path);

    for (auto p_temp : worker_list) {
        int worker_id = p_temp->GetWorkerId(); 
        string worker_name = p_temp->GetWorkerName();
        string worker_role = p_temp->GetRoleName();    
        save << worker_id << " " << worker_name << " " << worker_role << std::endl;
    }   
    save.close();
}

void ManageSystem::AddWoker() {

    int size_of_add = 0;
    while ( size_of_add <= 0 ) {
        cout << "请输入需要添加的人数(正整数)：" << std::endl;
        cin >> size_of_add;
    }

    for (int i=0;i<size_of_add;++i) {

        int worker_id; string worker_name, worker_role;    
        cin >> worker_id >> worker_name >> worker_role;

        Worker * p_temp = NULL;
        if ( worker_role == "老板" ) {
            p_temp = new Boss(worker_id, worker_name);
        }  
        else if ( worker_role == "经理" ) {
            p_temp = new Manager(worker_id, worker_name);
        }  
        else if ( worker_role == "员工" ) {
            p_temp = new Employee(worker_id, worker_name);
        }  

        worker_list.emplace_back(p_temp);
    }

    cout << "添加成功！" << std::endl;
}

void ManageSystem::ShowWokerList() const {

    cout << "************职工列表*************" << std::endl;
    for (auto p_temp : worker_list) {
        int worker_id = p_temp->GetWorkerId(); 
        string worker_name = p_temp->GetWorkerName();
        string worker_role = p_temp->GetRoleName();    
        cout << worker_id << " " << worker_name << " " << worker_role << std::endl;
    }   
    cout << "*********************************" << std::endl;
}

Worker * ManageSystem::FindWorker(int worker_id) const {
    for ( auto p_temp : worker_list ) {
        if ( p_temp->GetWorkerId() == worker_id ) return p_temp;
    }
    return NULL;
}

Worker * ManageSystem::FindWorker(string name) const {
    for ( auto p_temp : worker_list ) {
        if ( p_temp->GetWorkerName() == name ) return p_temp;
    }
    return NULL;
}

void ManageSystem::DeleteWorker() {

    cout << "输入要删除的职工姓名或编号" << std::endl;
    string input; cin >> input;

    int worker_id = 0;
    if ( input[0] >= '0' && input[0] <= '1' ) 
        worker_id = std::stoi(input);

    Worker * p_temp = worker_id ? FindWorker(worker_id) : FindWorker(input);
    
    if ( p_temp == NULL ) {
        cout << "无法找到此职工 删除失败" << std::endl;
        return;
    }

    for (int i=0;i<worker_list.size();++i)
        if ( worker_list[i] == p_temp ) {
            for (int j=i;j<worker_list.size()-1;++j)
                worker_list[j] = worker_list[j + 1];
            break;
        }
    worker_list.pop_back();
    delete p_temp;
    cout << "成功" << std::endl;
}

void ManageSystem::UpdateWorker() {
    cout << "输入要修改的职工姓名或编号" << std::endl;
    string input; cin >> input;

    int worker_id = 0;
    if ( input[0] >= '0' && input[0] <= '1' ) 
        worker_id = std::stoi(input);

    Worker * p_temp = worker_id ? FindWorker(worker_id) : FindWorker(input);
    
    if ( p_temp == NULL ) {
        cout << "无法找到此职工 删除失败" << std::endl;
        return;
    }

    cout << "找到的职工信息如下：" << std::endl;
    worker_id = p_temp->GetWorkerId(); 
    string worker_name = p_temp->GetWorkerName();
    string worker_role = p_temp->GetRoleName();    
    cout << worker_id << " " << worker_name << " " << worker_role << std::endl;

    cout << "\n开始修改：" << std::endl;
    cout << "职工编号："; cin >> worker_id;
    cout << "职工姓名："; cin >> worker_name;
    cout << "职工岗位："; cin >> worker_role;

    Worker * p_new = NULL;
    if ( worker_role == "老板" ) {
        p_new = new Boss(worker_id, worker_name);
    }  
    else if ( worker_role == "经理" ) {
        p_new = new Manager(worker_id, worker_name);
    }  
    else if ( worker_role == "员工" ) {
        p_new = new Employee(worker_id, worker_name);
    }  
    else {
        cout << "岗位信息错误 修改失败" << std::endl;
        return;
    }

    for (int i=0;i<worker_list.size();++i)
        if ( worker_list[i] == p_temp ) {
            worker_list[i] = p_new;
            break;
        }
    delete p_temp;
    cout << "成功" << std::endl;
}

void ManageSystem::SearchWorker() {

    cout << "输入要查找的职工姓名或编号" << std::endl;
    string input; cin >> input;

    int worker_id = 0;
    if ( input[0] >= '0' && input[0] <= '1' ) 
        worker_id = std::stoi(input);

    Worker * p_temp = worker_id ? FindWorker(worker_id) : FindWorker(input);
    
    if ( p_temp == NULL ) {
        cout << "无法找到此职工 删除失败" << std::endl;
        return;
    }

    cout << "找到的职工信息如下：" << std::endl;
    worker_id = p_temp->GetWorkerId(); 
    string worker_name = p_temp->GetWorkerName();
    string worker_role = p_temp->GetRoleName();    
    cout << worker_id << " " << worker_name << " " << worker_role << std::endl;
    cout << "成功" << std::endl;
}

void ManageSystem::SortWorker() {

    cout << "请选择：1. 编号升序\t2. 编号降序" << std::endl;
    int opt = 0;
    while (opt != 1 && opt != 2) {
        cout << "请输入：";
        cin >> opt;
    }

    if ( opt == 1 ) 
        sort( worker_list.begin(), worker_list.end(), [&](Worker * a, Worker * b) {
            return a->GetWorkerId() < b->GetWorkerId();
        });
    else if ( opt == 2 ) 
        sort( worker_list.begin(), worker_list.end(), [&](Worker * a, Worker * b) {
            return a->GetWorkerId() > b->GetWorkerId();
        });

    cout << "成功！" << std::endl;
}

void ManageSystem::Clear() {
    for (auto p_temp: worker_list) {
        delete p_temp;
    }
    worker_list.clear();
}

ManageSystem::~ManageSystem() {
    Save();
    for (auto p_temp : worker_list) {
        delete p_temp;
    }   
}