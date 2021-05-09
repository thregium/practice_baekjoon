#include <stdio.h>

/*
���� : ���� N(N <= 10000)�� 1, 2, 3, ..., N���� �� �������� �� ������ ������� ��������.
�� ������ �ٽ� �ι� ������ 1, 2, 3, ..., N���� ����� �� ������ ����Ѵ�.

�ذ� ��� : ù ��°�� ������ �� �� �ִ� �ĺ� ������ ����� ���� �Ǵ� �����ϴ� ������ ���� �پ��� �������̴�.
�׷��� �������� ���� �Ǵ� �����ϴ� ������ �� ���� �ִ�. �׸���, 2��¥�� ���� �Ǵ� �����ϴ� ������ ���
2���� ������ �ݴ����� �쿬�� ������ ���� �� �����Ƿ� �� �� �ĺ� ������ �� ���� ���� �Ѵ�.
�̷��� �ĺ� �������� ���� �����ϱ� ���ؼ��� �������� ���� ��� ���ƾ� 10�����̹Ƿ� ��� �ѹ��� ���캸���� �ð� �ʰ��� ���� �ʴ´�.
�ϴ� �ѹ��� ���� ������ ���� ���� ������ ���� ���� �ٽ� �������� ���� ������ ���������� Ȯ���Ѵ�.
���� ������ 3���� �Ѵ� ��� ��� �ϴ��� �Ұ����ϴ�. 1���� ��� �����̶�� ��ü ������ ������, �����̶�� ��ĭ�� �������� ���� ������ ���� �� �ִ�.
2���� ��� ������ �κ��� ������ ���� ���� ������ �Ǵ��� Ȯ���Ѵ�. 3���� ��쿡�� ��-��-���� ������ ���� �����ϰ�,
���� ������ �κ��� ������ ���� ���� ������ �Ǵ��� Ȯ���� ���� �ȴ�. ���� ������ ��������� ��� Ž���� ��� �����Ѵ�.

�ֿ� �˰����� : �ֵ� Ȥ, ���Ʈ ����, ���̽� ��ũ, ����

��ó : ���� 2008�� ��5/��3
*/

int a[10240][3], st[128], ed[128], mv[2][2];
int n, sp = 0, ep = 0, flag = 0;

void swap(int ss, int ee, int p) {
    //ss - ee ������ �����´�. p�� ������ Ƚ���̴�.
    for (int i = 1; i <= n; i++) {
        a[i][p] = a[i][p - 1];
    }
    for (int s = ss, e = ee; s < e; s++, e--) {
        a[e][p] = a[s][p - 1];
        a[s][p] = a[e][p - 1];
    }
}

void check(void) {
    int t = 1, sign = 0, len = 1, range[4][3]; //range : �� ������ ������ �����Ѵ�.(������, ����, ��ȣ)
    range[1][0] = 1;
    range[1][2] = 0;
    for (int i = 2; i <= n; i++) {
        if (len == 1) {
            len = 2;
            if (a[i][1] == a[i - 1][1] + 1) sign = 1;
            else if (a[i][1] == a[i - 1][1] - 1) sign = -1;
            else {
                range[t++][1] = i - 1;
                if (t > 3) return; //������ 3�� �̻��� ��� ���� ������ ���� �� ����.
                range[t][0] = i;
                range[t][2] = 0; //1ĭ¥�� ������ ��ȣ�� 0���� �Ѵ�.
                len = 1;
            }
            range[t][2] = sign;
        }
        else if (a[i][1] - a[i - 1][1] != sign) {
            t++;
            if (t > 3) return;
            range[t][0] = i;
            range[t][2] = 0;
            range[t - 1][1] = i - 1;
            len = 1;
        }
        else len++;
    }
    range[t][1] = n;
    if (t == 1) {
        flag = 1;
        if (range[1][2] > 0) {
            mv[1][0] = 1;
            mv[1][1] = 1;
        }
        else if (range[1][2] < 0) {
            mv[1][0] = 1;
            mv[1][1] = n;
        }
    }
    else if (t == 2) {
        if (range[1][2] >= 0 && range[2][2] <= 0) {
            swap(range[2][0], range[2][1], 2);
            for (int i = 1; i <= n; i++) {
                if (a[i][2] != i) return; //�������� ������ ������ ���� ����� �Ǿ����� Ȯ���Ѵ�.
            }
            mv[1][0] = range[2][0];
            mv[1][1] = range[2][1];
            flag = 1;
        }
        else if (range[1][2] <= 0 && range[2][2] >= 0) {
            swap(range[1][0], range[1][1], 2);
            for (int i = 1; i <= n; i++) {
                if (a[i][2] != i) return;
            }
            mv[1][0] = range[1][0];
            mv[1][1] = range[1][1];
            flag = 1;
        }
    }
    else {
        if (range[1][2] >= 0 && range[2][2] <= 0 && range[3][2] >= 0) {
            swap(range[2][0], range[2][1], 2);
            for (int i = 1; i <= n; i++) {
                if (a[i][2] != i) return;
            }
            flag = 1;
            mv[1][0] = range[2][0];
            mv[1][1] = range[2][1];
        }
    }
}

int main(void) {
    int sign = 0, len = 1; //sign : �ش� ������ ��ȣ, len : �ش� ������ ����
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][0]);
    }
    st[sp++] = 1;
    for (int i = 2; i <= n; i++) {
        if (len == 1) {
            //1ĭ�� ��� ��ȣ�� ���Ѵ�.
            len = 2;
            if (a[i][0] == a[i - 1][0] + 1) sign = 1;
            else if (a[i][0] == a[i - 1][0] - 1) sign = -1;
            else {
                //1ĭ¥�� ������ ���
                ed[ep++] = i - 1;
                st[sp++] = i;
                len = 1;
            }
        }
        else if (a[i][0] - a[i - 1][0] != sign) {
            //��ȣ�� ���� �ʴ� ���� ���� ���
            if (len == 2) {
                ed[ep++] = i - 2;
                st[sp++] = i - 1;
            }
            ed[ep++] = i - 1;
            st[sp++] = i;
            len = 1;
        }
        else len++;
    }
    if (len == 2) {
        ed[ep++] = n - 1;
        st[sp++] = n;
    }
    ed[ep++] = n;

    for (int i = 0; i < sp; i++) {
        for (int j = 0; j < ep; j++) {
            if (st[i] > ed[j]) continue;
            mv[0][0] = st[i];
            mv[0][1] = ed[j];
            swap(st[i], ed[j], 1);
            check();
            if (flag) break; //������ ���� ��� Ž�� ����
        }
        if (flag) break;
    }
    if (!flag) return 1;
    printf("%d %d\n%d %d", mv[0][0], mv[0][1], mv[1][0], mv[1][1]);

    return 0;
}