#include <stdio.h>
#include <string.h>

/*
���� : 100�� ������ �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, ���ڿ��� ���� �������� 2���� ���Ϸ�
���̱� ���� ������ �ϴ� ������ �ּ� ������ ���Ѵ�.

�ذ� ��� : ���� ������ ������ ���Ʈ ������ ���� �ϳ��� �غ��鼭 ���� ���� ���� �� �ִ� �����
����� ���� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : PacNW 2015 P�� // SEUSA 2015D1 I�� / 2015D2 J��
*/

char s[128];

int main(void) {
    int len, cnt, best = 103000;
    scanf("%s", s);
    len = strlen(s);
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            cnt = 0;
            for (int k = 0; k < len; k++) {
                if (s[k] != i && s[k] != j) cnt++;
            }
            if (cnt < best) best = cnt;
        }
    }
    if (best == 103000) return 1;
    printf("%d", best);
    return 0;
}