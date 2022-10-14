//
// Created by Simon on 09.10.2022.
//

#include <iostream>
#include <utility>
#include "RSelect.h"

RSelect::RSelect(int n) {
    int seed = (std::time(nullptr));
    this->rng = std::mt19937(seed);
    std::uniform_int_distribution<int> uni(0,UINT16_MAX); // unbiased random selection
    this->input_space = std::vector<uint16_t>(n);
    for(int i = 0; i<input_space.size();i++){
        uint16_t  a = uni(rng);
        this->input_space[i] = a;
    }
}

int RSelect::r_select(int start, int end, int order_statistic) {
    if(start==end)return this->input_space[order_statistic];
    std::uniform_int_distribution<int> uni(start,end); // unbiased random selection
    int pivot =uni(rng);
    uint16_t pivot_value = this->input_space[pivot];
    //swap the last elt with the pivot
    this->input_space[pivot] = this->input_space[end];
    this->input_space[end] = pivot_value;
    int smallest_elt_idx=start-1;

    for(int i = start;i<end;i++){
        uint16_t curr_val = this->input_space[i];
        if(curr_val <= pivot_value){//the current value is lesser or equal than the pivot value
            smallest_elt_idx++;
            this->input_space[i] = this->input_space[smallest_elt_idx];
            this->input_space[smallest_elt_idx] = curr_val;
        }
    }
    int pivot_index = smallest_elt_idx+1;
    this->input_space[end] = this->input_space[pivot_index];
    this->input_space[pivot_index] = pivot_value;
    if(pivot_index ==order_statistic)return pivot_value;
    if(order_statistic<pivot_index){
        return r_select(start,pivot_index-1,order_statistic);
    }else{
        return r_select(pivot_index+1,end,order_statistic);
    }
}

int RSelect::r_select_primer(int order_statistic) {
    return r_select(0,this->input_space.size()-1,order_statistic);
}

RSelect::RSelect(std::vector<uint16_t> input) {//pass by value -> so copied, we can move it to input_space;
    input_space=std::move(input);
}
