#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^5)개의 수열 A가 있을 때, 각각의 만족도는 어떠한 수 D에 대해 (Ai - |Ai - D|) * 100이라고 한다.
만족도가 X 이상인 수가 K개 이상인 가장 작은 D를 출력한다. 그러한 값이 없다면 -1을 출력하도록 한다.

해결 방법 : 수식을 풀어보면 만족도가 X 이상인 경우는 D가 (Ai * X / 100) 이상 (Ai * (200 - X) / 100) 이하인 경우이다.
그러므로, 위의 두 값들을 전부 정렬하여 만족하는 수를 작은 수부터 세어나가면 된다. 이때, 수가 같다면 시작하는 구간을 우선으로 한다.
처음엔 0에서 시작해서 시작하는 구간이 들어온 경우 1을 증가시키고 끝나는 구간이 들어온 경우 1을 감소시킨다.
이때, K 이상인 수가 나오면 값을 출력하고 프로그램을 종료하면 되고, 나오지 않았으면 프로그램의 끝에 -1을 출력하도록 하면 된다.

주요 알고리즘 : 수학, 스위핑

출처 : 네블컵 2회 C번
*/

int s[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if(ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int a, n, x, k, c = 0;
    scanf("%d %d %d", &n, &x, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        s[i * 2][0] = a * x; //시작하는 구간
        s[i * 2 + 1][0] = a * (200 - x); //끝나는 구간
        s[i * 2 + 1][1] = 1;
    }
    qsort(s, n * 2, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n * 2; i++) {
        if (s[i][1]) c--; //끝나는 구간을 만난 경우
        else c++; //시작하는 구간을 만난 경우
        if (c >= k) {
            if (s[i][0] % 100 == 0) printf("%d", s[i][0] / 100); //자연수인 경우 그대로 출력
            else printf("%d/%d", s[i][0] / gcd(s[i][0], 100), 100 / gcd(s[i][0], 100)); //기약분수 형태로 출력
            return 0; //프로그램 종료
        }
    }
    printf("-1");
    return 0;
}
