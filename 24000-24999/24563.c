#include <stdio.h>

/*
���� : P���� ������ ���ϰ� U(P + U <= 100)���� �������� ���� ������ �ִ�. �� ������ ������ ������ Ǯ��
�������� ���� ���� ����� �� ������ ����, �������� ���� ������ �����ϸ� ������ ���� ����� �� �ڷ� ����.
�̶�, ������ ��ġ�� �ٲ� ���°� �Է°� ���� �־����� �ش� ���·� �ٲٱ� ���� �ʿ���
���� �Ǵ� ������ Ǫ�� Ƚ���� ���Ѵ�.

�ذ� ��� : �켱 ������ ������ �������� ���� ���Ϸ� �ٲٰų� �� �ݴ��� ��쿡�� �ݵ�� 1�� �̵��ؾ� �Ѵ�.
����, �ڽź��� ������ ������ ������ ���� ������ �̵��ؾ� �ϴ� ��� �ݵ�� 2�� �̵��Ͽ� ���ƿ;�
������ ������ �ڷ� �� �� �ִ�. ������ ������ ������ (�ݴ� ���¿��� �̵��� ����, �ڽ��� �ڿ�(�������� ���� ���
�տ�) �ִ� ����, 2�� �̵��� ����)�� 3 �����̴�.
����, 1�� �ݴ� ���·� �̵��ϸ� �ٽ� ���� ���·� ���ƿ� �� � �����ε� ���ƿ� �� �ֱ� ������
�ݵ�� �̵��ؾ� �ϴ� ��츸 �Ű澲�� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : ECNA 2021 I��
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