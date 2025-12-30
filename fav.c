#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


#include "fav.h"

// T7

int favorables_par(int n, int sum, int rep, int p) {
  int pids[p];
  int fds[p][2];
  int bloque = rep/p; // Repeticiones para cada core
  for(int i = 0; i < p; i++){
    pipe(fds[i]);
    init_rand_seed();
    pids[i] = fork();
    if (pids[i] == 0){ // hijo
      close(fds[i][0]);
      int res = favorables(n, sum, bloque);
      write(fds[i][1], &res, sizeof(int));
      exit(0);
    }
    else{
      close(fds[i][1]); // padre
    } 
  }

  int res = 0;
  for (int i = 0; i < p; i++){
    int res_hijo;
    read(fds[i][0], &res_hijo, sizeof(int));
    close(fds[i][0]);
    waitpid(pids[i], NULL, 0);
    res += res_hijo;
  }
  return res;
}

