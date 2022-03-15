#include <stdio.h>
#include <string.h>

/*
���� : ���� 100000 ������ ��ȣ�� �̷���� ���ڿ��� �־��� ��, �� ���ڿ����� �� ���� ��ȣ�� ������
���� �� �ִ� ��ȣ ���ڿ��� ������ ���Ѵ�. ���� 1 �̻��̴�.

�ذ� ��� : ���� 1 �̻��̹Ƿ� (�� )�� ���̴� 1�̴�. �켱 (�� ���� ��츦 ������ ����
��ȣ�� ���� ���� ���ʺ��� �� ����, � (�� ����� �� ������ ���Ŀ� ������ ������ �ʾƾ� �Ѵ�.
�׷��� ���ؼ��� �ּڰ��� �����ʺ��� Ȯ���ϸ鼭 0���� Ŭ ���� (�� ������ ���� �ȴ�.
)�� ���� ���� ���ڿ��� ������ ���� �Ȱ��� �ϸ� �ȴ�.

�ֿ� �˰��� : ���� ��?

��ó : ���� 2020 K��
*/

char s[103000];
int lv[103000];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int res = 0, lt = 0, rt = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') lt++;
        else rt++;
        lv[i] = lt - rt;
    }
    if (lt == rt + 1);
    else if (rt == lt + 1) {
        for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
            swap(&s[i], &s[j]);
        }
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') s[i] = ')';
            else s[i] = '(';
        }
        lt = 0, rt = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') lt++;
            else rt++;
            lv[i] = lt - rt;
        }
    }
    else return 1;

    for (int i = strlen(s) - 2; i >= 0; i--) {
        if (lv[i + 1] < lv[i]) lv[i] = lv[i + 1];
        if (lv[i] < 0) res = -103000;
    }
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' && lv[i] > 0) res++;
    }
    printf("%d", res < 0 ? 0 : res);
    return 0;
}