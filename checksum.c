/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte unsigned char


int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0; 
  byte carry;  
  byte checksum; 
  byte complement;
  byte header[count];
  int retval = read(STDIN_FILENO, &header, count);
  

//for loop creating the complement
for (int i = 0; i < count; i++) {
    carry = 0;
    if (i == 5) {checksum = header[i]; header[i] = 0;}
    if (sum > max_int + 1) {sum = sum + header[i] + carry; sum - max_int; carry++;}
    else {sum = sum + header[i] + carry;}
}

int quotient = sum / (max_int + 1);     //Performs integer division on this sum using 2^8 as the divisor to yield both a quotient and a remainder. 
int remainder = sum % (max_int + 1);    //These values are then stored in the variables "quotient" and "remainder", respectively.  
sum = quotient + remainder;         //Adds the values of "quotient" and "remainder" together, and stores this value into the variable "sum".
complement = max_int - sum;         //Subtracts this new value of "sum" from 2^8-1, and stores the result in a variable called "complement".

fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
if (checksum != complement ) {
  fprintf(stderr, "Error Detected!\n"); 
  return 1;
}

  return 0;
}