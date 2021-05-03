#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 1000)개의 수가 있을 때, 수들을 합이 짝수, 홀수, 짝수, 홀수, ... 순이 되는 집합으로 만드려고 한다.
만들 수 있는 집합의 최대 개수를 구한다.

해결 방법 : 먼저, 수들 중 홀수와 짝수의 개수를 각각 센다. 만약 짝수가 더 많다면 홀, 짝으로 홀수 개수 * 2, 마지막에 짝수를 추가 가능하므로
홀수의 개수 * 2 + 1이고, 홀수와 짝수가 같다면 전체 수들을 전부 각 집합으로 나눌 수 있으므로 전체 수의 개수와 같다.
만약 홀수가 더 많다면 나눌 수 있는 개수는 (홀수 - 짝수) / 3 * 2에서 홀수 - 짝수의 나머지에 따라 0, -1, +1이 된다.
이를 경우에 맞게 나누면 답을 얻을 수 있다.

주요 알고리즘 : 수학, 그리디 알고리즘, 케이스 워크
*/

int a[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("f.in", "r");
        fo = fopen("f.out", "w");
    }
    int n, o = 0, e = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] & 1) o++;
        else e++;
    }
    if (e > o) printf("%d", o * 2 + 1);
    else if (e == o) printf("%d", n);
    else {
        if ((o - e) % 3 == 0) printf("%d", e * 2 + (o - e) / 3 * 2);
        else if ((o - e) % 3 == 1) printf("%d", e * 2 + (o - e) / 3 * 2 - 1);
        else printf("%d", e * 2 + (o - e) / 3 * 2 + 1);
    }
    return 0;
}