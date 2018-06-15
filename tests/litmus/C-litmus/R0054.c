// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/R0054.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 
volatile int atom_1_r7_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  vars[2] = 1;
  int v2_r5 = vars[3];
  int v4_r7 = vars[0];
  int v9 = (v4_r7 == 0);
  atom_1_r7_0 = v9;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[3] = 0;
  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  atom_1_r7_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v5 = vars[1];
  int v6 = (v5 == 2);
  int v7 = atom_1_r7_0;
  int v8_conj = v6 & v7;
  if (v8_conj == 1) assert(0);
  return 0;
}