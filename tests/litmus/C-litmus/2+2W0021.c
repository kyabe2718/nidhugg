// /home/osboxes/nidhugg_tests/gen-litmuts/power-tests/2+2W0021.litmus

#include <assert.h>
#include <stdint.h>
#include <pthread.h>

volatile int vars[4]; 

void *t0(void *arg){
label_1:;
  vars[0] = 2;

  vars[1] = 1;
  return NULL;
}

void *t1(void *arg){
label_2:;
  vars[1] = 2;
  int v2_r3 = vars[2];
  int v3_r5 = v2_r3 ^ v2_r3;
  int v6_r6 = vars[3+v3_r5];
  int v7_cmpeq = (v6_r6 == v6_r6);
  if (v7_cmpeq)  goto lbl_LC00; else goto lbl_LC00;
lbl_LC00:;
  vars[0] = 1;
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  vars[0] = 0;
  vars[2] = 0;
  vars[1] = 0;
  vars[3] = 0;

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v8 = vars[0];
  int v9 = (v8 == 2);
  int v10 = vars[1];
  int v11 = (v10 == 2);
  int v12_conj = v9 & v11;
  if (v12_conj == 1) assert(0);
  return 0;
}