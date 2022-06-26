#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
문제 : N(N <= 500000)개의 2 * 10^9 이하 자연수로 이루어진 무작위 수열이 주어질 때,
이 수열에서 배수 관계인 두 수를 구한다.

해결 방법 : 수열을 정렬하고 작은 수부터 그 수의 배수를 찾아나가면
빠르게 배수 관계가 되는 수들을 찾을 수 있다.

주요 알고리즘 : 수학, 정수론, 무작위화

출처 : BAPC 2021P A번
*/

int a[524288][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    //srand(time(NULL));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = i + 1;
        //a[i] = (((long long)rand() << 16) + (long long)rand()) % 2000000000 + 1;
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    //srand(clock());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j][0] % a[i][0] == 0) {
                printf("%d %d", a[i][1], a[j][1]);
                //printf("%d %d", a[i], a[j]);
                return 0;
            }
        }
    }
    return 1;
}