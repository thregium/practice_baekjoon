#include <stdio.h>
#include <stdlib.h>
#define MOD 10000

/*
문제 : N(N <= 200000)개의 자연수(<= 10^9)가 주어질 때, 각 자연수를 오름차순 또는 내림차순으로
배치하는 방법의 가짓수를 구한다. 같은 수라도 처음에 다른 위치에 있던 수라면 다른 수 취급한다.

해결 방법 : 각 수의 개수를 세서 여러 개인 경우 (그 수의 개수)! 만큼을 곱해나간다.
그리고 수가 여러 가지라면 오름차순과 내림차순이 각각 가능하므로 다시 2를 곱한다.
출력 형식이 특이하므로 출력 형식에 주의한다.

주요 알고리즘 : 수학, 조합론, 정렬

출처 : JPOI 2008 3-3번
*/

int a[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c = 1, flag_r = 0, flag_o = 0, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            for (int j = 1; j <= c; j++) {
                r = (r * j);
                if (r >= MOD) {
                    flag_o = 1;
                    r %= MOD;
                }
            }
            c = 1;
            flag_r = 1;
        }
        else c++;
    }
    for (int j = 1; j <= c; j++) {
        r = (r * j);
        if (r >= MOD) {
            flag_o = 1;
            r %= MOD;
        }
    }
    if (flag_r) r = (r * 2);
    if (r >= MOD) {
        flag_o = 1;
        r %= MOD;
    }
    if (flag_o) printf("%04d", r);
    else printf("%d", r);
    return 0;
}