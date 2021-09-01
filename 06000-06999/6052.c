#include <stdio.h>

/*
문제 : 자연수 S(S <= 18000)이 주어질 때, S 이상의 수가 한쪽인 가장 작은 친구 수 쌍을 구한다. 단, 완전수는 포함하지 않는다.

해결 방법 : S의 약수의 합을 구한 다음(S는 제외), 해당 수가 S인지 확인하고, S라면 다음 수를 찾는다.
아니라면 해당 수에서 약수의 합을 구하고, 그것이 S가 될 때 까지 계속해서 반복하면 된다.

주요 알고리즘 : 수학, 정수론, 브루트 포스

출처 : USACO 2010O B1번
*/

int getpal(int x) {
    int r = 0;
    for (int i = 1; i < x; i++) {
        if (x % i == 0) r += i;
    }
    return r;
}

int main(void) {
    int s, t;
    scanf("%d", &s);
    for (int i = s;; i++) {
        t = getpal(i);
        if (t == i) continue;
        if (getpal(t) == i) {
            printf("%d %d", i, t);
            break;
        }
    }
    return 0;
}