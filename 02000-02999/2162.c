#include <stdio.h>

/*
문제 : N(N <= 3000)개의 선분(|| <= 5000, 정수)이 주어질 때, 서로 교차하는 선분들을 그룹으로 묶으면 생기는 그룹의 개수와
그러한 그룹 가운데 가장 큰 그룹의 크기를 구한다. 선분의 끝만 닿더라도 교차하는 것이다.

해결 방법 : 각 선분 쌍들에 대해 선분의 교차 여부를 검사한다. 교차하는 경우 유니온 파인드로 한 그룹으로 묶어준다.
이를 반복한 다음 각 그룹별 선분의 수를 센 다음 개수와 가장 큰 그룹의 크기를 찾으면 된다.

주요 알고리즘 : 기하학, 선분교차, 유니온 파인드
*/

int line[3200][4], g[3200], cnt[3200];

long long int big(long long a, long long b) {
    return a > b ? a : b;
}

long long int small(long long a, long long b) {
    return a < b ? a : b;
}

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long int tri = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
    if (tri > 0) return 1;
    else if (tri == 0) return 0;
    else return -1;
}

int dotinline(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    if (ccw(x1, y1, x2, y2, x3, y3)) return 0;
    if (x3 > big(x1, x2) || x3 < small(x1, x2) || y3 > big(y1, y2) || y3 < small(y1, y2)) return 0;
    else return 1;
}

int crossline(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4) {
    if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0 && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) < 0) return 1;
    else if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2)) return 0;
    if (dotinline(x1, y1, x2, y2, x3, y3) || dotinline(x1, y1, x2, y2, x4, y4) || dotinline(x3, y3, x4, y4, x1, y1) || dotinline(x3, y3, x4, y4, x2, y2)) return 1;
    else return 0;
}

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, r1 = 0, r2 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &line[i][0], &line[i][1], &line[i][2], &line[i][3]);
    }
    r1 = n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (crossline(line[i][0], line[i][1], line[i][2], line[i][3], line[j][0], line[j][1], line[j][2], line[j][3]) && find(i) != find(j)) {
                uni(i, j);
                r1--;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt[find(i)]++;
    }
    for (int i = 1; i <= n; i++) {
        r2 = big(r2, cnt[i]);
    }

    printf("%d\n%d", r1, r2);
    return 0;
}