#include "worker.h"

#include <string>
using std::string;


int Worker::GetWorkerId() const {
    return worker_id;
}

string Worker::GetWorkerName() const {
    return worker_name;
}