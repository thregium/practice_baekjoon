#include <stdio.h>
#include <string.h>

/*
���� : 9 * 9 ũ��� �� ��ġ�� �ִ� ������ ������ �־�����. ����, ����, 3 * 3 ũ�� �簢������
�� ������ �������� �� ��� ��� �� ĭ�� ���� ������ ��� �ٸ��� �Ǵ� �� ���Ѵ�.
������ ��� 9������ ������ �־�����.

�ذ� ��� : �� ������ ������ Ȯ���ϰ� ���� �� ���� �ٲ۴�. �� ���� ������ ��Ģ�� ������ �� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Manila 2016 G��
*/

char buff[8];
char* p[9] = { "O", "WO", "WS", "ES", "MS", "CS", "IS", "OS", "SS" };
int sdk[9][9], cnt[9];

int main(void) {
    int n, r, t;
    scanf("%d", &n);
    for (int tt = 0; tt < n; tt++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%s", buff);
                t = 0;
                for (int k = 0; k < 9; k++) {
                    if (!strcmp(buff, p[k])) {
                        t++;
                        sdk[i][j] = k;
                    }
                }
                if (t != 1) return 1;
            }
        }

        r = 1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cnt[sdk[i][j]]++;
            }
            for (int j = 0; j < 9; j++) {
                if (cnt[j] != 1) r = 0;
                cnt[j] = 0;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cnt[sdk[j][i]]++;
            }
            for (int j = 0; j < 9; j++) {
                if (cnt[j] != 1) r = 0;
                cnt[j] = 0;
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cnt[sdk[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3]]++;
            }
            for (int j = 0; j < 9; j++) {
                if (cnt[j] != 1) r = 0;
                cnt[j] = 0;
            }
        }
        printf("%s\n", r ? "all 3" : "not");
    }
    return 0;
}