#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : [A, B](1 <= A <= B <= 10^11) ������ �ڿ����� ��� �������̸鼭 ����� 0���� �������� �ʴ�
�������� ���� ������ ���Ѵ�.

�ذ� ��� : ��� ���� ���� �������� ���� �־��� ���ǿ� �´� �� Ȯ���ϸ� �ȴ�.
��, ������ ���θ� Ȯ���ϱ� ���� ����� �����ؾ� �Ѵ�.(�� �ڵ忡���� ��ó�� + �̺� Ž���� ����ߴ�.)

�ֿ� �˰��� : ����, ���Ʈ ����, �̺� Ž��, ����

��ó : ROI 2021H A��
*/

char s[16];
long long sqr[327680];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void revstring(char* s) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        swap(&s[i], &s[j]);
    }
}

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long a, b, c, r = 0;
    scanf("%lld %lld", &a, &b);
    for (long long i = 1; i < 327680; i++) {
        sqr[i] = i * i;
    }
    for (long long i = 1; i < 327680; i++) {
        if (i * i < a || i * i > b) continue;
        sprintf(s, "%lld", i * i);
        revstring(s);
        if (s[0] == '0') continue;
        c = strtoll(s, NULL, 10);
        if (bsearch(&c, sqr, 327680, sizeof(long long), cmp1)) r++;
    }
    printf("%lld", r);
    return 0;
}