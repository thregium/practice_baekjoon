#include <stdio.h>

/*
문제 : N(N <= 100000)개의 점으로 이루어진 볼록 다각형(|X|, |Y| <= 10^8)이 있다.
이 볼록 다각형의 서로 다른 세 변을 포함하는 직선을 그어 볼록 다각형이 탈출하지 못하도록 하는
경우의 수를 구한다.

해결 방법 : 볼록다각형이 탈출할 수 있는 경우는 세 직선이 이루는 가장 큰 각이 180도 이상인 경우이다.
이 경우는 투 포인터를 이용해 각 점에서 반시계방향으로 돌면서 이루는 각이 180도를 넘는 첫 직선을 구한 다음,
그 이전의 세 직선을 뽑는 경우의 수를 구하면 된다.
그 합을 전부 구한 다음 세 개의 서로 다른 직선을 뽑는 모든 경우의 수에서 앞에서 구한 값을 빼면
탈출할 수 있는 경우의 수가 된다.

주요 알고리즘 : 기하학, 투 포인터, 조합론

출처 : Latin 2018 E번
*/

typedef struct point {
    long long x, y;
} point;

point p[103000];

long long geteulersum(long long a, long long b) {
    return ((b - a + 1) * (b + a)) >> 1;
}

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0) return 1; //turn left(x->y^)
    else if (tri == 0) return 0;
    else return -1; //turn right
}

point pointplus(point p1, point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

point pointminus(point p1, point p2) {
    p1.x -= p2.x;
    p1.y -= p2.y;
    return p1;
}

int main(void) {
    int e = 1, c;
    long long n, res = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    for (int i = 0; i < n; i++) {
        while (ccw(p[i], p[(i + 1) % n],
            pointplus(pointminus(p[(e + 1) % n], p[e]), p[(i + 1) % n])) >= 0) {
            e = (e + 1) % n;
        }
        c = e - i;
        if (c < 0) c += n;
        if (c > 2) res += geteulersum(1, c - 2);
    }
    res = n * (n - 1) * (n - 2) / 6 - res;
    printf("%lld", res);
    return 0;
}