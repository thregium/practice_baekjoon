#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

/*
문제 : N(N <= 25000)개의 일을 해야 한다. 각 일은 두 단계로 나누어져 있고, 첫 번째 단계를 끝내야 다음 단계를 할 수 있다.
첫 번째 단계와 두 번째 단계의 일은 각자 독립적으로 할 수 있다면 모든 일을 하는데 걸리는 최소 시간을 구한다.

해결 방법 : 첫 번째 단계와 두 번째 단계의 일을 하는 순서가 각자 같아야 최선이 됨을 알 수 있다.
따라서 첫 번째 일의 순서만 지정하면 되는데, 어느 위치의 일이든 순서 관계는 변하지 않기 때문에 정렬이 가능하다.
그 순서는 두 일만 갖고 생각하면 찾을 수 있다. (왼쪽 값의 첫 번째 단계의 일, 오른쪽 값의 두 번째 단계의 일)중 작은 것과
(오른쪽 값의 첫 번째 단계의 일, 왼쪽 값의 두 번째 단계의 일) 중 작은 것을 비교하는 방식인데, ... (작성 예정)

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2006O G2번
*/

int milk[25600][2], seq[16], vis[16], bseq[16];
int best = 1012345678, bcnt = 1;

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int aa = *(int*)a;
    int ab = *((int*)a + 1);
    int ba = *(int*)b;
    int bb = *((int*)b + 1);
    return (aa < ab ? aa : 1012345678 - ab) - (ba < bb ? ba : 1012345678 - bb);
}

void track(int n, int x) {
    if (n == x) {
        int r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            r1 += milk[seq[i]][0];
            r2 = big(r1, r2) + milk[seq[i]][1];
        }
        if (r2 < best) {
            best = r2;
            for (int i = 0; i < n; i++) bseq[i] = seq[i];
            bcnt = 1;
        }
        else if (r2 == best) bcnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        seq[x] = i;
        track(n, x + 1);
        vis[i] = 0;
    }
}

int main(void) {
    int n, t = 1;
    //freopen("E:\\PS\\Olympiad\\USA\\3_Gold\\2006_04\\usopen06\\testdata\\allopen06\\mqueue.10.in", "r", stdin);
    //srand(time(NULL));
    scanf("%d", &n);
    if (n > 25000) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &milk[i][0], &milk[i][1]);
        //milk[i][0] = rand() + 1;
        //milk[i][1] = rand() + 1;
    }
    //if(t == 0 && n == 25000) return 1;
    /*
    track(n, 0);
    printf("%d %d\n", best, bcnt);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", milk[bseq[i]][0], milk[bseq[i]][1]);
    }
    */
    qsort(milk, n, sizeof(int) * 2, cmp1);
    int r1 = 0, r2 = 0;
    for (int i = 0; i < n; i++) {
        r1 += milk[i][0];
        r2 = big(r1, r2) + milk[i][1];
        if (r2 > 500000000) return 1;
    }
    printf("%d", r2);
    return 0;
}