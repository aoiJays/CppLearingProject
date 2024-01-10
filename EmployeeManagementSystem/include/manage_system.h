#ifndef MANAGE_SYSTEM_H_
#define MANAGE_SYSTEM_H_

#include <string>
#include <vector>

#include "worker.h"

using std::string;
using std::vector;

class ManageSystem {

    private:
        const string load_file_path = "/home/aoijays/cppProject/EmployeeManagementSystem/asset/wokerList.txt";
        vector<Worker *> worker_list;

    public:
        
        ManageSystem();
        
        // 菜单显示
        void ShowMenu() const;

        // 将内存中的信息保存
        void Save() const;

        // 添加职工
        void AddWoker();

        // 显示所有职工信息
        void ShowWokerList() const;

        // 查找职工
        Worker * FindWorker(int worker_id) const;
        Worker * FindWorker(string name) const;
        
        // 删除职工
        void DeleteWorker();

        // 修改职工信息
        void UpdateWorker();

        // 查找职工信息
        void SearchWorker();
        
        // 按编号排序
        void SortWorker();

        // 清空
        void Clear();

        ~ManageSystem();

};

#endif