#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 300000)���� ���(0 <=, <= 10^8)�� �־��� ��, ���� X%�� ����� ���� ��� Y%�� ����
Y - X�� ���� Ŭ ���� Y, X�� ���Ѵ�.

�ذ� ��� : ����� ������������ ������ ����, ��ü ���� ���ϰ�, �ٽ� ���� ���� ���س����鼭
���� �� / ��ü ���� ������ ��� �� / ��ü ��� ���� ���� ���� ���̰� Ŀ�� ���� �� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ����

��ó : COCI 16/17#5 2��
*/

int a[327680];
int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long sum = 0, psum = 0;
    double x = 0.0, y = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    qsort(a, n, sizeof(int), cmp1);

    for (int i = 0; i < n; i++) {
        psum += a[i];
        if (psum / (double)sum - (i + 1.0) / n > y - x) {
            x = (i + 1.0) / n;
            y = psum / (double)sum;
        }
    }
    printf("%.9f\n%.9f", x * 100.0, y * 100.0);
    return 0;
}