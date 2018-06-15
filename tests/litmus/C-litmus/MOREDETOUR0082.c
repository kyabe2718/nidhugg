// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/MOREDETOUR0082.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_2_r1_3; 
volatile int atom_2_r4_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[1];
  int v3_r5 = v2_r3 ^ v2_r3;
  int v4_r5 = v3_r5 + 1;
  vars[2] = v4_r5;
  vars[2] = 3;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v6_r1 = vars[2];
  vars[2] = 2;
  int v21 = (v6_r1 == 1);
  atom_1_r1_1 = v21;
  return NULL;
}

void *t2(void *arg){
label_3:;
  int v8_r1 = vars[2];
  int v9_r3 = v8_r1 ^ v8_r1;
  int v12_r4 = vars[0+v9_r3];
  int v22 = (v8_r1 == 3);
  atom_2_r1_3 = v22;
  int v23 = (v12_r4 == 0);
  atom_2_r4_0 = v23;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 

  vars[1] = 0;
  vars[0] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;
  atom_2_r1_3 = 0;
  atom_2_r4_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  int v13 = vars[2];
  int v14 = (v13 == 3);
  int v15 = atom_1_r1_1;
  int v16 = atom_2_r1_3;
  int v17 = atom_2_r4_0;
  int v18_conj = v16 & v17;
  int v19_conj = v15 & v18_conj;
  int v20_conj = v14 & v19_conj;
  if (v20_conj == 1) assert(0);
  return 0;
}