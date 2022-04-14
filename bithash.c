#include <stdio.h>

#define TestBit(A,k)    ( A[(k/32)] & (1 << (k%32)) )
#define SetBit(A,k)     ( A[(k/32)] |= (1 << (k%32)) ) 

int main()
{
    unsigned int A[4] = {0};
    unsigned int B[4] = {0};
    
    char string1[] = "Memory leak";
    char string2[] = "Kernel Panic";
    char string3[] = "abacbcdgefg";
    
    int ascii;
    int  i = 0;
 
  # using bitwise hashtable, to find the common characters between 2 strings
  
    while (string1[i] != '\0') {   
        ascii = string1[i];
        SetBit(A,ascii);
        i++;
    }

    i = 0;
    while (string2[i] != '\0') {      
        ascii = string2[i];
        if (TestBit(A,ascii)) {
            printf("%c\n", string2[i]);
        }
        i++;
    }
    
    printf("====\n");
  
  # using bitwise hashtable, to remove the duplicated characters in a string
  
    i = 0;
    while (string3[i] != '\0') {      
        ascii = string3[i];
        if (!TestBit(B,ascii)) {
            printf("%c", string3[i]);
            SetBit(B,ascii);
        }
        i++;
    }   
    
    
    return 0;
}
