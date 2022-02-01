#include <stdio.h>
#include <string.h>

/*
���� : 100�� ������ �빮�ڿ� '_'�� �̷���� ���ڿ��� �ִ�. '_'�� 10�� ���ϴ�. �� ���ڿ�����
'_'�� �빮�ڸ� �־� ���� �� �ִ� 3 �������� ���� �Ǵ� ������ ���� �ʰ� 'L'�� 1�� �̻� ������
���ڿ��� ������ ���Ѵ�.

�ذ� ��� : �� �պ��� ���ڿ��� 'L', 'L'�� ������ ����, ������ ���� �־�鼭
�־��� ������ �����ϴ� �� Ȯ���Ѵ�. ���ڿ��� ������ ������ �����ϴ� �� ���ǰ� �������� ������ �����Ѵ�.
���ڿ��� ���� �����ϸ� ���ݱ��� ���� ����(L ����), ������ ������ Ȯ���ϸ� 20^���� + 5^������
�信 ���س�����. ��� ��츦 �õ��غ� �� ���� ���� ���� �ȴ�. �����÷ο� ���� Ȯ�ο� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����, ���շ�

��ó : COCI 09/10#3 3��
*/

char s[128];
long long r = 0;

int isvowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return 1;
    else return 0;
}

void track(int l, int p, int v, int co, int cl) {
    if (p == l) {
        long long t = 1;
        for (int i = 0; i < v; i++) t *= 5;
        for (int i = 0; i < co; i++) t *= 20;
        if (cl) r += t;
        return;
    }
    if (p >= 2 && s[p] != '_') {
        if (isvowel(s[p]) == isvowel(s[p - 1]) && isvowel(s[p - 1]) == isvowel(s[p - 2])) return;
    }
    if (s[p] == 'L') cl++;
    if (s[p] == '_') {
        if (p < 2 || (isvowel(s[p - 1]) || isvowel(s[p - 2]))) {
            s[p] = 'B';
            track(l, p + 1, v, co + 1, cl);
            s[p] = 'L';
            track(l, p + 1, v, co, cl + 1);
            s[p] = '_';
        }
        if (p < 2 || (!isvowel(s[p - 1]) || !isvowel(s[p - 2]))) {
            s[p] = 'A';
            track(l, p + 1, v + 1, co, cl);
            s[p] = '_';
        }
    }
    else track(l, p + 1, v, co, cl);
}

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    track(l, 0, 0, 0, 0);
    printf("%lld", r);
    return 0;
}