/**
 *  @author Jonathan Abbott
 *  @date   September 7th, 2020
 *  
 *  This includes the `main` driver for `Lab4` for CSE 20312.
 */


#include <iostream> // std::cout


#include "../include/MergeInt.h" // interval_list_t, interval_t, MergeIntervals


/**
 *  The `main` driver for `Lab4`.
 *  @return An operating system exit code.
 */
int main() {

    
    // First given test by Prof. Morrison.
    interval_list_t TestOne{
        interval_t{1, 3}, interval_t{2, 6}, interval_t{8, 10}, interval_t{15, 18}
    };
    MergeIntervals::Test(TestOne);


    // Second given test by Prof. Morrison.
    interval_list_t TestTwo{
        interval_t{1, 4}, interval_t{4, 5}
    };
    MergeIntervals::Test(TestTwo);


    // Third test, self-created.
    interval_list_t TestThree{
        interval_t{1, 2}, interval_t{3, 4}, interval_t{5, 7}, interval_t{6, 9}, interval_t{8, 10}
    };
    MergeIntervals::Test(TestThree);


    // Fourth test, self-created and not in sorted order.
    interval_list_t TestFour{
        interval_t{5, 7}, interval_t{1, 4}, interval_t{11, 15}, interval_t{6, 9}
    };
    MergeIntervals::Test(TestFour);

    
    // `0` for Success.
    return 0;
}