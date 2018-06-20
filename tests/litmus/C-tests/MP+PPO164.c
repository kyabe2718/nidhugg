/* Copyright (C) 2018 Magnus Lång and Tuan Phong Ngo
 * This benchmark is part of SWSC */

#include <assert.h>
#include <stdint.h>
#include <stdatomic.h>
#include <pthread.h>

atomic_int vars[4]; 
atomic_int atom_1_r1_1; 
atomic_int atom_1_r13_0; 

void *t0(void *arg){
label_1:;
  atomic_store_explicit(&vars[0], 1, memory_order_seq_cst);

  atomic_store_explicit(&vars[1], 1, memory_order_seq_cst);
  return NULL;
}

void *t1(void *arg){
label_2:;
  int v2_r1 = atomic_load_explicit(&vars[1], memory_order_seq_cst);
  int v4_r3 = atomic_load_explicit(&vars[1], memory_order_seq_cst);
  int v5_r4 = v4_r3 ^ v4_r3;
  int v8_r5 = atomic_load_explicit(&vars[2+v5_r4], memory_order_seq_cst);
  int v10_r7 = atomic_load_explicit(&vars[2], memory_order_seq_cst);
  int v11_r8 = v10_r7 ^ v10_r7;
  int v14_r9 = atomic_load_explicit(&vars[3+v11_r8], memory_order_seq_cst);
  int v16_r11 = atomic_load_explicit(&vars[3], memory_order_seq_cst);
  int v17_r12 = v16_r11 ^ v16_r11;
  int v20_r13 = atomic_load_explicit(&vars[0+v17_r12], memory_order_seq_cst);
  int v24 = (v2_r1 == 1);
  atomic_store_explicit(&atom_1_r1_1, v24, memory_order_seq_cst);
  int v25 = (v20_r13 == 0);
  atomic_store_explicit(&atom_1_r13_0, v25, memory_order_seq_cst);
  return NULL;
}

int main(int argc, char *argv[]){
  pthread_t thr0; 
  pthread_t thr1; 

  atomic_init(&vars[1], 0);
  atomic_init(&vars[3], 0);
  atomic_init(&vars[2], 0);
  atomic_init(&vars[0], 0);
  atomic_init(&atom_1_r1_1, 0);
  atomic_init(&atom_1_r13_0, 0);

  pthread_create(&thr0, NULL, t0, NULL);
  pthread_create(&thr1, NULL, t1, NULL);

  pthread_join(thr0, NULL);
  pthread_join(thr1, NULL);

  int v21 = atomic_load_explicit(&atom_1_r1_1, memory_order_seq_cst);
  int v22 = atomic_load_explicit(&atom_1_r13_0, memory_order_seq_cst);
  int v23_conj = v21 & v22;
  if (v23_conj == 1) assert(0);
  return 0;
}