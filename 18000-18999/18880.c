#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100000)개의 '1'과 '0'으로 이루어진 문자열이 주어진다. 이 문자열에서 '0' 두개를 '1'로 바꾸어
가장 가까운 '1' 사이의 거리가 가장 멀도록 할 때의 거리를 구한다. 문자열에서 '0'은 최소한 2개 이상 있다.

해결 방법 : 먼저 가장 먼 '1' 사이의 거리와 두 번째로 먼 '1' 사이의 거리, 그리고 그들 각각의 시작 위치와
첫 번째 '1', 마지막 '1'의 위치를 구한다. 가장 먼 '1' 사이의 거리 / 3이 두 번째로 먼 '1' 사이의 거리 / 2와
시작 위치, N - 1 - 마지막 위치보다 전부 크다면 그 '1' 사이에 두 '1'을 집어넣는 것이 최적이다.
아닌 경우에는 가장 먼 '1'과 시작 위치, N - 1 - 마지막 위치를 비교해 가장 큰 곳에서 가장 멀리 떨어지도록 '1'을 넣고
같은 방법으로 한 번 더 넣는다.
'1'을 집어넣었으면 직접 가장 가까운 '1'의 거리를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 케이스 워크

출처 : USACO 2019O B1번
*/

char s[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("socdist1.in", "r");
        fo = fopen("socdist1.out", "w");
    }
    int n, first, last, small, big, big2, bn, b2n;
    scanf("%d", &n);
    scanf("%s", s);
    first = -1, last = -1, small = INF, big = -1, big2 = -1, bn = -1, b2n = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (first < 0) first = i;
            if (last >= 0 && (i - last) > big) {
                big2 = big;
                b2n = bn;
                big = i - last;
                bn = last;
            }
            else if (last >= 0 && (i - last) > big2) {
                big2 = i - last;
                b2n = last;
            }
            last = i;
        }
    }
    if (last < 0) {
        printf("%d", n - 1);
        return 0;
    }

    if (big / 3 > big2 / 2 && big / 3 > first && big / 3 > n - last - 1) {
        s[bn + big / 3] = '1';
        s[bn + big / 3 * 2] = '1';
        first = -1, last = -1, small = INF, big = -1, bn = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (first < 0) first = i;
                if (last >= 0 && (i - last) < small) {
                    small = i - last;
                }
                last = i;
            }
        }
        printf("%d", small);
        return 0;
    }

    big >>= 1;
    if (first > big) {
        if (n - last - 1 > first) s[n - 1] = '1';
        else s[0] = '1';
    }
    else if (n - last - 1 > big) s[n - 1] = '1';
    else s[bn + big] = '1';

    first = -1, last = -1, small = INF, big = -1, big2 = -1, bn = -1, b2n = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (first < 0) first = i;
            if (last >= 0 && (i - last) > big) {
                big2 = big;
                b2n = bn;
                big = i - last;
                bn = last;
            }
            else if (last >= 0 && (i - last) > big2) {
                big2 = i - last;
                b2n = last;
            }
            last = i;
        }
    }
    big >>= 1;
    if (first > big) {
        if (n - last - 1 > first) s[n - 1] = '1';
        else s[0] = '1';
    }
    else if (n - last - 1 > big) s[n - 1] = '1';
    else s[bn + big] = '1';


    first = -1, last = -1, small = INF, big = -1, bn = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (first < 0) first = i;
            if (last >= 0 && (i - last) < small) {
                small = i - last;
            }
            last = i;
        }
    }
    printf("%d", small);
    return 0;
}