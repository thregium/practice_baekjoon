#include <stdio.h>
#include <string.h>

/*
문제 : 자연수 N(N <= 10^18)이 주어질 때, N보다 큰 자연수 가운데 연속한 같은 숫자가 없는 가장 작은 자연수를 구한다.

해결 방법 : 맨 뒷 자리부터 살펴보며 만약 앞에서 연속한 같은 숫자가 있다면 해당 수를 0으로 만들고 앞으로 간다.
해당 자리가 연속한 같은 숫자인 경우 해당 자리에 1을 증가시키고 다시 해당 자리를 살펴본다.
그 외의 경우는 뒷 자리로 간다. 이를 반복하여 맨 뒤에서 뒷 자리로 가게 되면 나오는 수가 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 백트래킹

출처 : ROI 2017H E번
*/

char path[256], s[32];

int main(void) {
    unsigned long long n, d = 1, l;
    int r, p = 0;
    for (int tt = 1; tt <= 1; tt++) {
        d = 1, p = 0;
        //sprintf(path, "E:\\PS\\Olympiad\\Russia\\2017H\\ru-olymp-team-spb-2017-archive\\diffdigits\\tests\\%02d", tt);
        //freopen(path, "r", stdin);
        scanf("%lld", &n);
        n++;
        while (d > 0) {
            sprintf(s, "%llu", n);
            l = strlen(s);
            r = -1;
            for (int i = 1; i < l - p - 1; i++) {
                if (s[i] == s[i - 1]) r = 1;
            }
            if (p + 1LL < l && s[l - p - 1] == s[l - p - 2]) {
                n += d;
                r = 0;
            }
            if (r > 0) {
                n -= d * ((n / d) % 10);
                d *= 10;
            }
            else if (r < 0) d /= 10;
            p += r;
        }
        //sprintf(path, "E:\\PS\\Olympiad\\Russia\\2017H\\ru-olymp-team-spb-2017-archive\\diffdigits\\tests\\%02d.a", tt);
        //freopen(path, "r", stdin);
        //scanf("%llu", &d);
        //printf("%llu : %llu -> %d\n", n, d, (n == d));
        printf("%llu", n);
    }
    return 0;
}