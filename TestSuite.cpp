//
// Created by Simon on 09.10.2022.
//

#include <iostream>
#include "TestSuite.h"
#include "RSelect.h"
#include <iostream>
#include <fstream>
#include <algorithm>

TestSuite::TestSuite(size_t initial_array_size, int k) {
    int seed = (std::time(nullptr));
    this->rng = std::mt19937(seed);
    this->k = k;
    this->initial_size = initial_array_size;

}
//set i to negative value for random i selection
void TestSuite::start_test_suite(std::string filename,int order, int samples) {
    std::ofstream test_file;
    test_file.open(filename);
    for (int i = 0; i < samples; ++i) {
        size_t curr_size = this->initial_size;
        start = clock();
        for (int j = 0; j < k/curr_size; ++j) {
            RSelect r = RSelect(curr_size);

            std::uniform_int_distribution<int> uni(0,curr_size-1); // unbiased random selection
            if(order==-1){
                r.r_select_primer(uni(rng));
            }else if(order == 1){
                r.r_select_primer(0);
            }else if(order ==-2){
                //do nothing for rempl test
            }else{
                r.r_select_primer(curr_size/order);
            }

        }
        end = clock();
        float t = ((float) end - start)/CLOCKS_PER_SEC;
        test_file << t << "," << curr_size << "\n";
        this->initial_size *= 1.5;
    }
    test_file.close();
}
void TestSuite::start_test_suite_tri(std::string filename,int order, int samples) {
    std::ofstream test_file;
    test_file.open(filename);
    std::uniform_int_distribution<int> uni(0,UINT16_MAX); // unbiased random selection
    for (int i = 0; i < samples; ++i) {
        size_t curr_size = this->initial_size;
        start = clock();
        for (int j = 0; j < k/curr_size; ++j) {
            std::vector<uint16_t> test_vector(this->initial_size);
            for(int k = 0; k<test_vector.size();k++){
                uint16_t  a = uni(rng);
                test_vector[k] = a;
            }
            std::sort(test_vector.begin(),test_vector.end());
        }
        end = clock();
        float t = ((float) end - start)/CLOCKS_PER_SEC;
        test_file << t << "," << curr_size << "\n";
        this->initial_size *= 1.5;
    }
    test_file.close();
}