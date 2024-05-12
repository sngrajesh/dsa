// https://www.codingninjas.com/studio/problems/delete-middle-element-from-stack_985246

#include <bits/stdc++.h>

void solve(stack<int> &inputStack, int count, int size) {
  if (size / 2 == count) {
    inputStack.pop();
    return;
  }
  int stored = inputStack.top();
  inputStack.pop();
  solve(inputStack, count+1, size);
  inputStack.push(stored);
}

void deleteMiddle(stack<int> &inputStack, int N) { solve(inputStack, 0, N); }