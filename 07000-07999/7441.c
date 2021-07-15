#include <stdio.h>

/*
���� : N(N <= 100)���� ������ ���� K(K <= 100)�� ������ ����� ����� �־�����. �̶� �־��� ����� ����
���԰� �ٸ� �ϳ��� ������ ���� �� �ִ��� Ȯ���ϰ� �ִٸ� �� ������ ��ȣ�� ����Ѵ�. ��, ��� ������ �Ѱ����� �ִ�.

�ذ� ��� : N�� K�� ũ�Ⱑ �۱� ������ ��� ������ ���� �� ������ �ٸ� �������� �����ų� ���̴ٰ� �����ϰ�
����� �����غ���. �����ϸ� �� ������ �����ų� ���ſ� �� �ִ� ���̴�. ��� ������ ���� Ȯ���� ��
���԰� �ٸ� �� �ִ� ������ ���� 1���� ��� �� ������ ��ȣ�� ����ϰ� 1���� �ƴ϶�� ���� �� ���ٰ� �ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : NEERC 1998 A��
*/

int weight[128][128];

int main(void) {
    int n, k, res = 0, cnt = 0, twt, trs;
    char c;
    //freopen("E:\\PS\\ICPC\\Northern Eurasia\\Final\\1998\\TESTS\\COIN.20", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &weight[i][0]);
        for (int j = 1; j <= weight[i][0] * 2; j++) {
            scanf("%d", &weight[i][j]);
        }
        scanf(" %c", &c);
        if (c == '<') weight[i][127] = -1;
        else if (c == '>') weight[i][127] = 1;
    }
    for (int i = 1; i <= n; i++) {
        trs = 1;
        for (int j = 0; j < k; j++) {
            twt = 0;
            for (int ii = 1; ii <= weight[j][0]; ii++) {
                if (weight[j][ii] == i) twt++;
            }
            for (int ii = weight[j][0] + 1; ii <= weight[j][0] * 2; ii++) {
                if (weight[j][ii] == i) twt--;
            }
            if (twt != weight[j][127]) {
                trs = 0;
                break;
            }
        }
        if (trs) {
            res = i;
            cnt++;
            continue;
        }
        trs = 1;
        for (int j = 0; j < k; j++) {
            twt = 0;
            for (int ii = 1; ii <= weight[j][0]; ii++) {
                if (weight[j][ii] == i) twt--;
            }
            for (int ii = weight[j][0] + 1; ii <= weight[j][0] * 2; ii++) {
                if (weight[j][ii] == i) twt++;
            }
            if (twt != weight[j][127]) {
                trs = 0;
                break;
            }
        }
        if (trs) {
            res = i;
            cnt++;
        }
    }

    if (cnt == 1) printf("%d", res);
    else printf("0");
    return 0;
}