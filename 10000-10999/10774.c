#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 저지와 A(A = 10^6)명의 선수가 있다. 각 저지는 번호별로 한 개씩 있고,
선수들은 자신이 원하는 번호와 사이즈가 있다. 자신의 번호와 맞으면서 자신의 사이즈 이상인 저지를 각 선수가 입을 때,
저지를 입을 수 있는 선수들의 최댓값을 출력한다.

해결 방법 : 각 번호마다 최소 사이즈를 가진 사람을 찾는다. 그 다음, 각 저지들마다의 사이즈를 비교하며
그 사람에게 맞는 것의 개수를 구하면 된다.

주요 알고리즘 : 

출처 : CCC 2015S 2번
*/

int js[1048576], best[1048576];

int main(void) {
    int n, a, x, r = 0;
    char c;
    scanf("%d%d", &n, &a);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &js[i]);
        if (js[i] == 'L') js[i] = 3;
        else if (js[i] == 'M') js[i] = 2;
        else if (js[i] == 'S') js[i] = 1;
        else return 1;
    }
    for (int i = 0; i < a; i++) {
        scanf(" %c %d", &c, &x);
        if (x <= 0 || x > n) continue;
        if (c == 'L' && (best[x] > 3 || best[x] == 0)) best[x] = 3;
        else if (c == 'M' && (best[x] > 2 || best[x] == 0)) best[x] = 2;
        else if (c == 'S' && (best[x] > 1 || best[x] == 0)) best[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (best[i] > 0 && best[i] <= js[i]) r++;
    }
    printf("%d", r);
    return 0;
}