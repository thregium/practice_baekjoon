#include <stdio.h>
#define INF 1012345678

/*
문제 : 길이 N(N <= 200000)의 얼음에 각각의 강도가 주어진다. 펭귄이 있는 얼음의 왼쪽과 오른쪽 얼음을 깨서 펭귄을
떨어뜨리려 할 때, 최소로 필요한 강도 합을 구한다. 펭귄의 왼쪽과 오른쪽에는 반드시 1개 이상의 얼음이 있다.

해결 방법 : 양쪽에서 각각 강도가 가장 약한 얼음을 깨면 된다. 펭귄이 나오기 전까지의 최솟값과
펭귄이 나온 다음의 최솟값을 더하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : 인천대 2019 A번
*/

int a[204800];

int main(void) {
    int n, ls = INF, rs = INF, ph = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0) {
            ph = 1;
            continue;
        }
        if (ph == 0 && a[i] < ls) ls = a[i];
        else if (ph == 1 && a[i] < rs) rs = a[i];
    }
    printf("%d", ls + rs);
    return 0;
}