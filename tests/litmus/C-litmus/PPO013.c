// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/PPO013.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 
volatile int atom_1_r6_0; 

void *t0(void *arg){
label_1:;
  vars[0] = 1;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  int v3_cmpeq = (v2_r1 == v2_r1);
  if (v3_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  int v5_r3 = vars[2];
  int v7_r5 = vars[2];
  int v8_cmpeq = (v7_r5 == v7_r5);
  if (v8_cmpeq)  goto lbl_LC01; else goto lbl_LC01;
lbl_LC01:;

  int v10_r6 = vars[0];
  int v14 = (v2_r1 == 1);
  atom_1_r1_1 = v14;
  int v15 = (v10_r6 == 0);
  atom_1_r6_0 = v15;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[1] = 0;
  vars[2] = 0;
  vars[0] = 0;
  atom_1_r1_1 = 0;
  atom_1_r6_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v11 = atom_1_r1_1;
  int v12 = atom_1_r6_0;
  int v13_conj = v11 & v12;
  if (v13_conj == 1) assert(0);
  return 0;
}