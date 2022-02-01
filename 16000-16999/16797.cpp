#include <stdio.h>
#include <map>
using namespace std;

/*
문제 : 평면상의 N(N <= 100000)개의 격자점(|| <= 10^9)에 여우들이 w_i(w_i <= 10000)마리 있다.
이때, 1 * 1 이상의 크기로 격자점상에 격자와 같은 방향으로 직사각형을 만들었을 때,
넓이 대비 여우들이 가장 많은 직사각형의 여우 밀도를 구한다.

해결 방법 : 1 * 1 정사각형일 때 여우 밀도가 가장 높아야 한다. 따라서, 각 여우의 위치마다
각 꼭지점으로 하는 여우 밀도 가운데 가장 큰 것을 고르면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 맵

출처 : JAG 2013S4 C번
*/

int p[103000][3];
map<pair<int, int>, int> m;

int big(int a, int b) {
    return a > b ? a : b;
}

int getfox(int x, int y) {
    return m[make_pair(x, y)] + m[make_pair(x, y + 1)] + m[make_pair(x + 1, y)] + m[make_pair(x + 1, y + 1)];
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
        m.insert(make_pair(make_pair(p[i][0], p[i][1]), p[i][2]));
    }
    for (int i = 0; i < n; i++) {
        r = big(r, getfox(p[i][0], p[i][1]));
        r = big(r, getfox(p[i][0], p[i][1] - 1));
        r = big(r, getfox(p[i][0] - 1, p[i][1]));
        r = big(r, getfox(p[i][0] - 1, p[i][1] - 1));
    }
    printf("%d / 1\n", r);
    return 0;
}