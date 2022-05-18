#include <stdio.h>

/*
���� : N(N <= 100)���� ������� OX��� �� ����� �־�����. ���� ������ K(K <= 100)���̴�.
����� O, X, ���� ���� �� �� �ϳ��̴�. �̶�, ������ O, X�� ���� ���ؼ�
��� ����� ���� �ִ� 1�� ���Ϸθ� ���ߵ��� �ϴ� ����� �ִ� �� Ȯ���ϰ�, �ִٸ� �׷��� ��� ��
���������� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �켱, ���� ��� �ϳ��� ���ߵ��� �ߴٸ� �������� ��� Ʋ���� �ؾ� �Ѵ�.
�̸� ������ ���� ����� �ٲٸ� 2-SAT�� �ȴ�. ���� �÷��̵�-���� �˰����� ����
�� ������ ���� �̵� ������ ��� ������ �����ش�.

�� ������ ���� �������� �� �տ������� F, T ������� ������ �� Ȯ���غ��鼭 ��������� ���ǿ� ����� ����
�� ������ �߰��ص� ����� ������ �ʴ� ��� �װ��� ������ ������ �ȴ�.
�� �������� �� �� ������ �� ���� ��찡 ����� ������ ���̴�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�, 2-SAT, �׸��� �˰���

��ó : PacNW 2021 J/W�� // SCUSA 2021D1 E�� // MidC 2021 F�� // NENA 2021 I��
*/

char stu[128][128], res[128];
int reach[256][256];

int main(void) {
    int n, k, r = 1, av;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", stu[i]);
        for (int j = 0; j < k; j++) {
            if (stu[i][j] == 'X') continue;
            for (int jj = 0; jj < k; jj++) {
                if (jj == j || stu[i][jj] == 'X') continue;
                reach[j * 2 + (stu[i][j] == 'T')][jj * 2 + (stu[i][jj] == 'F')] = 1;
            }
        }
    }
    for (int p = 0; p < k * 2; p++) {
        for (int i = 0; i < k * 2; i++) {
            for (int j = 0; j < k * 2; j++) {
                reach[i][j] |= (reach[i][p] & reach[p][j]);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        av = 0;
        if (res[i]) continue;
        if (!reach[i * 2][i * 2 + 1]) {
            av = 1;
            for (int j = 0; j < k; j++) {
                if (j == i) continue;
                if (reach[i * 2][j * 2] && reach[i * 2][j * 2 + 1]) av = 0;
                if (reach[i * 2][j * 2] && res[j] == 'T') av = 0;
                if (reach[i * 2][j * 2 + 1] && res[j] == 'F') av = 0;
            }
            if (av) {
                res[i] = 'F';
                for (int j = 0; j < k * 2; j++) {
                    if (j == i * 2) continue;
                    if (reach[i * 2][j]) res[j >> 1] = ((j & 1) ? 'T' : 'F');
                }
            }
        }
        if (!av && !reach[i * 2 + 1][i * 2]) {
            av = 1;
            for (int j = 0; j < k; j++) {
                if (j == i) continue;
                if (reach[i * 2 + 1][j * 2] && reach[i * 2 + 1][j * 2 + 1]) av = 0;
                if (reach[i * 2 + 1][j * 2] && res[j] == 'T') av = 0;
                if (reach[i * 2 + 1][j * 2 + 1] && res[j] == 'F') av = 0;
            }
            if (av) {
                res[i] = 'T';
                for (int j = 0; j < k * 2; j++) {
                    if (j == i * 2 + 1) continue;
                    if (reach[i * 2 + 1][j]) res[j >> 1] = ((j & 1) ? 'T' : 'F');
                }
            }
        }
        if (!av) r = 0;
    }
    if (!r) printf("-1");
    else printf("%s\n", res);
    return 0;
}