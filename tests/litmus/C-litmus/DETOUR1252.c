// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR1252.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[2]; 
volatile int atom_0_r5_2; 
volatile int atom_1_r3_3; 
volatile int atom_1_r5_4; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;

  int v2_r5 = vars[1];
  int v17 = (v2_r5 == 2);
  atom_0_r5_2 = v17;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  int v4_r3 = vars[1];
  vars[1] = 4;
  int v6_r5 = vars[1];
  int v7_r6 = v6_r5 ^ v6_r5;
  int v8_r6 = v7_r6 + 1;
  vars[0] = v8_r6;
  int v18 = (v4_r3 == 3);
  atom_1_r3_3 = v18;
  int v19 = (v6_r5 == 4);
  atom_1_r5_4 = v19;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[1] = 3;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  atom_0_r5_2 = 0;
  atom_1_r3_3 = 0;
  atom_1_r5_4 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v9 = atom_0_r5_2;
  int v10 = vars[0];
  int v11 = (v10 == 2);
  int v12 = atom_1_r3_3;
  int v13 = atom_1_r5_4;
  int v14_conj = v12 & v13;
  int v15_conj = v11 & v14_conj;
  int v16_conj = v9 & v15_conj;
  if (v16_conj == 1) assert(0);
  return 0;
}