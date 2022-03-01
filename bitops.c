#include <stdio.h>

/* Function to print out the bits in binary
   representation of positive integer x */
void printBits(unsigned int x)
{
    int i;
    for(i=8*sizeof(x)-1; i>=0; i--) {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

/* Function to get no of set bits in binary
   representation of positive integer x */
unsigned int countSetBits(unsigned int x)
{
    unsigned int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

/* Function to reverse the order of bits in binary
   representation of positive integer x */
unsigned int revBits(unsigned int x)
{
    unsigned int result = 0;
    unsigned int bitlen = (sizeof (x)) * 8;

    for (;bitlen--; x >>= 1)
    {
      result <<= 1;
      result |= (x & 1);
    }
    return result;
}   
   
int main ()
{
    unsigned int orig = 0b01001011010010110100101101001011;
    unsigned int res = 0;

    printf("original: %d\n", orig);
    printBits(orig);    

    res = revBits(orig);
    printf("reverse bits: %d\n", res);
    printBits(res);
    printf("count bits: %d\n", countSetBits(res));
    
    return 0;
}
