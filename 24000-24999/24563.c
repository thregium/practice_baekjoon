#include <stdio.h>

/*
문제 : P개의 고정된 파일과 U(P + U <= 100)개의 고정되지 않은 파일이 있다. 각 고정된 파일의 고정을 풀면
고정되지 않은 파일 목록의 맨 앞으로 가고, 고정되지 않은 파일을 고정하면 고정된 파일 목록의 맨 뒤로 간다.
이때, 파일의 위치를 바꿀 형태가 입력과 같이 주어지면 해당 형태로 바꾸기 위해 필요한
고정 또는 고정을 푸는 횟수를 구한다.

해결 방법 : 우선 고정된 파일을 고정되지 않은 파일로 바꾸거나 그 반대의 경우에는 반드시 1번 이동해야 한다.
또한, 자신보다 순서가 나중인 파일이 앞쪽 순서로 이동해야 하는 경우 반드시 2번 이동하여 돌아와야
나중인 파일의 뒤로 갈 수 있다. 순서상 나중인 파일은 (반대 상태에서 이동한 파일, 자신의 뒤에(고정되지 않은 경우
앞에) 있는 파일, 2번 이동한 파일)의 3 가지이다.
또한, 1번 반대 상태로 이동하면 다시 원래 상태로 돌아올 때 어떤 순서로든 돌아올 수 있기 때문에
반드시 이동해야 하는 경우만 신경쓰면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : ECNA 2021 I번
*/

char dir[256];
int a1[128], a2[128];

int isp(int p1, int x) {
    for (int i = 0; i < p1; i++) {
        if (a1[i] == x) return 1;
    }
    return 0;
}

int main(void) {
    int p1, u1, p2, u2, inp, inr, apr, res = 0;
    for (int tt = 1; tt <= 1; tt++) {
        //sprintf(dir, "E:\\PS\\ICPC\\North America\\East Central\\2021\\pinnedfiles\\data\\secret\\maxsize_%d.in", tt);
        //freopen(dir, "r", stdin);
        res = 0;
        scanf("%d %d", &p1, &u1);
        for (int i = 0; i < p1 + u1; i++) {
            scanf("%d", &a1[i]);
        }
        scanf("%d %d", &p2, &u2);
        for (int i = 0; i < p2 + u2; i++) {
            scanf("%d", &a2[i]);
        }

        inr = 0;
        for (int i = 0; i < p2; i++) {
            if ((i < p2) ^ isp(p1, a2[i])) res++;
            else {
                inp = 1;
                for (int j = 0; j < i; j++) {
                    if (!isp(p1, a2[j])) inp = 0;
                    apr = 0;
                    for (int k = 0; k < p1; k++) {
                        if (a1[k] == a2[i]) apr = 1;
                        if (apr && a2[j] == a1[k]) inp = 0;
                    }
                }
                if (!inp) inr = 1;
                if (inr) res += 2;
            }
        }
        inr = 0;
        for (int i = p2 + u2 - 1; i >= p2; i--) {
            if ((i < p2) ^ isp(p1, a2[i])) res++;
            else {
                inp = 0;
                for (int j = i + 1; j < p2 + u2; j++) {
                    if (isp(p1, a2[j])) inp = 1;
                    apr = 0;
                    for (int k = p1; k < p1 + u1; k++) {
                        if (a1[k] == a2[i]) apr = 1;
                        if (!apr && a2[j] == a1[k]) inp = 1;
                    }
                }
                if (inp) inr = 1;
                if (inr) res += 2;
            }
        }
        printf("%d", res);
        //sprintf(dir, "E:\\PS\\ICPC\\North America\\East Central\\2021\\pinnedfiles\\data\\secret\\maxsize_%d.ans", tt);
        //freopen(dir, "r", stdin);
        //scanf("%d", &res);
        //printf("%d\n", res);
    }
    return 0;
}