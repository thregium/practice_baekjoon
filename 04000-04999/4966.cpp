#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : 빨간색 카드가 N(N <= 500)장, 파란색 카드가 M(M <= 500)장 있고,
각 카드에는 10^7 이하의 자연수가 쓰여 있다. 빨간색 카드와 파란색 카드를 하나씩 골라
양쪽 카드에 쓰인 수가 서로소가 아닌 경우 둘씩 제거가 가능하다면
제거 가능한 쌍의 최대 개수를 구한다.

해결 방법 : 이분 매칭을 통해 최대 매칭을 구하면 제거되는 쌍의 수와 같다.
간선은 유클리드 호제법을 통해 최대공약수를 구하고 2 이상인 경우 이어주면 된다.

주요 알고리즘 : 그래프 이론, 이분 매칭, 유클리드 호제법

출처 : JDC 2009 E번
*/

int blue[512], red[512], left[512], right[512], vis[512];
vector<int> ed[512];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int match(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (right[i] == 0 || (!vis[right[i]] && match(right[i]))) {
            left[x] = i;
            right[i] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, m, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &blue[i]);
            left[i] = 0;
            ed[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &red[i]);
            right[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (gcd(blue[i], red[j]) > 1) ed[i].push_back(j);
            }
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) vis[j] = 0;
            r += match(i);
        }
        printf("%d\n", r);
    }
    return 0;
}