#include <stdio.h>

/*
문제 : 길이 N(N <= 10000)의 1, 2, 3, ..., N으로 된 수열에서 두 구간을 순서대로 뒤집었다.
이 수열을 다시 두번 뒤집어 1, 2, 3, ..., N으로 만드는 두 구간을 출력한다.

해결 방법 : 첫 번째로 뒤집어 볼 수 있는 후보 구간은 뒤집어서 증가 또는 감소하는 구간의 수가 줄어드는 구간들이다.
그러한 구간들은 증가 또는 감소하는 구간의 양 끝이 있다. 그리고, 2개짜리 증가 또는 감소하는 구간의 경우
2개의 방향이 반대지만 우연히 합쳐진 것일 수 있으므로 둘 다 후보 구간의 양 끝에 들어가야 한다.
이러한 후보 구간들은 답이 존재하기 위해서는 시작점과 끝점 모두 많아야 10개씩이므로 모두 한번씩 살펴보더라도 시간 초과가 나지 않는다.
일단 한번씩 직접 뒤집은 다음 증감 구간의 수를 세서 다시 뒤집으면 원래 수열이 가능한지를 확인한다.
증감 구간이 3개를 넘는 경우 어떻게 하더라도 불가능하다. 1개인 경우 역순이라면 전체 구간을 뒤집고, 정순이라면 한칸만 뒤집으면 원래 수열을 만들 수 있다.
2개인 경우 역순인 부분을 뒤집은 다음 원래 수열이 되는지 확인한다. 3개인 경우에는 정-역-정의 순서일 때만 가능하고,
역시 역순인 부분을 뒤집은 다음 원래 수열이 되는지 확인해 보면 된다. 원래 수열이 만들어지는 경우 탐색을 즉시 종료한다.

주요 알고리즘 : 애드 혹, 브루트 포스, 케이스 워크, 구현

출처 : 정올 2008지 초5/중3
*/

int a[10240][3], st[128], ed[128], mv[2][2];
int n, sp = 0, ep = 0, flag = 0;

void swap(int ss, int ee, int p) {
    //ss - ee 구간을 뒤집는다. p는 뒤집은 횟수이다.
    for (int i = 1; i <= n; i++) {
        a[i][p] = a[i][p - 1];
    }
    for (int s = ss, e = ee; s < e; s++, e--) {
        a[e][p] = a[s][p - 1];
        a[s][p] = a[e][p - 1];
    }
}

void check(void) {
    int t = 1, sign = 0, len = 1, range[4][3]; //range : 각 구간의 정보를 저장한다.(시작점, 끝점, 부호)
    range[1][0] = 1;
    range[1][2] = 0;
    for (int i = 2; i <= n; i++) {
        if (len == 1) {
            len = 2;
            if (a[i][1] == a[i - 1][1] + 1) sign = 1;
            else if (a[i][1] == a[i - 1][1] - 1) sign = -1;
            else {
                range[t++][1] = i - 1;
                if (t > 3) return; //구간이 3개 이상인 경우 원래 수열을 만들 수 없다.
                range[t][0] = i;
                range[t][2] = 0; //1칸짜리 구간은 부호를 0으로 한다.
                len = 1;
            }
            range[t][2] = sign;
        }
        else if (a[i][1] - a[i - 1][1] != sign) {
            t++;
            if (t > 3) return;
            range[t][0] = i;
            range[t][2] = 0;
            range[t - 1][1] = i - 1;
            len = 1;
        }
        else len++;
    }
    range[t][1] = n;
    if (t == 1) {
        flag = 1;
        if (range[1][2] > 0) {
            mv[1][0] = 1;
            mv[1][1] = 1;
        }
        else if (range[1][2] < 0) {
            mv[1][0] = 1;
            mv[1][1] = n;
        }
    }
    else if (t == 2) {
        if (range[1][2] >= 0 && range[2][2] <= 0) {
            swap(range[2][0], range[2][1], 2);
            for (int i = 1; i <= n; i++) {
                if (a[i][2] != i) return; //역방향인 구간을 뒤집은 다음 제대로 되었는지 확인한다.
            }
            mv[1][0] = range[2][0];
            mv[1][1] = range[2][1];
            flag = 1;
        }
        else if (range[1][2] <= 0 && range[2][2] >= 0) {
            swap(range[1][0], range[1][1], 2);
            for (int i = 1; i <= n; i++) {
                if (a[i][2] != i) return;
            }
            mv[1][0] = range[1][0];
            mv[1][1] = range[1][1];
            flag = 1;
        }
    }
    else {
        if (range[1][2] >= 0 && range[2][2] <= 0 && range[3][2] >= 0) {
            swap(range[2][0], range[2][1], 2);
            for (int i = 1; i <= n; i++) {
                if (a[i][2] != i) return;
            }
            flag = 1;
            mv[1][0] = range[2][0];
            mv[1][1] = range[2][1];
        }
    }
}

int main(void) {
    int sign = 0, len = 1; //sign : 해당 구간의 부호, len : 해당 구간의 길이
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][0]);
    }
    st[sp++] = 1;
    for (int i = 2; i <= n; i++) {
        if (len == 1) {
            //1칸인 경우 부호를 정한다.
            len = 2;
            if (a[i][0] == a[i - 1][0] + 1) sign = 1;
            else if (a[i][0] == a[i - 1][0] - 1) sign = -1;
            else {
                //1칸짜리 구간인 경우
                ed[ep++] = i - 1;
                st[sp++] = i;
                len = 1;
            }
        }
        else if (a[i][0] - a[i - 1][0] != sign) {
            //부호에 맞지 않는 수가 나온 경우
            if (len == 2) {
                ed[ep++] = i - 2;
                st[sp++] = i - 1;
            }
            ed[ep++] = i - 1;
            st[sp++] = i;
            len = 1;
        }
        else len++;
    }
    if (len == 2) {
        ed[ep++] = n - 1;
        st[sp++] = n;
    }
    ed[ep++] = n;

    for (int i = 0; i < sp; i++) {
        for (int j = 0; j < ep; j++) {
            if (st[i] > ed[j]) continue;
            mv[0][0] = st[i];
            mv[0][1] = ed[j];
            swap(st[i], ed[j], 1);
            check();
            if (flag) break; //정답이 나온 경우 탐색 종료
        }
        if (flag) break;
    }
    if (!flag) return 1;
    printf("%d %d\n%d %d", mv[0][0], mv[0][1], mv[1][0], mv[1][1]);

    return 0;
}