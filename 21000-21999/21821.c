#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� �̸�(�ҹ���, 10�� �̳�)�� �־�����. ���� K(K <= 100)���� ���۹��� ���� �̸��� ������ �־��� ��,
��� ����� �ֿ� ���� ���Ĺ� ���踦 ���Ѵ�. ������ ��� '1', �Ĺ��� ��� '0', �� �� ���� ��� '?', �ڱ� �ڽ��� ��� 'B'�̴�.
���۹��� ���� �̸��� ������ �⿩�� -> �������̴�. ��� ���۹����� �Ĺ�� ������ �⿩�� �̻��� �⿩�ߴ�.

�ذ� ��� : �� ���۹��� �̸��� ���������� �Ǿ��ִٸ� �⿩���� ���� ������ �� �� ����. �׷���, �������� �ƴ� ��쿡��
�ݵ�� ���ʿ� �ִ� ����� �⿩���� �� ���� ���̰�, �̸� �̿��� ���Ĺ� ���踦 �� �� �ִ�.
�� ���۹��� ���� �⿩���� �׷����� ������, ���� �⿩���� �ٸ� �׷볢�� ���Ĺ� ���踦 �����Ѵ�.
���� ������ �������� �÷��̵�-���� �˰����� �̿��� ���������� �̾����� ���Ĺ� ���赵 �߰��� �ָ�
�� �� �ִ� ��� ����� ���Ĺ� ���踦 �� �� �ִ�.

�ֿ� �˰��� : ���ڿ�, �׷��� �̷�, �÷��̵�-����

��ó : USACO 2021O B2��
*/

char meb[128][16], paper[128][16], res[128][128];
int group[128], pmb[128];

int main(void) {
    int k, n;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", meb[i]);
        for (int j = 0; j < n; j++) {
            if (i == j) res[i][j] = 'B';
            else res[i][j] = '?';
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", paper[j]);
            if (j == 0) group[j] = 1;
            else if (strcmp(paper[j], paper[j - 1]) < 0) group[j] = group[j - 1] + 1;
            else group[j] = group[j - 1];
            for (int kk = 0; kk < n; kk++) {
                if (!strcmp(paper[j], meb[kk])) pmb[j] = kk;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int kk = j + 1; kk < n; kk++) {
                if (group[j] == group[kk]) continue;
                res[pmb[j]][pmb[kk]] = '0';
                res[pmb[kk]][pmb[j]] = '1';
            }
        }
    }
    
    for (int kk = 0; kk < n; kk++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][kk] == '1' && res[kk][j] == '1') res[i][j] = '1';
                if (res[i][kk] == '0' && res[kk][j] == '0') res[i][j] = '0';
            }
        }
    }
    

    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}