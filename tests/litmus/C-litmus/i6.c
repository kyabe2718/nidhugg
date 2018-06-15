// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/i6.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_1_r1_1; 
volatile int atom_2_r2_1; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[0];
  int v3_r9 = v2_r1 ^ v2_r1;
  vars[1+v3_r9] = 1;
  int v15 = (v2_r1 == 1);
  atom_1_r1_1 = v15;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v5_r2 = vars[1];
  int v6_r9 = v5_r2 ^ v5_r2;
  int v9_r3 = vars[0+v6_r9];
  int v16 = (v5_r2 == 1);
  atom_2_r2_1 = v16;
  int v17 = (v9_r3 == 0);
  atom_2_r3_0 = v17;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_2_r2_1 = 0;
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v10 = atom_1_r1_1;
  int v11 = atom_2_r2_1;
  int v12 = atom_2_r3_0;
  int v13_conj = v11 & v12;
  int v14_conj = v10 & v13_conj;
  if (v14_conj == 1) assert(0);
  return 0;
}