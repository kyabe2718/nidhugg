// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/S+PPO695.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_1_r1_1; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = vars[1];
  vars[1] = 2;
  int v4_r4 = vars[1];
  int v6_r5 = vars[1];
  int v7_r6 = v6_r5 ^ v6_r5;
  int v8_r6 = v7_r6 + 1;
  vars[2] = v8_r6;
  int v10_r8 = vars[2];
  int v11_cmpeq = (v10_r8 == v10_r8);
  if (v11_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[0] = 1;
  int v19 = (v2_r1 == 1);
  atom_1_r1_1 = v19;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[1] = 0;
  vars[2] = 0;
  atom_1_r1_1 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v12 = vars[0];
  int v13 = (v12 == 2);
  int v14 = vars[1];
  int v15 = (v14 == 2);
  int v16 = atom_1_r1_1;
  int v17_conj = v15 & v16;
  int v18_conj = v13 & v17_conj;
  if (v18_conj == 1) assert(0);
  return 0;
}