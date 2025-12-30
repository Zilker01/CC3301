#include <string.h>

// T5

void sort(unsigned int *nums, int n) {
  unsigned int *ult= &nums[n-1];
  unsigned int *p= nums;
  while (p<ult) {
    // No modifique nada arriba de esta linea
    // Inicio de la parte que debe cambiar

    unsigned int num1 = p[0];
    unsigned int num2 = p[1];
    int t3 = 0;
    int t2 = 0;
    int bit_anterior = 0;

    while (num1 > 0){
      int bit_actual = num1 & 1;
      if(bit_anterior == 0 && bit_actual == 1){
        t2++;
        bit_anterior = bit_actual;
        num1 = num1 >> 1;
      }
      else{
        bit_anterior = bit_actual;
        num1 = num1 >> 1;
      }
    }

    bit_anterior = 0;

    while (num2 > 0){
      int bit_actual = num2 & 1;
      if(bit_anterior == 0 && bit_actual == 1){
        t3++;
        bit_anterior = bit_actual;
        num2 = num2 >> 1;
      }
      else{
        bit_anterior = bit_actual;
        num2 = num2 >> 1;
      }
    }

    int t1 = t2 <= t3 ? 0 : 1;

    // Fin de la parte que debe cambiar
    // No Cambie nada mas a partir de aca
    if (t1 <= 0)
      p++;
    else {
      unsigned int tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= nums;
    }
  }
}
