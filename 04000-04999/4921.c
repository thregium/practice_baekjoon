#include <stdio.h>

/*
���� : 10000�� ������ ���� ������ �Ϸķ� ���� �������� ���Ѵ�. 1�� ���Ͽ��� �����ؼ� 2�� ���Ͽ��� ������ �Ѵ�.

�ذ� ��� : ���� 1�� ���Ͽ��� �������� Ȯ���ϰ�, �׷��� ��� �� ������ ���� ������ �¾� ������ ���Ѵ�.
�̶�, 2�� ������ ���� ������ NULL�� �����Ѵ�. ��� ��� �´ٸ� ���� �����ϰ�, �ϳ��� ���� �ʴ´ٸ� ���� �Ұ����ϴ�.

�ֿ� �˰����� : ����

��ó : Arab 2006 C��
*/

char s[10240];

int main(void) {
    int r = 1;
    for (int tt = 1;; tt++) {
        scanf("%s", s);
        if (s[0] == '0') break;
        r = (s[0] == '1');
        for (int i = 0; s[i]; i++) {
            if (s[i] == '1' && !(s[i + 1] == '4' || s[i + 1] == '5')) r = 0;
            if (s[i] == '2' && !(s[i + 1] == '\0')) r = 0;
            if (s[i] == '3' && !(s[i + 1] == '4' || s[i + 1] == '5')) r = 0;
            if (s[i] == '4' && !(s[i + 1] == '2' || s[i + 1] == '3')) r = 0;
            if (s[i] == '5' && !(s[i + 1] == '8')) r = 0;
            if (s[i] == '6' && !(s[i + 1] == '2' || s[i + 1] == '3')) r = 0;
            if (s[i] == '7' && !(s[i + 1] == '8')) r = 0;
            if (s[i] == '8' && !(s[i + 1] == '6' || s[i + 1] == '7')) r = 0;
            if (!r) break;
        }
        printf("%d. %s\n", tt, r ? "VALID" : "NOT");
    }
    return 0;
}