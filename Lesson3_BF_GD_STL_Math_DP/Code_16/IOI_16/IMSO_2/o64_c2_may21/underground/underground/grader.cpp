#include "underground.h"
#include <vector>
#include <cstdio>

using namespace std;

static vector<vector<int>> A;

int main()
{
  int R,C;

  scanf("%d %d",&R,&C);
  for(int i=0; i<R; i++) {
    vector<int> row;
    for(int j=0; j<C; j++) {
      int aa;

      scanf("%d",&aa);
      row.push_back(aa);
    }
    A.push_back(row);
  }

  int result = dig_paths(R, C, A);

  printf("%d\n", result);
  return 0;
}
