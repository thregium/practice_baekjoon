#include <stdio.h>
#include <string.h>

/*
문제 : FizzBuzz 문자열의 N(N <= 10^18)번째부터 20개의 문자를 출력한다.

해결 방법 : 그 수 이전에 나오는 마지막 수를 매개 변수 탐색을 이용하여 찾아낸 다음, 그 위치에서
남은 문자 번째의 값을 출력하면 된다. 각 수까지 나오는 문자의 개수는 각 숫자의 개수와 Fizz, Buzz의
개수를 각각 구해서 셀 수 있다.

주요 알고리즘 : 수학, 파라메트릭

출처 : JAG 2012S3B B번
*/

char s[32];

long long getdigits(long long n) {
    long long one = 0, three = 0, five = 0, fifteen = 0, fizz = 0, buzz = 0;
    for (long long i = 1; i <= n; i *= 10) one += n - i + 1;
    for (long long i = 1; i <= n; i *= 10) three += n / 3 - (i - 1) / 3;
    for (long long i = 1; i <= n; i *= 10) five += n / 5 - (i - 1) / 5;
    for (long long i = 1; i <= n; i *= 10) fifteen += n / 15 - (i - 1) / 15;
    fizz = n / 3 * 4;
    buzz = n / 5 * 4;
    return one - three - five + fifteen + fizz + buzz;
}

int main(void) {
    long long n, lo, hi, mid, pos;
    scanf("%lld", &n);
    for (int i = 0; i < 20; i++) {
        lo = 0, hi = 100000000000000000;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (getdigits(mid) < n + i) lo = mid;
            else hi = mid - 1;
        }

        pos = n + i - getdigits(lo);
        if ((lo + 1) % 15 == 0) strcpy(s, "FizzBuzz");
        else if ((lo + 1) % 5 == 0) strcpy(s, "Buzz");
        else if ((lo + 1) % 3 == 0) strcpy(s, "Fizz");
        else sprintf(s, "%lld", lo + 1);
        printf("%c", s[pos - 1]);
    }
    printf("\n");
    return 0;
}