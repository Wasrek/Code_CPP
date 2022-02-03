#include "guess.h"
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int calc(vector<int> cur) {
  if (cur.size() == 1) {
    return cur[0];
  }
  int z = cur.size();
  z /= 4;
  set<pair<int, char>> S;
  for (int i = 0; i < z; ++i) {
    S.emplace(cur[3*i], 'R');
    S.emplace(cur[3*i+1], 'B');
    S.emplace(cur[3*i+2]-1, 'B');
  }
  vector<pair<int, char>> query;
  for(auto x : S) query.emplace_back(x);
  char c = ask(query);
  vector<int> now;
  if (c == 'R') {
    for (int i = 0; i < z; ++i) now.emplace_back(cur[3*i]);
  } else if (c == 'B') {
    for (int i = 0; i < z; ++i) now.emplace_back(cur[3*i+1]);
  } else if (c == 'C') {
    for (int i = 0; i < z; ++i) now.emplace_back(cur[3*i+2]);
  } else {
    for (int i = z*3; i < z*4; ++i) now.emplace_back(cur[i]);
  }
  return calc(now);
}

int find_answer(int N, int K) {
  vector<int> cur;
  for (int i = 0; i < N; ++i)
    cur.emplace_back(i);
  return calc(cur);
}