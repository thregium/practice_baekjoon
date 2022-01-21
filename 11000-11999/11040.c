#include <stdio.h>

/*
���� : N(N <= 17)���� �ڿ����� �����ڷ� �̷���� ������ �־�����. �� �������� ������ .�� ������
�������ٰ� �� ��, �� ������ ���� ����Ѵ�. �ڿ����� �����ڴ� ���� 9�� ���Ϸ� �־�����.
����, �� �ڿ����� 1 �ڸ� ���θ� �̷���� �ִ�.

�ذ� ��� : ���� �ٱ��ʺ��� ������ �������� ���� ����� ������. ���� ���� �����ڸ� ��������
����ϸ�, ���ڰ� ������ ���ϰų� ���ϰ�, �����ڰ� ������ .�� ������ ���� .�� �������� ���� ĭ�� ������
���� ���� �� ������ ��������� ����� ���� �ᱣ���� ���ϰų� ���Ѵ�. �߰��� 1ĭ�� ���� ĭ�� ���´ٸ�
�� ĭ�� ������ ���̹Ƿ� �״�� ��ȯ�Ѵ�. �� ������ ����� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���

��ó : JDC 2015 C��
*/

char buff[64];
int level[64], num[64];

int getres(int st, int ed, int lv) {
    if (st == ed) {
        return num[st];
    }
    int op = -num[st];
    int r = op - 1, et;
    for (int i = st + 1; i <= ed; i++) {
        if (num[i] >= 0) {
            if (op == 1) r += getres(i, i, lv + 1);
            else r *= getres(i, i, lv + 1);
        }
        else {
            et = i + 1;
            while (level[et] > lv + 1) et++;
            if (op == 1) r += getres(i, et - 1, lv + 1);
            else r *= getres(i, et - 1, lv + 1);
            i = et - 1;
        }
    }
    return r;
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            level[i] = 0;
            for (int j = 0; buff[j]; j++) {
                if (buff[j] == '.') level[i]++;
                else if (buff[j] == '+') num[i] = -1;
                else if (buff[j] == '*') num[i] = -2;
                else num[i] = buff[j] - '0';
            }
        }
        printf("%d\n", getres(0, n - 1, 0));
        for (int i = 0; i < n; i++) {
            level[i] = 0, num[i] = 0;
        }
    }
    return 0;
}