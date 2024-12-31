#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <iostream>

#include "Thermal.h"

typedef struct _thread_data_ {
  DeviceBase* pDevice;
  int iCommand;
} thread_param;

int main(int argc, char* argv[]) {
  Thermal thermal;
  pthread_t tids[2];
  thread_param threadPram[2];
  thermal.GetImage();
  return 0;
}