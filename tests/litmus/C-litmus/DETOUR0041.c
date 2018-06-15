// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/DETOUR0041.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r3_0; 
volatile int atom_0_r6_1; 
volatile int atom_1_r1_1; 
volatile int atom_1_r4_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;
  int v2_r3 = vars[1];
  vars[1] = 1;
  int v4_r6 = vars[1];
  int v5_r7 = v4_r6 ^ v4_r6;
  vars[2+v5_r7] = 1;
  int v19 = (v2_r3 == 0);
  atom_0_r3_0 = v19;
  int v20 = (v4_r6 == 1);
  atom_0_r6_1 = v20;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v7_r1 = vars[2];
  int v8_r3 = v7_r1 ^ v7_r1;
  int v11_r4 = vars[0+v8_r3];
  int v21 = (v7_r1 == 1);
  atom_1_r1_1 = v21;
  int v22 = (v11_r4 == 0);
  atom_1_r4_0 = v22;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[2] = 0;
  vars[1] = 0;
  atom_0_r3_0 = 0;
  atom_0_r6_1 = 0;
  atom_1_r1_1 = 0;
  atom_1_r4_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v12 = atom_0_r3_0;
  int v13 = atom_0_r6_1;
  int v14 = atom_1_r1_1;
  int v15 = atom_1_r4_0;
  int v16_conj = v14 & v15;
  int v17_conj = v13 & v16_conj;
  int v18_conj = v12 & v17_conj;
  if (v18_conj == 1) assert(0);
  return 0;
}