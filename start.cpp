#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <random>
#include "LRU.cpp"

void _run()
{
    std::random_device rd;
    int random_num;
    page_table process[10];
    for(int i = 0; i < 10; ++i) {
        process[i].symbol = 0;
        process[i].ex_sto_num = i;
        process[i].number = i;
        process[i].memory_num = 0;
    }
    URL* pro = new URL();
    int count = 10, cnt = 0;
    while(cnt < count) {
        random_num = rd() % 10;
        usleep(random_num);
        pro->running_call(random_num);
        std::cout<<"process "<<random_num<<" is called"<<std::endl;
        pro->print_apro();
        std::cout<<"memory stack contains:"<<std::endl;
        print_memory(*pro);
        cnt++;
    }
}

extern "C" {
    void run_()
    {
        _run();
    }
}
