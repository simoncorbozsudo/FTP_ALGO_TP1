//
// Created by Simon on 09.10.2022.
//
#ifndef FTP_ALG_TP1_RSELECT_H
#define FTP_ALG_TP1_RSELECT_H


#include <vector>
#include <ctime>
#include <random>


class RSelect {
    public:
        RSelect(int n);
        RSelect(std::vector<uint16_t> input);
        int r_select_primer(int order_statistic);
    private:
        std::vector<uint16_t> input_space;
        std::mt19937 rng;//random number engine
        int r_select(int start,int end, int order_statistic);
};


#endif //FTP_ALG_TP1_RSELECT_H
