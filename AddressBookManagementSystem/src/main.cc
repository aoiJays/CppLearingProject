#include <cstdlib>
#include <iostream>

#include "address_book.h"
#include "menu.h"

int main() {

    AddressBook address_book;

    while (true) {
        system("clear");
        ShowMenu();
        int user_num = -1; std:: cin >> user_num;

        // 0. 退出通讯录
        if ( user_num == 0 ) {
            std:: cout << " --- --- 通讯录关闭 --- --- " << std::endl;
            break;
        }

        // 1. 添加联系人
        else if ( user_num == 1 ) {
           address_book.AddNewAddress();
        }

        // 2. 显示联系人
        else if ( user_num == 2 ) {
            address_book.ShowAddress();
        }

        // 3. 删除联系人
        else if ( user_num == 3 ) {
            address_book.DeleteAddress();
        }

        // 4. 查找联系人
        else if ( user_num == 4 ) {
            address_book.QueryAddress();
        }

        // 5. 修改联系人
        else if ( user_num == 5 ) {
            address_book.UpdateAddress();
        }

        // 6. 清空联系人
        else if ( user_num == 6 ) {
            address_book.ClearAddress();
        }    

        char ch = getchar(); 
        std::cout << "请按任意键继续 ... " << std::endl;
        ch = getchar();
    }

    return 0;
}