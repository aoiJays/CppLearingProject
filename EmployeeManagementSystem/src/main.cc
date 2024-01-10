#include <cstdlib>
#include <iostream>

#include "manage_system.h"

int main() {

    ManageSystem manage_system;

    int choice; 
    while (true) {
        
        manage_system.ShowMenu();
        std::cin >> choice;

        switch (choice) {
            case 0:
                // 退出管理系统
                return 0;
                break;
            case 1:
                // 增加职工信息
                manage_system.AddWoker();
                break;
            case 2:
                // 显示职工信息
                manage_system.ShowWokerList();
                break;
            case 3:
                manage_system.DeleteWorker();
                // 删除职工信息
                break;
            case 4:
                manage_system.UpdateWorker();
                // 修改职工信息
                break;
            case 5:
                // 查找职工信息
                manage_system.SearchWorker();
                break;
            case 6:
                // 按照编号排序
                manage_system.SortWorker();
                break;
            case 7:
                // 清空所有文档
                manage_system.Clear();
                break;
            default:
                std::cout << "错误指令 请重新输入\n";
                break;
        }

        manage_system.Save();
        char ch = std::cin.get(); ch = std::cin.get();
        system("clear");
    }
}

