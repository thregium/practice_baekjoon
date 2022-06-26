#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
문제 : 200000개 이하의 선분 길이(<= 10^9, 자연수)가 주어질 때,
삼각형을 이루는 세 선분이 있는 지 찾고 있다면 그 세 선분의 길이를 각각 구한다.

해결 방법 : 가장 변의 길이가 큰 것부터 정렬해두면 빠르게 답을 찾을 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 기하학

출처 : POI 1994/1995_2 3번
*/

int a[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int istriangle(int a, int b, int c) {
    if (a >= b + c || b >= a + c || c >= a + b) return 0;
    else return 1;
}

int main(void) {
    int n = 0;
    while (1) {
        scanf("%d", &a[n]);
        if (a[n] == 0) break;
        n++;
    }
    assert(n <= 200000);
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (istriangle(a[i], a[j], a[k])) {
                    printf("%d %d %d", a[i], a[j], a[k]);
                    return 0;
                }
            }
        }
    }
    printf("NIE");
    return 0;
}