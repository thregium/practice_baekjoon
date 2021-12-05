#include <stdio.h>

/*
���� : N(N <= 50)���� ���� �ٸ� �ڿ���(<= 10^6)�� �̷���� �迭�� �־��� ��, S(S <= 10^6)�� ���Ϸ� ������ �� ����
������ �ٲپ� ���� �� �ִ� ���������� ���� �޼��� �迭�� ���Ѵ�.

�ذ� ��� : �� �տ������� ���� �̵� Ƚ�� ���� �ٲ� �� �ִ� ���� ū ���� ã�� �� ���� ���ϴ� ��ġ�� ������� ���� �ݺ��Ѵ�.
�̸� �迭�� ������ �ݺ��ϸ� ������� ������ ���� ū ���� ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : SRM 307 D1A / D2B
*/

int arr[64];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, s, best = -1, bp = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &s);
    for (int i = 0; i < n; i++) {
        best = arr[i], bp = i;
        for (int j = i + 1; j - i <= s && j < n; j++) {
            if (arr[j] > best) {
                best = arr[j];
                bp = j;
            }
        }
        for (int j = bp; j > i; j--) {
            swap(&arr[j], &arr[j - 1]);
        }
        s -= bp - i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}