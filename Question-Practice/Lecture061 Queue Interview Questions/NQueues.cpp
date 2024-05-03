#include <bits/stdc++.h>
class NQueue {
public:
  // Initialize your data structure.
  int s;
  int n;
  int free;
  int *next;
  int *arr;
  int *start;
  int *end;

  NQueue(int n, int s) {
    this->n = n;
    this->s = s;
    this->free = 0;
    this->arr = new int[s];

    this->next = new int[s];
    for (int i = 0; i < s ; i++) {
      this->next[i] = i + 1;
    }
    this->next[s - 1] = -1;

    this->start = new int[n];
    this->end = new int[n];
    for (int i = 0; i < n ; i++) {
      this->start[i] = -1;
      this->end[i] = -1;
    }
  }

  // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the
  // queue, and false otherwise. 
  bool enqueue(int x, int m) {
    if (free == -1)
      return false;

    int index = free;
    free = next[index];
    arr[index] = x;

    if (start[m - 1] == -1) {
      start[m - 1] = index;
    }else{
        next[end[m-1]] = index;
    }

    next[index] = -1;
    end[m - 1] = index;

    return true;
  }

  // Dequeues top element from Mth queue. Returns -1 if the queue  is empty,
  // otherwise returns the popped element.
  int dequeue(int m) {
    if (start[m - 1] == -1)
      return -1;

    int index = start[m-1];
    start[m-1] = next[index];
    next[index] =free;
    free = index;
    return arr[index];
  }
};