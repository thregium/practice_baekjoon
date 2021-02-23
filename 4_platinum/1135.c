#include <stdio.h>
#include <stdlib.h>

/*
문제 : 트리 형태로 된 회사가 있고, 각 사원들은 자신의 직속 부하에게만 연락할 수 있다고 한다. 각 사원은 전화를 하는데 1분씩 걸리고, 동시에 전화를 할 수는 없다고 할 때
사장이 모든 사원들에게 뉴스를 전하는데 걸리는 시간을 구한다. 사원의 수는 50명 이하이다.

해결 방법 : 트리를 후위순회하며 말단부터 해당 사원의 모든 부하에게 뉴스를 전하는데 걸리는 시간을 구한다. 최말단 사원의 경우 부하가 없으므로 0초이고,
부하가 있는 경우에는 시간이 오래 걸리는 사원부터 순서대로 전화를 건다. 이 때 자신이 전화를 거는데 걸린 시간과 해당 사원이 부하에게 전하는데 걸리는 시간의 합이
가장 큰 것이 자신의 전달 시간이 된다. 이를 반복하여 사장까지 도달하면 사장의 전달 시간을 출력한다.
*/

int inf[64][64]; //부하의 목록
int tm[64]; //모든 부하에게 뉴스를 전하는데 걸리는 시간

int big(int a, int b) {
     return a > b ? a : b;
}

int infcmp(const void* a, const void* b) {
     int ai = tm[*(int*)a];
     int bi = tm[*(int*)b];

     return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int makeinfs(int a) {
     int x = 0;
     for (int i = 1; i <= inf[a][0]; i++) {
          makeinfs(inf[a][i]);
     }
     if (inf[a][0] == 0) return tm[a] = 0;
     
     qsort(&inf[a][1], inf[a][0], sizeof(int), infcmp);
     for (int i = 1; i <= inf[a][0]; i++) {
          x = big(x, i + tm[inf[a][i]]);
     }
     return tm[a] = x;
}

int main(void) {
     int n, a;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a);
          if(a >= 0) inf[a][++inf[a][0]] = i;
     }
     printf("%d", makeinfs(0));
     return 0;
}