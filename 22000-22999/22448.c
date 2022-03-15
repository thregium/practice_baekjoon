#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF (1LL << 63)

/*
���� : �־��� ���� 200 ������ ���Ŀ��� �������� �켱������ �ٲ� �� �ִٸ�
���� ����� ������ �ִ��� ���Ѵ�. ���� �߰��� � ������ �ϴ���
long long ���� �ȿ� ������ �־�����. ������ �����ڴ� '+', '-', '*' 3������ ���ѵȴ�.

�ذ� ��� : �켱������ ���� ��� ��츦 �õ��غ��鼭 ������ ���� ����Ͽ� ���� ���� ���� ã���� �ȴ�.
������ ���� ��ȣ ������ ��������� �� ���� Ȯ���ϰ�, ��ȣ ���� ������ �����ڰ� ���ٸ�
strtoll()�� �Ľ��ϰ�, �ִ� ��쿡�� �켱������ ���� �ͺ��� ���ʷ� ����س�����.
������ ����� �����ϹǷ� �����Ѵ�.

�ֿ� �˰��� : ����, �Ľ�, ���Ʈ ����

��ó : JAG 2013S3 G��
*/

char s[256];
int prio[3]; //+, -, *, higher first

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long solve(int st, int ed) {
    long long num[128], nnm[128];
    int inst[128], nnst[128];
    int ncnt = 0, icnt = 0, nnct = 0, nict = 0, lst = st, par = 0, noop = 1;
    long long tmp;
    for (int i = st; i <= ed; i++) {
        if (s[i] == '(') par++;
        else if (s[i] == ')') par--;
        else if (par == 0 && (s[i] == '+' || s[i] == '-' || s[i] == '*')) noop = 0;
    }
    if (noop && s[st] == '(') {
        lst++, st++, ed--, par = 0;
    }
    for (int i = st; i <= ed; i++) {
        if (par == 0 && (s[i] == '+' || s[i] == '-' || s[i] == '*')) {
            if (s[i] == '+') inst[icnt++] = 0;
            else if (s[i] == '-') inst[icnt++] = 1;
            else if (s[i] == '*') inst[icnt++] = 2;
            num[ncnt++] = solve(lst, i - 1);
            lst = i + 1;
        }
        else if (s[i] == '(') par++;
        else if (s[i] == ')') par--;
    }
    if (icnt == 0) return strtoll(&s[st], NULL, 10);
    else num[ncnt++] = solve(lst, ed);

    for (int i = 2; i >= 0; i--) {
        nnct = 0, nict = 0;
        tmp = num[0];
        for (int j = 0; j < icnt; j++) {
            if (prio[inst[j]] == i) {
                if (inst[j] == 0) tmp += num[j + 1];
                else if (inst[j] == 1) tmp -= num[j + 1];
                else tmp *= num[j + 1];
            }
            else {
                nnst[nict++] = inst[j];
                nnm[nnct++] = tmp;
                tmp = num[j + 1];
            }
        }
        nnm[nnct++] = tmp;
        for (int j = 0; j < nnct; j++) num[j] = nnm[j];
        for (int j = 0; j < nict; j++) inst[j] = nnst[j];
        icnt = nict, ncnt = nnct;
    }
    return num[0];
}

int main(void) {
    long long best = INF;
    scanf("%s", s);
    for (int i = 0; i < 3; i++) {
        prio[0] = i;
        for (int j = 0; j < 3; j++) {
            prio[1] = j;
            for (int k = 0; k < 3; k++) {
                prio[2] = k;
                best = big(best, solve(0, strlen(s) - 1));
            }
        }
    }
    printf("%lld\n", best);
    return 0;
}