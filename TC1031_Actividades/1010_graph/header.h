

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <sys/types.h>
#include <string>
#include <vector>

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long int lli;

class Chronometer {
private:
  timeval startTime;
  bool 	started;

public:
  Chronometer() :started(false) {}

  void start(){
    started = true;
    gettimeofday(&startTime, NULL);
  }

  double stop(){
    timeval endTime;
    long seconds, useconds;
    double duration = -1;

    if (started) {
      gettimeofday(&endTime, NULL);

      seconds  = endTime.tv_sec  - startTime.tv_sec;
      useconds = endTime.tv_usec - startTime.tv_usec;

      duration = (seconds * 1000.0) + (useconds / 1000.0);
      started = false;
    }
    return duration;
  }
};


template <class T>
void swap(T *A, int i, int j) {
  T aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

template <class T>
void swap(std::vector<T> &v, int i, int j) {
  T aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

template <class T>
std::string arr2str(T *A, int size) {
  std::stringstream aux;

  aux << "[" << A[0];
  for (int i = 1; i < size; i++) {
    aux << ", " << A[i];
  }
  aux << "]";
  return aux.str();
}

template <class T>
std::string vec2str(const std::vector<T> &v) {
	std::stringstream aux;

  aux << "[" << v[0];
  for (int i = 1; i < v.size(); i++) {
    aux << ", " << v[i];
  }
  aux << "]";
  return aux.str();
}

#endif
