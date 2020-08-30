/**
 *  @author Jonathan Abbott
 *  @date   Aug 30, 2020
 * 
 *  This file includes all the implementation details for the scheduling algorithm that
 *  uses QuickSort for CC2.
 */


#include <iostream> // std::ostream
#include <vector>   // std::vector
#include <queue>    // std::priority_queue

#include "Quick.h"  // Quick::Sort


// Classic define guards to avoid multiple-definition.
#ifndef CC2_SCHEDULER_H_
#define CC2_SCHEDULER_H_


/**
 *  `Processor` struct to demonstrate divying tasks up to an assortment of "workers."
 *  The reason this was chosen and not a simple `uint64_t` vector is because it (1) tags
 *  each processor with an `id` that can be recovered after the load balancing and (2)
 *  it allows a vector of `Processor`s to be passed in with possibly non-zero `time`s.
 */
struct Processor {
    // These members are by default public.
    uint64_t id;
    uint64_t time;

    // Constructor. Need not define others for proof-of-concept.
    Processor(uint8_t inId, uint64_t inTime)
        : id(inId), time(inTime) {}
};


/**
 *  Implemented so that the `priority_queue` later on can put the `Processor` with
 *  the lightest load at the front of the queue. (i.e. through `std::greater`)
 * 
 *  @param p1 The left-side of the `>` comparison.
 *  @param p2 The right-side of the `>` comparison.
 */
bool operator > (const Processor & p1, const Processor & p2) {
    return p1.time > p2.time;
}


/**
 *  Implemented so that `Processor` can be directly piped to stdout.
 *  Usage: std::cout << MyProcessor << std::endl;
 *  
 *  @param os i.e. `std::cout` in usage "std::cout << MyProcessor"
 *  @param p The `MyProcessor` in the above example.
 */
std::ostream & operator << (std::ostream & os, const Processor & p) {
    os << "Processor(id: " << p.id << ", " << "time: " << p.time << ")";
    return os;
}


/**
 *  Namespace that contains the load balancing algorithms.
 */
namespace Scheduler {


    /**
     *  Given a vector of available processors with busy-times, allocate given tasks in vector
     *  among processors, so that the total completion of these tasks are minimized. Note: 
     *  this function returns through call-by-reference, and `tasks` parameter is sorted.
     *  It is not copied because of the cost of that operation. Whether or not this is OK depends
     *  on the context.
     * 
     *  @param processors The vector of processors that `tasks` will be distributed upon.
     *  @param tasks The vector of tasks that will be distributed among `processors`.
     */
    void Balance(std::vector<Processor> & processors, std::vector<uint64_t> & tasks) {
        
        // First, create priority queue with processors param.
        // Ideally, the processors would already be in a priority queue. But this is a
        // proof-of-concept.
        std::priority_queue<Processor, std::vector<Processor>, std::greater<Processor>> pq(
            processors.begin(), processors.end()
        );
        

        // Sort the tasks into ascending order.
        Quick::Sort(tasks);


        // Now, iterate from longest job to shortest job.
        for (std::vector<uint64_t>::reverse_iterator it = tasks.rbegin(); it != tasks.rend(); ++it) {
            
            // Pop processor that's least busy.
            Processor proc = pq.top();
            pq.pop();

            // Add job to it.
            proc.time += *it;

            // And re-add to the queue.
            pq.push(proc);
        }


        // Now, overwrite processors with new information.
        // Note, this is only done because this is a proof-of-concept! Obviously,
        // this is inefficient.
        processors.clear();
        while (not pq.empty()) {
            processors.push_back(pq.top());
            pq.pop();
        }
    }
}

#endif