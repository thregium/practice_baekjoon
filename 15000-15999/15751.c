#include <stdio.h>
#include <math.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 수직선 상의 좌표 A에서 B로 이동할 때, 좌표 C와 D에 있는 텔레포터를 이용 가능하다고 한다.
텔레포터를 이용하면 즉시 C와 D 사이를 이동 가능하고, 좌표 1만큼 움직이는데 시간이 1씩 든다고 하면, A와 B를 이동하는데 걸리는 최소 시간을 구한다.

해결 방법 : A에서 B로 가는 방법으로는 A에서 직선으로 B로 가거나, A에서 C로 간 다음 D에서 B로 가거나, A에서 D로 간 다음 C에서 B로 가는 3가지가 있다.
두 점 사이의 거리는 두 점의 좌표를 뺀 값의 절대값과 같으므로, 위 3가지를 간단히 계산 가능하다. 이 값들 중 가장 작은 것이 정답이 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : USACO 2018F B1번
*/

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("teleport.in", "r");
        fo = fopen("teleport.out", "w");
    }
    int a, b, c, d, r1, r2, r3;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    r1 = abs(a - c) + abs(b - d);
    r2 = abs(a - d) + abs(b - c);
    r3 = abs(a - b);
    printf("%d", r1 < r2 && r1 < r3 ? r1 : r2 < r3 ? r2 : r3);
    return 0;
}