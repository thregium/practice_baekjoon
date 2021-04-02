#include <stdio.h>

/*
문제 : 일직선 모양의 강이 있고, 강 서쪽에는 n개, 동쪽에는 m개의 사이트들이 있다. 각 사이트들 사이에 일대일 대응으로 다리를 연결하고, 다리들끼리 겹치지 않을 때 다리를 짓는 방법의 가짓수를 구한다.

해결 방법 : 다리를 짓는 방법의 수는 mCn과 같다. mCn = (m-1)C(n-1) + (m-1)Cn과 같으므로 다이나믹 프로그래밍을 이용해 푼다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int brid[32][32];

int build(int n, int m) {
     if (brid[n][m]) return brid[n][m];
     if (m == 0) return brid[n][m] = 1;
     if (n == m) return brid[n][m] = 1;
     return brid[n][m] = build(n - 1, m) + build(n - 1, m - 1);
}

int main(void) {
     int t, n, m;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d %d", &n, &m);
          printf("%d\n", build(m, n));
     }
     return 0;
}