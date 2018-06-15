// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/Z6.5+sync+rfi-data+sync.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r3_2; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  int v2_r3 = vars[1];
  int v3_r4 = v2_r3 ^ v2_r3;
  int v4_r4 = v3_r4 + 1;
  vars[2] = v4_r4;
  int v16 = (v2_r3 == 2);
  atom_1_r3_2 = v16;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[2] = 2;

  int v6_r3 = vars[0];
  int v17 = (v6_r3 == 0);
  atom_2_r3_0 = v17;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  atom_1_r3_2 = 0;
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v7 = vars[1];
  int v8 = (v7 == 2);
  int v9 = vars[2];
  int v10 = (v9 == 2);
  int v11 = atom_1_r3_2;
  int v12 = atom_2_r3_0;
  int v13_conj = v11 & v12;
  int v14_conj = v10 & v13_conj;
  int v15_conj = v8 & v14_conj;
  if (v15_conj == 1) assert(0);
  return 0;
}