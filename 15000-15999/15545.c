#include <stdio.h>

/*
문제 : 두 자연수 T와 N(T, N <= 10^6)이 주어질 때, N을 잘라서 붙인 수가 T 이하의 가장 큰 자연수가
되는 경우를 출력한다. 그러한 경우가 없다면 "error"를, 있지만 여럿인 경우 "rejected"를 출력한다.

해결 방법 : N을 자르는 모든 경우를 시도해보며 T 이하의 최댓값이 갱신될때 마다 그때까지 자른 방법의
배열을 저장해둔 값으로 자르는 방법의 배열을 갱신한다. 만약 최댓값과 같은 값이 다시 나온다면 기록해두고
최댓값이 갱신된 적이 없거나 같은 값이 있음이 확인되면 "error" 또는 "rejected"를,
둘다 아니라면 저장한 배열을 출력한다.
각 경우를 시도할 때에는 문자열로 바꾼 문자 단위로 잘라서 계산해나가면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : Kanazawa 2002 F번
*/

int best, bcnt, blen, arr[16], barr[16];

void track(int t, int n, int p, int c, int r) {
    int x = 0, i;
    char dig[16] = { 0, };
    sprintf(dig, "%d", n);
    for (i = p + 1; dig[i]; i++) {
        x *= 10;
        x += dig[i - 1] - '0';
        arr[c] = x;
        if (r > t) return;
        track(t, n, i, c + 1, r + x);
    }
    x *= 10;
    x += dig[i - 1] - '0';
    r += x;
    arr[c++] = x;
    if (r > t) return;
    if (r > best) {
        best = r;
        bcnt = 1;
        blen = c;
        for (int i = 0; i < c; i++) {
            barr[i] = arr[i];
        }
    }
    else if (r == best) bcnt++;
    return;
}

int main(void) {
    int t, n;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2002\\JAG\\paper.txt", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2002\\JAG\\paper_t.out", "w", stdout);
    while (1) {
        scanf("%d %d", &t, &n);
        if (t == 0) break;
        best = -1, bcnt = 1;
        track(t, n, 0, 0, 0);
        if (best < 0) printf("error\n");
        else if (bcnt > 1) printf("rejected\n");
        else {
            printf("%d ", best);
            for (int i = 0; i < blen; i++) {
                printf("%d", barr[i]);
                if (i < blen - 1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}