#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 123456)���� ���� �ְ�, 1�� ���� ������ ���鿡 ���� �Ǵ� ���� A_i(A_i <= 10^9)���� �ִ�.
�� ������ Ʈ�� ���·� ����Ǿ� �ִ�. �̶�, ����� 1�� ������ �̵��ϰ�, �� ����� �ִ� 1��������
���� ��ƸԴ´ٸ� 1�� ���� ������ �� �ִ� ���� ���� ���Ѵ�.

�ذ� ��� : Ʈ�� DP�� �̿��� �� ���� �� ��� ���� ���� �� ����, �� �� ���� ���� ���̰�, �� ���� �� ����
��ȯ�� ������. �̸� �ݺ��Ͽ� 1�� ���� �� ���� ���Ѵ�. �����÷ο� �����Ѵ�.

�ֿ� �˰��� : DP, Ʈ��DP

��ó : ��ϴ� 2018 ���
*/

long long isle[131072][2], par[131072];
vector<int> chd[131072];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long dp(int x) {
    for (int i : chd[x]) {
        isle[x][0] += dp(i);
    }
    long long van = small(isle[x][0], isle[x][1]);
    isle[x][0] -= van;
    isle[x][1] -= van;
    return isle[x][0];
}

int main(void) {
    int n, a, p;
    char t;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf(" %c %d %d", &t, &a, &p);
        if (t == 'W') isle[i][1] = a;
        else if (t == 'S') isle[i][0] = a;
        else return 1;
        chd[p].push_back(i);
        par[i] = p;
    }
    printf("%lld", dp(1));
    return 0;
}