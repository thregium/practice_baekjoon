#include <stdio.h>
#define SZ 131072

/*
문제 : 두 명의 플레이어가 N(N <= 100000)개의 1 ~ N까지의 자연수로 이루어진 순열을 이용한 게임을 진행한다.
각 턴마다 플레이어는 인접한 두 수 가운데 앞 수가 더 큰 두 수의 순서를 바꾼다. 이때 이러한 수가 여러개인 경우
가장 유리한 것을 고른다. 바꿀 수 있는 수가 없다면 진다. 이때 이기는 플레이어를 구한다.

해결 방법 : 플레이어의 선택에 상관없이 처음 순열에 따라 바꿀 수 있는 횟수가 정해져있다.
이 값은 버블 소트에서 교환 연산의 횟수와 같으며, 1517번의 풀이를 그대로 가져온 다음, 이 값이 홀수인 경우
선공이 이기고 짝수인 경우 후공이 이긴다고 출력하면 된다.

주요 알고리즘 : 자료구조, 세그먼트 트리, 게임 이론

출처 : Brasil 2008 E번
*/

int x[103000];
long long seg[SZ << 1];

void upd(int p, int n) {
    seg[SZ + p] = n;
    for (int i = ((SZ + p) >> 1); i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

long long find(int fs, int fe, int ss, int se, int p) {
    if (fs > se || fe < ss) return 0;
    else if (fs <= ss && se <= fe) return seg[p];
    else return find(fs, fe, ss, (ss + se) >> 1, p << 1) + find(fs, fe, ((ss + se) >> 1) + 1, se, (p << 1) + 1);
}

int main(void) {
    int n;
    long long r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\E.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x[i]);
            upd(x[i], 1);
            r += x[i] - find(0, x[i] - 1, 0, SZ - 1, 1) - 1;
        }

        for (int i = 1; i <= n; i++) {
            upd(i, 0);
        }
        if (r & 1) printf("Marcelo\n");
        else printf("Carlos\n");
    }
    return 0;
}