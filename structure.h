#ifndef _STRUCTURE_
#define _STRUCTURE_

typedef struct page_table {
    //页号
    int number;
    //标志0: ex, 1: mem
    int symbol;
    //主存块号
    int memory_num;
    //外存地址
    int ex_sto_num;
} page_table;

#endif  //_STRUCTURE_
