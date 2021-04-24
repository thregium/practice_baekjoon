#include <stdio.h>
#include <ctype.h>

/*
���� : ��й�ȣ�� �־����� �� ��й�ȣ�� ��ȿ���� �˻��Ѵ�.
��ȿ�� ��й�ȣ�� �빮��, �ҹ���, ����, Ư�����ڰ� 1�� �̻� ���ԵǾ�� �ϰ�, 12�� �̻��̾�� �Ѵ�.

�ذ� ��� : ����, ��й�ȣ�� ���̸� Ȯ���� 12�ں��� ���ٸ� ��ȿ���� ������ ����Ѵ�.
12�� �̻��� ���, �� ������ Ÿ�Ժ��� ������ ���� 0���� ���� �ִٸ� ��ȿ���� ���� ���̰� ���� 1�� �̻��� ��� ��ȿ�� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : AIPO 2017F 2��
*/

char pw[128];

int main(void) {
    int t, n, u, l, d, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d%s", &n, pw);
        if (n < 12) {
            printf("invalid\n");
            continue;
        }
        u = 0, l = 0, d = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (isupper(pw[i])) u++;
            else if (islower(pw[i])) l++;
            else if (isdigit(pw[i])) d++;
            else s++;
        }
        if (u && l && d && s) printf("valid\n");
        else printf("invalid\n");
    }
    return 0;
}
