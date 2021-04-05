#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� ���� S�� �־��� ��, A < B�� �����ϰ�, [A, B]�� S�� ���Ұ� ���� ���� ��� N�� �����ϴ� �ڿ��� ������ ���� ���Ѵ�.
(L <= 50, Si <= 1000)

�ذ� ��� : Si�� �ִ��� ũ�� �����Ƿ� ���Ʈ ������ ���� ��� ������ Ȯ���ϰ� ���ǿ� �´� ��츸 Ȯ���ص� ����ϴ�.

�ֿ� �˰��� : ���Ʈ ����
*/

int s[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, n, r = 0;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &n);
    qsort(s, l, sizeof(int), cmp1);
    for (int j = 1; j < s[0]; j++) {
        for (int k = j + 1; k < s[0]; k++) {
            if (n >= j && n <= k) r++; //�� �� ���� ó��
        }
    }
    for (int i = 1; i < l; i++) {
        for (int j = s[i - 1] + 1; j < s[i]; j++) {
            for (int k = j + 1; k < s[i]; k++) {
                if (n >= j && n <= k) r++; //�̿� ���� ó��
            }
        }
    }
    printf("%d", r);
    return 0;
}