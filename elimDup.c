#include <stdio.h>
#include <stdlib.h>

#include "elimDup.h"

// T3

void elimDup(Nodo *L){
  while (L != NULL && L->prox != NULL){
    if(L->x == L->prox->x){
      Nodo *temp = L->prox;
      L->prox = L->prox->prox;
      free(temp);
  }
  else{
    L = L->prox;
  }
}
}
