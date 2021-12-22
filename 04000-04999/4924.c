#include <stdio.h>

/*
문제 : x가 1일 때 0, 소수일 때 -1, 합성수일 때 (소인수의 개수)로 정의되는 함수 p(x)에서 sum(p(x) - 1, s, e)의 값이
L <= S <= E <= U(L, U <= 10^6)의 sum(p(x) - 1, s, e)을 구한다.

해결 방법 : 에라토스테네스의 체를 이용해 각 수의 소수 여부와 소인수의 개수인지를 구해 p(x)의 값을 미리 구해둔다.
그 다음, p(x)에서 1씩을 뺀 후, L과 U가 주어질 때 마다 부분 최댓값을 다이나믹 프로그래밍으로 구해나가면 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스, DP

출처 : Arab 2006 F번
*/

int p[1048576];

int main(void) {
    int l, u, r = 0, last = 0;
   //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2006\\F. Johnny Hates Number Theory [prime]\\prime.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2006\\F. Johnny Hates Number Theory [prime]\\prime_t.out", "w", stdout);
    for (int i = 2; i <= 1000000; i++) {
        if (p[i]) continue;
        p[i] = -1;
        for (int j = i * 2; j <= 1000000; j += i) {
            for (int k = j; k % i == 0; k /= i) p[j]++;
        }
    }
    for (int i = 1; i <= 1000000; i++) p[i]--;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &l, &u);
        if (u < 0) break;
        r = -2, last = 0;
        for (int i = l; i <= u; i++) {
            if (last + p[i] > p[i]) last += p[i];
            else last = p[i];
            if (last > r) r = last;
        }
        printf("%d. %d\n", tt, r);
    }
    return 0;
}