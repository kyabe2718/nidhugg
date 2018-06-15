// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/safe400.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[3]; 
volatile int atom_0_r1_1; 
volatile int atom_1_r1_1; 
volatile int atom_1_r3_0; 
volatile int atom_2_r3_0; 

void *t0(void *arg){
label_1:;
  int v2_r1 = vars[0];

  vars[1] = 1;
  int v16 = (v2_r1 == 1);
  atom_0_r1_1 = v16;
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v4_r1 = vars[1];

  int v6_r3 = vars[2];
  int v17 = (v4_r1 == 1);
  atom_1_r1_1 = v17;
  int v18 = (v6_r3 == 0);
  atom_1_r3_0 = v18;
  return NULL;
}

void *t2(void *arg){
label_3:;
  vars[2] = 1;

  int v8_r3 = vars[0];
  int v19 = (v8_r3 == 0);
  atom_2_r3_0 = v19;
  return NULL;
}

void *t3(void *arg){
label_4:;
  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 
  pthread_t thr2; 
  pthread_t thr3; 

  vars[2] = 0;
  vars[0] = 0;
  vars[1] = 0;
  atom_0_r1_1 = 0;
  atom_1_r1_1 = 0;
  atom_1_r3_0 = 0;
  atom_2_r3_0 = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);
  pthread_create(&thr2, NULL, t2, NULL);
  pthread_create(&thr3, NULL, t3, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  int v9 = atom_0_r1_1;
  int v10 = atom_1_r1_1;
  int v11 = atom_1_r3_0;
  int v12 = atom_2_r3_0;
  int v13_conj = v11 & v12;
  int v14_conj = v10 & v13_conj;
  int v15_conj = v9 & v14_conj;
  if (v15_conj == 1) assert(0);
  return 0;
}