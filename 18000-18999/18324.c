#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 0에서 K 이상의 위치로 이동해야 한다. 시작 속도는 1이고, 이동시마다 속도를 1씩 늘리거나 줄일 수 있다.
도착 속도는 X 이하로 해야 한다고 할 때 최소 이동 횟수를 구한다.

해결 방법 : 시작점부터 X 지점까지 T 시간 내에 이동 가능하고, Y 지점까지 T - 1 시간 내에 이동 가능하다면
Y 부터 X 지점 사이의 모든 지점은 T 시간 내에 이동 가능하다. 따라서 X 지점까지 낼 수 있는 최고 속도를 알면 최소 이동 횟수를 알 수 있다.
최고 속도는 먼저, 시작점부터 X 속도까지 올려가며 그 전에 도착할 수 있는지 검사한다. 도착 가능하다면 이동 횟수는 도착했을 때의 속도와 같다.
도착 불가능하다면 X부터 속도를 올려가며 목적지에 도달 가능한지 계속 검사한다. 이때, 속도를 올리는 것 한번, 줄이는 것 한번 해서
두 번을 거리와 이동 횟수에 더해야 한다. 한번만 해서 도달 가능한 경우에도 검사를 멈춘다.

주요 알고리즘 : 그리디 알고리즘, 수학

출처 : USACO 2020J B3번
*/

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("race.in", "r");
        fo = fopen("race.out", "w");
    }
    int k, n, x, t, s; //t : 시간, s : 거리 합
    scanf("%d %d", &k, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        t = 0;
        s = 0;
        for (int j = 1; j < x; j++) {
            t++;
            s += j;
            if (s >= k) break;
        }
        if (s >= k) {
            printf("%d\n", t);
            continue;
        }
        for (int j = x; s < k; j++) {
            t++;
            s += j;
            if (s >= k) break;
            t++;
            s += j;
        }
        printf("%d\n", t);
    }
    return 0;
}