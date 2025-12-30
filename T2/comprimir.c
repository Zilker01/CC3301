#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comprimir.h"

// T2

void comprimir(char *str) {
    if (*str == 0) return;

    char *read = str;
    char *write = str;

    while (*read) {  // Loop over each character
        char current = *read;
        int cnt = 0;

        while (*read == current) {  // Count repeated characters
            cnt++;
            read++;
        }

        if (cnt > 1) *write++ = '0' + cnt;  // Write count if >1
        *write++ = current;                 // Write character
    }

    *write = '\0';  // Null-terminate string
}

char *comprimido(char *str){
  char *temp = str;
  int len = 1;

  // First pass: calculate length of compressed string
  while (*temp){
    char current = *temp++;
    int temp_cnt = 1;
    while (*temp == current){ // Count repetitions
      temp_cnt++;
      temp++;
    }
    if (temp_cnt > 1){ // Count + character
      len += 2;        // Single character
    }
    else{
      len += 1;         
    }  
  }
  char *new_str = malloc(len + 1);
  char *write = new_str;

  // Second pass: build compressed string
  while (*str){
    int cnt = 1;
    char current = *str;
    str++;

    while(*str == current){
      cnt++;
      str++;
    }
    if (cnt > 1){           // Write count and character
      *write++ = '0' + cnt;
      *write++ = current;
    }
    if (cnt == 1){          // Write single character
      *write++ = current;
    }
  }
  *write = '\0';
  return new_str;
}
