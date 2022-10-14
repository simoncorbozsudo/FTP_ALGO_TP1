#include <iostream>
#include "RSelect.h"
#include "TestSuite.h"

int main() {
    //K = 60000000 should take around 2 secs
    int cases []= {-1,1,8,4,2};
    std::string filenames []= {"random_select_k60000000_irandom.csv",
                               "random_select_k60000000_i1.csv",
                               "random_select_k60000000_inOVER8.csv",
                               "random_select_k60000000_inOVER4.csv",
                               "random_select_k60000000_inOVER2.csv"};
    for (int i = 0; i < 5; ++i) {
        TestSuite t = TestSuite(1000,60000000*8 );
        t.start_test_suite(filenames[i],cases[i],25);
    }
    TestSuite a = TestSuite(1000,60000000 );
    a.start_test_suite_tri("sorted.csv",2,25);
    TestSuite b = TestSuite(1000,60000000 );
    b.start_test_suite("temps_rempl.csv",-2,25);
    return 0;
}