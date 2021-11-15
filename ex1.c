#include "ex1.h"
/**
 * get the type of endian the current machine works on.
 * @return
 */
int is_big_endian(){
    unsigned long i = 1;
    /** get the first byte of long number. the size of char is 1 byte so a pointer to it is a pointer to the first
    byte in the order of the system's memory. **/

    char* c = (char*) &i;
    /**
     * 1  binary representation is 00..1. if we get 1 it means the first byte is the lsb,
     * which means small endian if we get 0, the first byte is msb which means big endian.**/
    if ((int) *c == 1){
        return 0;
    } else{
        return 1;
    }
}
/**
 *merge the first half iof bytes from x and the second half from y
 * @param x num
 * @param y num
 * @return new num with half of byte of x and the other half of y
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y){
    unsigned long maskForLeft = 1;
    unsigned long maskForRight = 0;
    unsigned long final = 0;
    int size = sizeof(long);
    unsigned long num1 = 1;
    //create the bitmask for the left half
    for (int i = 1; i < (size)*4; ++i) {
        maskForLeft = maskForLeft | (num1<<=1);
    }
    unsigned long tmp = maskForLeft;
    tmp<<=(size*4);
    maskForRight = tmp;
    //create the bitmask for the right half
    //& arithmetic operation, makes sure that only the bits in the mask will be on- the first or second half.
    y = y&maskForLeft;
    x = x&maskForRight;
    // | arithmetic operation  with 0 will 'copy' the numbers after they were masked
    final = final | x;
    final = final | y;
    return final;
}

/**
 * change the i byte of x with b
 * @param x num
 * @param b  part to replace
 * @param i the location in x to replace
 * @return
 */
unsigned long put_byte(unsigned long x, unsigned char b, int i){
    //get the first byte of x
    char* pToByte = (char*) &x;
    //if it big endian go i bytes because W-8 - i = i when looking backwards
    if (is_big_endian()){
        for (int j=0; j<i; j++){
            pToByte++;
        }
        //small endian, so go W/8-1-i bytes (assuming we use 64 bit system so 64/8 - 1 - i
    } else{
        for (int j=0; j<7-i; j++){
            pToByte++;
        }
    }
    *pToByte = b;
return x;
}
