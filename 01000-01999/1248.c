#include <stdio.h>

/*
���� : N(<= 10) ũ���� �迭�� -10���� 10 ������ ������ ���� �ִ�. �̶�, ��� ���� �տ� ���� ���� ���ΰ� �־�����
������ �迭 ��� �ϳ��� ����Ѵ�. ���� ���� �־����� �ʴ´�.

�ذ� ��� : ù ��° ������ ������ ��� ��츦 �غ���. ���� ���� �ϳ��� ���� ���̶� �������� ���Ѵٸ�
Ž���� �����ϰ� ���� ���� Ž���Ѵ�. ���������� ���� ���� ���ϸ� ���� �� �ð��� ������ �� �ִ�.

�ֿ� �˰��� : ��Ʈ��ŷ, ���� ��

��ó : Seoul 2008 G��
*/

int a[16][16], arr[16];
int r = 0;

int track(int n, int x) {
    if (n == x) {
        r = 1;
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        return;
    }

    int s, t;
    for (int i = -10; i <= 10; i++) {
        arr[x] = i;
        s = 0, t = 1;
        for (int j = x; j >= 0; j--) {
            s += arr[j];
            if (a[j][x] < 0 && s >= 0) t = 0;
            if (a[j][x] == 0 && s != 0) t = 0;
            if (a[j][x] > 0 && s <= 0) t = 0;
            if (!t) break;
        }
        if (!t) continue;
        track(n, x + 1);
        if (r) return;
    }
}

int main(void) {
    int n;
    char c;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            c = getchar();
            if (c == '0') a[i][j] = 0;
            else if (c == '-') a[i][j] = -1;
            else if (c == '+') a[i][j] = 1;
            else return 1;
        }
    }
    track(n, 0);
    if (r == 0) return 1;
    return 0;
}