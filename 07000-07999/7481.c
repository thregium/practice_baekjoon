#include <stdio.h>

/*
문제 : A, B(A, B <= 10000), S(S <= 10^9)가 주어질 때, A단위 지폐와 B단위 지폐를 사용하여 S단위를 만드는 방법이 있는지 구하고,
가능하다면 그 중 가장 지폐를 적게 사용하는 방법을 구한다.

해결 방법 : 먼저, A와 B의 최대공약수를 구한다. 만약 S가 최대공약수의 배수가 아니라면 S 단위를 A와 B의 자연수 배로
만들 수 있는 방법이 없다. 배수인 경우에는 시작점을 잡는다. 시작점은 두 수가 0 이상이며 가장 작은,
S와의 (A와 B의 최소공배수)로 나눈 나머지가 같은 수이다.
시작점을 잡은 다음에는 더 큰 수를 기준점으로 파라메트릭을 시행한다. 더 큰 수를 더 작은 수 / 최대공약수 배 단위로
움직이며 S를 만들 수 있는 가장 큰 배수를 구한다. 만약 양수에서 그러한 것이 없다면 만들 수 있는 경우가 없는 것이다.
그러한 것이 있다면 그 값을 이용해 A와 B의 사용 개수를 구하면 된다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법, 파라메트릭

출처 : AUCPC 2010S A번
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int t, a, b, s, g, l, stt1, stt2, swapped;
    long long lo, hi, mid, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &a, &b, &s);
        if (a < b) {
            swap(&a, &b);
            swapped = 1;
        }
        else swapped = 0;
        g = gcd(a, b);
        if (s % g) {
            printf("Impossible\n"); //불가능한 경우 1
            continue;
        }
        for (stt1 = 0;; stt1++) {
            if ((s - a * stt1) % b) continue;
            for (stt2 = 0;; stt2++) {
                if ((a * stt1 + b * stt2) % (a * b / g) == s % (a * b / g)) break; //시작점 잡기
            }
            break;
        }
        l = b / g;

        lo = -1, hi = 1012345678;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (a * stt1 + mid * a * l + b * stt2 <= s) lo = mid;
            else hi = mid - 1;
        } //파라메트릭
        if (lo < 0) {
            printf("Impossible\n"); //양수 범위에서 답을 낼 수 없을 때
            continue;
        }
        if ((s - a * stt1 - lo * a * l - b * stt2) % b) return 1; //잘못 된 경우?
        r = (s - a * stt1 - lo * a * l - b * stt2) / b; //더 작은 수의 사용 수
        if (swapped) printf("%lld %lld\n", r + stt2, lo * l + stt1); //두 값에 시작점의 값들을 더하면 답이 된다.
        else printf("%lld %lld\n", lo * l + stt1, r + stt2);
    }
    return 0;
}