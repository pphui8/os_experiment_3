#ifndef _URL_
#define _URL_

#include "structure.h"
#include "cstring"

class URL;

void
    print_memory(URL&);
void
    run();
void
    _run();

class URL {
public:
    URL():exist_process(0) {
        for(int i = 0; i < 10; ++i) {
            all_pro[i].symbol = 0;
            all_pro[i].ex_sto_num = i;
            all_pro[i].number = i;
            all_pro[i].memory_num = 0;
        }
        for(int i = 0; i < 4; ++i) page_memory[i].number = 0;
    }
    void running_call(int);
    void print_apro();
private:
    int exist_process;
    page_table page_memory[4];
    page_table all_pro[10];

    friend void print_memory(URL&);
};

inline void
URL::running_call(int pro)
{
    if(exist_process < 3) {
        for(int i = 0; i <= exist_process; ++i) {
            if(pro == page_memory[i].number) {   //作业已存在
                if(0 == i) {
                    page_table tmp = page_memory[i];
                    page_memory[0] = page_memory[1];
                    page_memory[1] = page_memory[2];
                    page_memory[2] = tmp;
                }
                else if(1 == i) {
                    page_table tmp = page_memory[i];
                    page_memory[1] = page_memory[2];
                    page_memory[2] = tmp;
                }
                exist_process--;
                return;
            }
        }
        //作业不存在
        all_pro[pro].symbol = 1;
        all_pro[pro].memory_num = 3;
        page_memory[exist_process] = all_pro[pro];
        exist_process++;
    }
    else {
        //去掉最久作业
        all_pro[page_memory[0].number].symbol = 0;
        for(int i = 1; i < 4; ++i) page_memory[i - 1] = page_memory[i];
        for(int i = 0; i <= exist_process - 1; ++i) {
            if(pro == page_memory[i].number) {   //作业已存在
                if(0 == i) {
                    page_table tmp = page_memory[i];
                    page_memory[0] = page_memory[1];
                    page_memory[1] = page_memory[2];
                    page_memory[2] = tmp;
                }
                else if(1 == i) {
                    page_table tmp = page_memory[i];
                    page_memory[1] = page_memory[2];
                    page_memory[2] = tmp;
                }
                exist_process--;
                return;
            }
        }
        //作业不存在
        all_pro[pro].symbol = 1;
        all_pro[pro].memory_num = 3;
        page_memory[exist_process] = all_pro[pro];
        exist_process++;
    }
}

#include <iostream>
inline void
URL::print_apro()
{
    std::cout<<"pro num"<<'\t'<<"status"<<'\t'<<"ex mem"<<' '<<"mem loc"<<std::endl;
    for(int i= 0; i < 10; ++i) {
        std::cout<<all_pro[i].number<<'\t'<<all_pro[i].symbol<<'\t'<<all_pro[i].ex_sto_num<<"   \t"<<all_pro[i].memory_num<<std::endl;
    }
}

inline void
print_memory(URL& p)
{
    int resout[3];
    int cnt = 0;
    if(p.exist_process == 3) {
        for(int i = 1; i < 4; ++i) std::cout<<p.page_memory[i].symbol<<' ';
    }
    else for(int i = 0; i < 3; ++i) std::cout<<p.page_memory[i].symbol<<' ';
    std::cout<<std::endl;
}

#endif  //_URL_
