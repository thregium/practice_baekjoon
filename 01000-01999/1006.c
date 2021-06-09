#include <stdio.h>

/*
���� : ���� �ѷ� �κ��� 2 * N(N <= 10000) ũ��� ��������. �� ĭ���� 10000 ������ ������ �����ִ�.
������ ������ �� ĭ�� ���� W(W <= 10000)���� �۴ٸ� �� ĭ�� �ѹ��� ������ �� �ְ�, �ƴ϶�� �� ĭ���� ������ �� �ִ�.
�� ĭ���� ���ǿ� �°� ������ ���� �ʿ��� ������ �ּ� ������ ���Ѵ�.

�ذ� ��� : ���� ù ��° ���� ������ �� ���� ������ �������� Ȯ���Ѵ�. ù ���� ������ �� ���� ��� ������ ���� ���¿� ����
���� �� �ִ� ������ �ּ� ������ ���� ���Ѵ�. �ּ� ������ ���̳��� ���α׷����� ���� ���Ѵ�.
���� �������� �ش� ĭ���� ä�� ���¿��� �ʿ��� ������ �ּ� ������ �ٱ���, ����, ���� ���ִ� ���¿� ���� ���� ���Ѵ�.
�� ���� ä���� �ϴ� ��� �κ��� ä���� �� �ش� ��ġ������ ���� ������ �������� �ȴ�.
��� ���¿� ���� �ּ� ���� ��� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : DP, ����DP
*/

int wontagon[10240][2], mem[10240][3]; //0 : �ٱ��ʸ� ���ִ� ���, 1 : ���� ��� ���ִ� ���, 2 : ���ʸ� ���ִ� ���

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int n, int w, int s) {
    //s == 0 : ù ĭ�� ������ ĭ�� ������� ����, 1 : �ٱ��ʸ� �����, 2 : ���ʸ� �����, 3 : ���� ��� �����
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) mem[i][j] = 987654321; //���Ѵ�� �ʱ�ȭ
    }

    //������ �ʱ�ȭ
    mem[0][1] = 0;
    if (s & 1) mem[1][0] = 0;
    else mem[1][0] = 1;
    if (s & 2) mem[1][2] = 0;
    else mem[1][2] = 1;
    mem[1][1] = small(mem[1][0], mem[1][2]) + 1;
    if (s == 3) mem[1][1] = 0;
    if (wontagon[1][0] + wontagon[1][1] <= w) mem[1][1] = small(mem[1][1], mem[0][1] + 1);

    for (int i = 2; i <= n; i++) {
        mem[i][0] = mem[i - 1][1] + 1; //��ĭ
        mem[i][2] = mem[i - 1][1] + 1; //��ĭ

        if (wontagon[i][0] + wontagon[i - 1][0] <= w) {
            mem[i][0] = small(mem[i][0], mem[i - 1][2] + 1); //�ٱ���, ��ĭ
        }
        if (wontagon[i][1] + wontagon[i - 1][1] <= w) {
            mem[i][2] = small(mem[i][2], mem[i - 1][0] + 1); //����, ��ĭ
            if (wontagon[i][0] + wontagon[i - 1][0] <= w) {
                mem[i][1] = small(mem[i][1], mem[i - 2][1] + 2); //�ٱ��� + ����, ��ĭ * 2
            }
        }
        mem[i][1] = small(mem[i][1], small(mem[i][0], mem[i][2]) + 1); //����, ����
        if (wontagon[i][0] + wontagon[i][1] <= w) mem[i][1] = small(mem[i][1], mem[i - 1][1] + 1); //����, ��ĭ
    }
    
    //�ᱣ��, ó���� ä������ ���� �κ��� ���� ������ ���� ������� ������ ���� ���Ѵ�.
    if (s == 0) return mem[n][1];
    else if (s == 1) return mem[n][2] + 1;
    else if (s == 2) return mem[n][0] + 1;
    else return mem[n - 1][1] + 2;
}

int main(void) {
    int t, n, w, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &w);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &wontagon[i][0]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &wontagon[i][1]);
        }

        if (n == 1) {
            if (wontagon[1][0] + wontagon[1][1] <= w) printf("1\n");
            else printf("2\n");
            continue;
        }

        r = dp(n, w, 0);
        if (wontagon[1][0] + wontagon[n][0] <= w) r = small(r, dp(n, w, 1));
        if (wontagon[1][1] + wontagon[n][1] <= w) {
            r = small(r, dp(n, w, 2));
            if (wontagon[1][0] + wontagon[n][0] <= w) r = small(r, dp(n, w, 3));
        }
        printf("%d\n", r);
    }
    return 0;
}