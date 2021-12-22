#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� S(S <= 20)�� �빮�ڷ� �̷���� ���ڿ��� �־�����. �� ���ڿ��� ������������ �� ���ڵ��� �ϳ��� ���ڷ� �� ����
�̾���� �� ������ ���� ��������ٰ� ���� ��, ���� ���ڵ�� �̷���� ���ڿ��� ����Ѵ�.

�ذ� ��� : ���ں��� �� ���ĺ��� �����ϴ� Ƚ���� ���캸�� 0�� ���� Z, 2�� ���� W, 6�� ���� X, 8�� ���� G�� �������� �� �� �ִ�.
�̷��� ���ڵ��� �����ϰ� ���� 3�� ���� H�� ����������, ����� ������� ������ ���鵵 ������ ���ĺ����� �����ϰ� �ȴ�.
�̸� ������� ���ڿ��� ���� ����, �־����� ���ڿ����� �� ���ڿ��� ������ ����.
�׷��� ���� ������� ������ ������ ������ ���� �ش� ������ ������ ã�� �� �ִ�. ã�� �������� �̸� ��� ���ڿ��� �߰��ϰ�,
�ش� ���ڿ� �ִ� ���ĺ����� ������ŭ ���ؼ� �����. �̸� �� ���ڿ� ���� �ݺ��� ���� ��� ���ڿ��� ������������ �����ϸ�
���� ã���� �ϴ� ���ڿ��� ���� �� �ִ�.

�ֿ� �˰��� : ���ڿ�, �ֵ� Ȥ

��ó : GCJ 2016_1B A2��
*/

char* numorder = "0268345179";
char* alphorder = "ZWXGHRFOVE";
char* numalph[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
char s[2048], r[2048];
int cnt[26];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, p, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            cnt[s[i] - 'A']++;
        }
        p = 0;
        for (int i = 0; i < 10; i++) {
            c = cnt[alphorder[i] - 'A'];
            if (c < 0) return 1;
            for (int j = 0; j < c; j++) {
                r[p++] = numorder[i];
            }
            for (int j = 0; numalph[numorder[i] - '0'][j]; j++) {
                cnt[numalph[numorder[i] - '0'][j] - 'A'] -= c;
            }
        }
        r[p] = '\0';
        qsort(r, p, sizeof(char), cmp1);
        printf("Case #%d: %s\n", tt, r);
    }
    return 0;
}