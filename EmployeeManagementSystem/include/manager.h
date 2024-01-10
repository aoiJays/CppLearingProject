#ifndef MANAGER_H_
#define MANAGER_H_

#include <string>

#include "worker.h"

using std::string;

class Manager : public Worker {
    
    private:
        
    public:

        Manager(int id, string name);
        void ShowInfo() const;
        string GetRoleName() const;
};

#endif