#include <stdio.h>

/*
문제 : N(N <= 1000)개의 수로 이루어진 배열과 Q(Q <= 10000)개의 쿼리가 주어질 때, 각 쿼리에 응답한다.
1. A번째 수부터 B번째 수 까지의 합을 출력한 다음, A번째 수와 B번째 수를 서로 바꾼다.
2. A번째 수부터 B번째 수 까지의 합에서 C번째 수부터 D번째 수 까지의 합을 뺀 값을 출력한다/

해결 방법 : N과 Q가 크지 않기 때문에 각 쿼리마다 합을 직접 구하고 바꾸는 연산도 직접 처리하면 된다.

주요 알고리즘 : 구현

출처 : 선린 1회예 D번
*/

int arr[1024];

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int n, q, o, a, b, c, d;
    long long res;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &o);
        if (o == 1) {
            scanf("%d %d", &a, &b);
            res = 0;
            for (int j = a; j <= b; j++) {
                res += arr[j];
            }
            printf("%lld\n", res);
            swap(&arr[a], &arr[b]);
        }
        else {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            res = 0;
            for (int j = a; j <= b; j++) {
                res += arr[j];
            }
            for (int j = c; j <= d; j++) {
                res -= arr[j];
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}
