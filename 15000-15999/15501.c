#include <stdio.h>

/*
���� : 1���� N(N <= 10^6)������ �ڿ����� �̷���� �� ������ �־��� ��, �� ��° �������� 1ĭ�� �б� �Ǵ�
��ü ������ ������ ���� �� ����Ͽ� ù ��° ������ ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : ù ĭ�� �����ϰ� �� ������ �����غ� ���� �� ��° ������ ������ �̸� �� �� �� �غ���.
�� �� �ϳ����� �� ������ ���ٸ� ���� �� �ְ�, �� �ܿ��� ���� �� ����.

�ֿ� �˰��� : ����?

��ó : ����Ʈ�� 1ȸ A��
*/

int a[1048576], b[1048576];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, stt = -1, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (b[i] == a[0]) {
            if (stt >= 0) return 1;
            stt = i;
        }
    }
    if (stt < 0) return -1;

    t = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[(stt + i) % n]) t = 0;
    }
    if (t) {
        printf("good puzzle");
        return 0;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--) swap(&b[i], &b[j]);

    stt = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] == a[0]) {
            if (stt >= 0) return 1;
            stt = i;
        }
    }
    if (stt < 0) return -1;
    t = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[(stt + i) % n]) t = 0;
    }
    if (t) printf("good puzzle");
    else printf("bad puzzle");
    return 0;
}