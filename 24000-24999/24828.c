#include <stdio.h>

/*
���� : �� ���� �ƴ� ���� A, B(A <= B < 2^31)�� �־��� ��, A�� �� �ڸ����� �� �ŵ������� �ؼ� ���ؾ�
B�� �Ǵ� �� ���Ѵ�. �׷��� ���� ������ ��츸 �־�����.

�ذ� ��� : ũ�� ������ ���ϱ� ������ ��� ����� ���� ���캸�鼭 ���� ã�� ������ �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ��Ʈ��ŷ

��ó : VTH 2021 K��
*/

int arr[16];

int b10(int x) {
    if (x >= 1000000000) return 1000000000;
    else if (x >= 100000000) return 100000000;
    else if (x >= 10000000) return 10000000;
    else if (x >= 1000000) return 1000000;
    else if (x >= 100000) return 100000;
    else if (x >= 10000) return 10000;
    else if (x >= 1000) return 1000;
    else if (x >= 100) return 100;
    else if (x >= 10) return 10;
    else return 1;
}

void printkey(int a, int b, int t, int p) {
    if (t == 0) {
        if (b == 0) {
            for (int i = 0; i < p; i++) printf("%d ", arr[i]);
        }
        return;
    }
    int x = a / t % 10;
    for (long long i = t, j = 0; i <= b; i *= x, j++) {
        arr[p] = j;
        printkey(a, b - i, t / 10, p + 1);
    }
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printkey(a, b, b10(a), 0);
    return 0;
}