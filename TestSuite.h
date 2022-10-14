//
// Created by Simon on 09.10.2022.
//

#ifndef FTP_ALG_TP1_TESTSUITE_H
#define FTP_ALG_TP1_TESTSUITE_H


#include <cstddef>
#include <ctime>
#include <random>

class TestSuite {
    public:
        TestSuite(size_t initial_array_size, int k);
        void start_test_suite(std::string filename,int i,int samples);
        void start_test_suite_tri(std::string filename,int i,int samples);
    private:
        int k;
        clock_t start, end;
        size_t initial_size;
        std::mt19937 rng;//random number engine

};


#endif //FTP_ALG_TP1_TESTSUITE_H
