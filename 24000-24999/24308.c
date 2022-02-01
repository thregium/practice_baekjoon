#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
���� : 100�� ������ ��� �Ǵ� ������ �־�����. �̶�, �� ������ ��Ȯ�� 2���� �ڸ����� �ٲپ�
��������� �� ��� 6���� ������ �������� ���� ū ���� ���Ѵ�. 0���� �����ؼ��� �� �ȴ�.

�ذ� ��� : 2���� �ڸ��� �� �� �� �ڸ��� ��� ���� �ڸ��� �ٸ��� 6���� ������ ��������
(������ �ڸ��� ¦���̰� ��� �ڸ����� ���� 3��) ���� ��� Ȯ���Ѵ�. �� �� ���� ū ���� ���� �Ǵµ�,
�̴� ��� �ڸ����� �����Ƿ� ���ڿ� �񱳸� ���� �˾Ƴ� �� �ִ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : IATI 2018 D1��
*/

char s[128], res[128], tmp[128], orig[128];

int main(void) {
    int l, rl = 0, sg = 0, sm = 0, r = 0;
    scanf("%s", s);
    l = strlen(s);
    sg = (s[0] == '-');
    if (sg) orig[0] = '-';
    rl = sg;
    if (l < 2) return 1;
    for (int i = 0; i < l; i++) {
        if (isdigit(s[i])) {
            sm += s[i] - '0';
            orig[rl++] = s[i];
        }
    }
    strcpy(tmp, orig);
    for (int i = sg; i < rl; i++) {
        for (int a = 9; a >= 0; a--) {
            if (i == sg && a == 0) continue;
            for (int j = i + 1; j < rl; j++) {
                if (orig[i] - '0' == a) continue;
                for (int b = 9; b >= 0; b--) {
                    if (orig[j] - '0' == b) continue;
                    if ((j != rl - 1 && ((orig[rl - 1] - '0') & 1)) || (j == rl - 1 && (b & 1))) continue;
                    if ((sm + (a - orig[i] + '0') + (b - orig[j] + '0')) % 3) continue;
                    tmp[i] = a + '0';
                    tmp[j] = b + '0';
                    if (r++ == 0) strcpy(res, tmp);
                    else if ((sg && strcmp(res, tmp) > 0) || (!sg && strcmp(res, tmp) < 0)) {
                        strcpy(res, tmp);
                    }
                    tmp[i] = orig[i];
                    tmp[j] = orig[j];
                }
            }
        }
    }
    printf("%s", res);
    return 1;
}