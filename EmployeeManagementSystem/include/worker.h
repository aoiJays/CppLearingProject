#ifndef WORKER_H_
#define WORKER_H_

#include <string>
using std::string;

class Worker {
    
    protected:
        
        int worker_id;
        string worker_name;

    public:
        virtual void ShowInfo() const = 0;
        virtual string GetRoleName() const = 0;

        int GetWorkerId() const;
        string GetWorkerName() const;
};
#endif