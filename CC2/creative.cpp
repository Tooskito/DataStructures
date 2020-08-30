#include <iostream>
#include <vector>
#include <string>

#include "Quick.h"
#include "Scheduler.h"

int main() {

    std::vector<uint64_t> myJobs{
        55, 27, 59, 1, 5, 12, 7, 2, 444, 2, 3, 15, 25, 47, 25, 126, 25
    };
    
    std::vector<Processor> myProcs{
        Processor(0, 60), Processor(1, 40), Processor(2, 0), Processor(3, 9) 
    };

    Scheduler::Balance(myProcs, myJobs);
    PrintVector(myProcs);

    return 0;
}