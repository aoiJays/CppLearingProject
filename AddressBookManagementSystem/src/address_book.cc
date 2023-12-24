// 先引入需要实现的头文件
#include "address_book.h"

// C 头文件

// C++头文件
#include <algorithm>
#include <iostream>

// 本项目头文件
#include "address.h"


void AddressBook::ShowSingleAddress( int address_num ) const {

    if ( address_num >= (*this).book_size || address_num < 0 ) {
        std::cout << " --- --- 编号非法 显示失败 --- " << std::endl;
        return;
    }

    std::cout << " --- --- --- --- --- " << std::endl;
    std::cout << "姓名： " << (*this).book[address_num].u_name << std::endl;
    std::cout << "性别： " << ((*this).book[address_num].sex == 0 ? "女" : "男") << std::endl;
    std::cout << "年龄： " << (*this).book[address_num].age << std::endl;
    std::cout << "电话： " << (*this).book[address_num].telephone << std::endl;
    std::cout << "住址： " << (*this).book[address_num].home_address << std::endl;
    std::cout << " --- --- --- --- --- \n" << std::endl;

}

// WARNING：找不到 返回 -1
int AddressBook::FindAddress( std::string u_name ) const {
   
    for (int i=0;i<(*this).book_size;++i) {
        if ( (*this).book[i].u_name == u_name ) return i;
    }
    return -1;
}

AddressBook::AddressBook() {
    (*this).book_size = 0;
}

void AddressBook::AddNewAddress() { 

    if ( (*this).book_size == (*this).MAXN ) {
        std::cout << " --- --- 通讯录已满 --- --- 添加失败 --- " << std::endl;
        return;
    }

    Address temp;    

    // 姓名
    std::cout << " --- --- 输入姓名 --- --- " << std::endl;
    std::cin >> temp.u_name;


    // 性别
    std::cout << " --- --- 输入性别 --- --- " << std::endl;    
    temp.sex = -1;

    while ( temp.sex != 0 && temp.sex != 1) {
        std::cout << "(0. 女性 1. 男性 ) 输入0/1 " << std::endl;  
        std::cin >> temp.sex;
    }


    // 年龄
    std::cout << " --- --- 输入年龄 --- --- " << std::endl;    
    std::cin >> temp.age;


    // 电话
    std::cout << " --- --- 输入电话 --- --- " << std::endl;      
    std::cin >> temp.telephone;


    // 家庭住址
    std::cout << " --- --- 家庭住址 --- --- " << std::endl;      
    std::cin >> temp.home_address;  


    // 添加
    (*this).book[ (*this).book_size ++ ] = temp;

    std::cout << " --- --- 添加成功 --- --- " << std::endl; 
    (*this).ShowSingleAddress( (*this).book_size - 1 );
    std::cout << " --- --- 添加的记录如上 --- --- " << std::endl; 
}

void AddressBook::ShowAddress() const {
    std::cout << "通讯录中共有" << (*this).book_size << "条记录" << std::endl;
    for (int i=0;i<(*this).book_size;++i) {
        (*this).ShowSingleAddress( i );
    }
}

void AddressBook::DeleteAddress() {

    if ( (*this).book_size == 0 ) {
        std::cout << " --- --- 通讯录为空 无法删除 --- --- " << std::endl;
        return;
    }

    std::cout << " --- --- 输入你需要删除的名字 --- --- " << std::endl;

    std::string temp_name;
    std::cin >> temp_name;


    // 查找
    int position_in_book = (*this).FindAddress( temp_name );
    if ( position_in_book == -1 ) {
        std::cout << " --- --- 查无此人 删除失败 --- --- " << std::endl;
        return;
    }


    // 删除

    std::cout << " --- --- 删除对象如下 --- --- " << std::endl;
    (*this).ShowSingleAddress( position_in_book );

    std::swap( (*this).book[ position_in_book ], (*this).book[ (*this).book_size ] );
    --(*this).book_size;

    std::cout << " --- --- 删除成功 --- --- " << std::endl;
}

void AddressBook::QueryAddress() const {

    std::cout << " --- --- 输入你需要查找的名字 --- --- " << std::endl;

    std::string temp_name;
    std::cin >> temp_name;


    // 查找
    int position_in_book = (*this).FindAddress( temp_name );
    if ( position_in_book == -1 ) {
        std::cout << " --- --- 查无此人 查找失败 --- --- " << std::endl;
        return;
    }


    // 显示
    std::cout << " --- --- 查找对象如下 --- --- " << std::endl;
    (*this).ShowSingleAddress( position_in_book );
    std::cout << " --- --- 查找成功 --- --- " << std::endl;
}

void AddressBook::UpdateAddress() {

    std::cout << " --- --- 输入你需要修改的名字 --- --- " << std::endl;

    std::string temp_name;
    std::cin >> temp_name;


    // 查找
    int position_in_book = (*this).FindAddress( temp_name );
    if ( position_in_book == -1 ) {
        std::cout << " --- --- 查无此人 修改失败 --- --- " << std::endl;
        return;
    }

    Address *temp = &(*this).book[position_in_book];    

    // 姓名
    std::cout << "原姓名：" << temp->u_name << std::endl;
    std::cout << " --- --- 输入姓名 --- --- " << std::endl;
    std::cin >> temp->u_name;


    // 性别
    std::cout << "原性别：" << (temp->sex==0?"女":"男") << std::endl;
    temp->sex = -1;
    std::cout << " --- --- 输入性别 --- --- " << std::endl;    
    
    while ( temp->sex != 0 && temp->sex != 1) {
        std::cout << "(0. 女性 1. 男性 ) 输入0/1 " << std::endl;  
        std::cin >> temp->sex;
    }


    // 年龄
    std::cout << "原年龄：" << temp->age << std::endl;
    std::cout << " --- --- 输入年龄 --- --- " << std::endl;    
    std::cin >> temp->age;


    // 电话
    std::cout << "原电话：" << temp->telephone << std::endl;
    std::cout << " --- --- 输入电话 --- --- " << std::endl;      
    std::cin >> temp->telephone;


    // 家庭住址
    std::cout << "原住址：" << temp->home_address << std::endl;
    std::cout << " --- --- 家庭住址 --- --- " << std::endl;      
    std::cin >> temp->home_address;  


    std::cout << " --- --- 修改成功 --- --- " << std::endl; 
    (*this).ShowSingleAddress( position_in_book );
    std::cout << " --- --- 添加的记录如上 --- --- " << std::endl; 
}

void AddressBook::ClearAddress() {
    (*this).book_size = 0;
    std::cout << " --- --- 清空完成 --- --- " << std::endl;
}