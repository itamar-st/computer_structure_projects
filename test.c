#include "ex1.h"
#include <stdio.h>
unsigned long test[10][2] =
    {
        {0x0000000000000abc, 0x0000000000000def},
        {0x0000000000000fbd, 0x0000000000001fcb},
        {0x0000000000000ef6, 0x0000000000000453},
        {0x1234562345adfcda, 0x000000032542dbae},
        {0x0000000cdcdbe685, 0x000000000000000f},
        {0x00000000abccafba, 0x00000000fdae4756},
        {0xaabbccddeeff1234, 0x4321ffeeddccbbaa},
        {0x000232355564cccc, 0x0000001245654654},
        {0x0123456789abcdef, 0x0},
        {0x5555555555555555, 0xf}
    };
void test_merge_bytes() {
    unsigned long result[10] = {0xdef,
                                0x1fcb,
                                0x453,
                                0x123456232542dbae,
                                0x0000000c0000000f,
                                0x00000000fdae4756,
                                0xaabbccddddccbbaa,
                                0x0002323545654654,
                                0x0123456700000000,
                                0x555555550000000f};
    int flag = 0;
    for (int i = 0; i < 10; ++i) {
        if (merge_bytes(test[i][0], test[i][1]) != result[i]) {
            printf("merge bytes test %d failed\n", i);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("passed all test for merge_bytes\n");
    }
}

void test_put_byte() {
    unsigned char test2[10] = {0xab,
                               0xcd,
                               0xef,
                               0x01,
                               0x23,
                               0x45,
                               0x67,
                               0x89,
                               0xba,
                               0xdc};
    unsigned long result[10] = {0xab00000000000abc,
                                0x00cd000000000fbd,
                                0x0000ef0000000ef6,
                                0x1234560145adfcda,
                                0x0000000c23dbe685,
                                0x00000000ab45afba,
                                0xaabbccddeeff6734,
                                0x000232355564cc89,
                                0xba23456789abcdef,
                                0x55dc555555555555};
    int flag = 0;
    for (int i = 0; i < 10; ++i) {
        if (put_byte(test[i][0], test2[i], i % 8) != result[i]) {
            printf("put bytes test %d failed\n", i);
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("passed all test for put_byte\n");
    }
}