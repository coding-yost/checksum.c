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

//for loop creating the complement
for (int i = 0; i < count; i++) {
    carry = 0;
    if (i == 5) {checksum = header[i]; header[i] = 0;}
    if (sum > max_int + 1) {carry++;}
    else {sum = sum + header[i] + carry;}
}


    fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }

  return 0;
}