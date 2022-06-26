#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 10^6)명의 사람과 M(M <= 10^6)개의 대립관계가 주어질 때, 같은 조에 있는 사람끼리
대립관계가 없도록 모든 사람을 두 조에 배치하지 못하게 되는 첫 배치의 번째수를 구한다.
이미 있던 배치에서 양쪽 조를 바꾼 것은 같은 배치로 본다.

해결 방법 : 이분 그래프를 칠하는 방법의 가짓수 + 1을 묻는 것과 같다.
2^(연결 요소의 개수 - 1) + 1이 답이 되지만 이분 그래프가 아니라면 impossible을 출력해야 한다.

주요 알고리즘 : 그래프 이론, 이분 그래프, 조합론

출처 : GCPC 2021 K번
*/

int color[1048576];
vector<int> ed[1048576];

void coloring(int x, int c) {
    color[x] = c;
    for (int i : ed[x]) {
        if (color[i] == 0) coloring(i, c == 1 ? 2 : 1);
    }
}

int main(void) {
    int n, m, p, a, b, res = 1;
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            coloring(i, 1);
            if (i > 1) res = (res * 2) % p;
        }
    }
    res = (res + 1) % p;
    for (int i = 1; i <= n; i++) {
        for (int j : ed[i]) {
            if (color[i] == color[j]) res = -1;
        }
    }

    if (res < 0) printf("impossible");
    else printf("%d", res);

    return 0;
}