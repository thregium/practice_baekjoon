#include <stdio.h>
#include <string.h>

/*
���� : 2���� 26�� ������ ���ڿ��� �����ư��� ��ĥ ��, 2���� ��ġ�� �Ǵ� ���ڿ��� ���� ���� �ݺ� ������ ����Ѵ�.

�ذ� ��� : ���ڿ��� ���̰� ¦���� ���, ù ��° ����� Ȧ����°, �� ��° ����� ¦����° ���ڵ鸸 ��ġ�� �ȴ�.
���ڿ��� Ȧ����� ù ��° ����� Ȧ����°, �� ��° ����� ¦����°�� ��ġ��, ���ڿ��� ������ �ٽ� ���ƿͼ�
ù ��° ����� ¦����°, �� ��° ����� Ȧ����°�� ���ľ� �Ѵ�.

�ֿ� �˰��� : ����?

��ó : ���δ� 2016 G��
*/

char s[32];

int main(void) {
    int t, l;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        l = strlen(s);
        if (l & 1) {
            for (int i = 0; i < l; i += 2) printf("%c", s[i]);
            for (int i = 1; i < l; i += 2) printf("%c", s[i]);
            printf("\n");
            for (int i = 1; i < l; i += 2) printf("%c", s[i]);
            for (int i = 0; i < l; i += 2) printf("%c", s[i]);
            printf("\n");
        }
        else {
            for (int i = 0; i < l; i += 2) printf("%c", s[i]);
            printf("\n");
            for (int i = 1; i < l; i += 2) printf("%c", s[i]);
            printf("\n");
        }
    }
    return 0;
}