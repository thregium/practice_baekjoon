#include <stdio.h>

/*
문제 : 크기 N(N <= 200000)인 최소 힙에서 1 ~ N까지의 자연수를 한 번씩 넣어 자연수 K가 P번 노드에 들어가도록 하는 순열을 구한다.
만약 없는 경우 -1을 출력한다.

해결 방법 : 먼저 P가 1인 경우를 살펴본다. K가 1이라면 어떠한 순열을 출력하더라도 상관 없고, 아니라면 항상 불가능하다.
그 외의 경우는 P번 노드부터 위쪽 노드와 아래쪽 노드에 수들을 채워본다. 위쪽으로는 자신의 값 - 1을 순서대로 채워나가면 되고,
아래쪽으로는 재귀를 이용해 값을 채워나가면 된다. 중간에 값이 나가는 경우에는 -1을 출력하고 프로그램을 종료한다.
다음으로는 1번 노드의 값을 1로 고친 다음 아직까지 나오지 않은 값들을 나머지 노드에 차례로 집어넣는다.
이 과정이 끝나면 값들을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 구성적, 재귀

출처 : UCPC 2018 E번
*/

int res[204800], chk[204800];
int t, over = 0;

void track(int n, int p) {
    if (p > n) return;
    if (t > n) over = 1;
    res[p] = t;
    chk[t++] = 1;
    track(n, p * 2);
    track(n, p * 2 + 1);
}

int main(void) {
    int n, k, p;
    scanf("%d%d %d", &n, &k, &p);
    if (p == 1) {
        //루트 노드의 경우
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                printf("%d\n", i);
            }
        }
        else printf("-1");
        return 0;
    }
    //위쪽으로 자리가 있는지 검사
    t = p;
    for (int i = 0; i < k; i++) t /= 2;
    if (t) {
        printf("-1");
        return 0;
    }
    res[p] = k;
    chk[k] = 1;
    for (int i = p; i > 1; i >>= 1) {
        //위쪽 노드 채우기
        res[i >> 1] = res[i] - 1;
        chk[res[i >> 1]] = 1;
    }
    chk[res[1]] = 0;
    res[1] = 1;
    chk[1] = 1;
    t = k;
    track(n, p); //아래쪽 노드 채우기
    if (over) {
        //넘어간 경우
        printf("-1");
        return 0;
    }
    t = 1;
    for (int i = 1; i <= n; i++) {
        //나머지 노드 채우기
        if (res[i]) continue;
        while (chk[t]) t++;
        res[i] = t;
        chk[t] = 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}