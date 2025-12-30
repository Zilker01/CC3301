#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "elim-dup.h"

// Elimina dígitos hexadecimales consecutivos repetidos en un número de 64 bits.

uint64_t elimDup(uint64_t x) {
    uint64_t mask_base = 15;    // Máscara 15 = 0000 ... 1111 en binario, para aislar 4 bits (un dígito hexadecimal)
    uint64_t resultado = 0;     // Variable donde construiremos el número sin dígitos duplicados consecutivos
    uint64_t anterior = 129;    // Inicializamos con un valor imposible de 4 bits (0-15) para asegurar que el primer dígito se agregue
    int shift = 0;              // Desplazamiento de bits para colocar cada dígito en su posición correcta en el resultado


  // Iteramos en sizeof(x)*2 para tener un maximo de 16 iteraciones (cantidad de digitos hexadecimales)
  for (int i = 0; i < sizeof(x)*2; i++) {
      uint64_t actual = x & mask_base; // Aplicamos un y logico para aislar los ultimos 4 digitos de x

      // Si el numero actual es distinto al anterior, se agrega
      if (actual != anterior) { 
          resultado = resultado | (actual << shift); // Aplicamos un o logico entre el resultado y el digito actual para insertarlo
          anterior = actual;                         // Actualizamos el anterior
          shift = shift + 4;                         // Avanzamos 4 bits para agregar el siguiente digito hexadecimal
      }
      x = x >> 4; // Movemos el numero original 4 bits para actuar en su siguiente digito
  }

  return resultado; 
}
