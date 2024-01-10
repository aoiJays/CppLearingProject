#ifndef BOSS_H_
#define BOSS_H_

#include <string>

#include "worker.h"

using std::string;

class Boss : public Worker {
    
    private:
        
    public:

        Boss(int id, string name);
        void ShowInfo() const;
        string GetRoleName() const;
};

#endif