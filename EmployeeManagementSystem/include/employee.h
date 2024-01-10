#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>

#include "worker.h"

using std::string;

class Employee : public Worker {
    
    private:
        
    public:

        Employee(int id, string name);
        void ShowInfo() const;
        string GetRoleName() const;
};

#endif