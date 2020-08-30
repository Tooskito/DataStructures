/**
 *  @author Jonathan Abbott
 *  @date   Aug 30, 2020
 *  
 *  This file includes the driver for the Creative portion of my CC2 for CSE 20312.
 */


#include <iostream> // std::cout
#include <vector>   // std::vector

#include "../include/Quick.h"       // PrintVector
#include "../include/Scheduler.h"   // Scheduler::Balance


/**
 *  This is the main driver for my Creative portion of CC2, demonstrating a scheduling 
 *  algorithm that includes QuickSort.
 *  
 *  @return An exit code 0 for success. Otherwise, failure.
 */
int main() {


    // Simple test #1 to make sure algorithm works.
    std::vector<uint64_t> TestOneJobs{
        20, 20, 10, 10
    };
    
    std::cout << "Test #1 Jobs:\t\t\t";
    PrintVector(TestOneJobs);

    std::vector<Processor> TestOneProcessors{
        Processor(0, 0), Processor(1, 0), Processor(2, 0)
    };
    
    std::cout << "Test #1 Initial Processors:\t";
    PrintVector(TestOneProcessors);

    Scheduler::Balance(TestOneProcessors, TestOneJobs);
    
    // Result should be 20, 20, 20
    std::cout << "Test #1 Final Processors:\t";
    PrintVector(TestOneProcessors);

    std::cout << std::endl;



    // Another test #2 to test edge-case.
    std::vector<uint64_t> TestTwoJobs{
        10, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };
    
    std::cout << "Test #2 Jobs:\t\t\t";
    PrintVector(TestTwoJobs);

    std::vector<Processor> TestTwoProcessors{
        Processor(0, 0), Processor(1, 0)
    };
    
    std::cout << "Test #2 Initial Processors:\t";
    PrintVector(TestTwoProcessors);

    Scheduler::Balance(TestTwoProcessors, TestTwoJobs);
    
    // Result should be 15, 15
    std::cout << "Test #2 Final Processors:\t";
    PrintVector(TestTwoProcessors);

    std::cout << std::endl;



    // General test #3.
    std::vector<uint64_t> TestThreeJobs{
        50, 75, 10, 40
    };
    
    std::cout << "Test #3 Jobs:\t\t\t";
    PrintVector(TestThreeJobs);

    std::vector<Processor> TestThreeProcessors{
        Processor(0, 100), Processor(1, 20), Processor(2, 30)
    };
    
    std::cout << "Test #3 Initial Processors:\t";
    PrintVector(TestThreeProcessors);

    Scheduler::Balance(TestThreeProcessors, TestThreeJobs);
    
    // Result should be 100, 105, 120
    std::cout << "Test #3 Final Processors:\t";
    PrintVector(TestThreeProcessors);

    std::cout << std::endl;



    // Another test #4 to test edge-case.
    std::vector<uint64_t> TestFourJobs{
        50, 75, 25, 10, 20, 15, 30, 60
    };
    
    std::cout << "Test #4 Jobs:\t\t\t";
    PrintVector(TestFourJobs);

    std::vector<Processor> TestFourProcessors{
        Processor(0, 500), Processor(1, 0)
    };
    
    std::cout << "Test #4 Initial Processors:\t";
    PrintVector(TestFourProcessors);

    Scheduler::Balance(TestFourProcessors, TestFourJobs);
    
    // Result should be 0->500, 1->285
    std::cout << "Test #4 Final Processors:\t";
    PrintVector(TestFourProcessors);


    return 0;
}