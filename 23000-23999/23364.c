#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� : N(N <= 500000)���� 2 * 10^9 ���� �ڿ����� �̷���� ������ ������ �־��� ��,
�� �������� ��� ������ �� ���� ���Ѵ�.

�ذ� ��� : ������ �����ϰ� ���� ������ �� ���� ����� ã�Ƴ�����
������ ��� ���谡 �Ǵ� ������ ã�� �� �ִ�.

�ֿ� �˰��� : ����, ������, ������ȭ

��ó : BAPC 2021P A��
*/

int a[524288][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    //srand(time(NULL));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = i + 1;
        //a[i] = (((long long)rand() << 16) + (long long)rand()) % 2000000000 + 1;
    }
    qsort(a, n, sizeof(int) * 2, cmp1);
    //srand(clock());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j][0] % a[i][0] == 0) {
                printf("%d %d", a[i][1], a[j][1]);
                //printf("%d %d", a[i], a[j]);
                return 0;
            }
        }
    }
    return 1;
}