#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 자연수가 주어질 때, 이 자연수들 가운데 다른 모든 수와의 최대공약수가 1인 가장 큰 수를 구한다.

해결 방법 : 수들을 내림차순으로 정렬한 뒤, 맨 앞 수부터 차례로 나머지 모든 수와의 최대공약수를 구한다.
모두 1인 수가 나오면 바로 출력하면 된다.

주요 알고리즘 : 수학, 유클리드 호제법, 정렬

출처 : NAQ 2012 E번
*/

int numbers[1024];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, t;
    //freopen("E:\\PS\\ICPC\\North America\\Qualifier\\2012\\test_data\\choosingnumbers\\data\\secret\\random.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Qualifier\\2012\\test_data\\choosingnumbers\\data\\secret\\random_t.out", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        qsort(numbers, n, sizeof(int), cmp1);
        for (int i = 0; i < n; i++) {
            t = 1;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (gcd(numbers[i], numbers[j]) > 1) {
                    t = 0;
                    break;
                }
            }
            if (t) {
                printf("%d\n", numbers[i]);
                break;
            }
        }
    }
    return 0;
}