#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
���� : RLE ���·� �̷���� �� ���ڿ��� �־�����. ù ���ڿ����� �� ��° ���ڿ��� �ִ� ù ��ġ�� ã��
�� ���ڿ��� �� ��° ���ڿ��� �ٲ� �� RLE ���·� ����Ѵ�.
�׷��� ���ڿ��� ���� ���� �״�� ����Ѵ�.
�� ���ڿ��� ������ ���� ���� �ִ� 10^8���̰�, ���� ����� ���� �ִ� 1000���̴�.

�ذ� ��� : �켱 �Ľ��� ���� RLE�� ������ ���� �����ش�. �׷� ����, ���ڿ��� ã�� ������.

ù ���ڿ����� �� ��° ���ڿ��� ã�� ����� ������ ����.
�� ��° ���ڿ��� ��� ���� 1�� ��쿡�� �ش� ����� ���� ���ڸ� ���̰� �� �̻��� �����
ã�Ƽ� �� ����� ù �κ��� �ٲ۴�.
2 �̻��̶�� ���۰� ������ ��� ���� ���ڸ� ���̰� �� �̻�, �� �� ������ ���� ���ڿ� ���̵�
���� ����� ������ ã�ƾ� �Ѵ�. ������ ����� ���� �����Ƿ� �ܼ� ���Ʈ ������ ����� �� �ִ�.

���ڿ��� ã�� �������� ���ڿ��� ������ �ٲ㳪���� �Ѵ�. �켱 �� ��° ���ڿ��� ��ġ�� �ʴ� �κ���
�״�� ��������. �׸��� ���۰� ������ ���̸� Ȯ���� �� ���̸�ŭ�� �� ���ڿ��� �ִ´�.
�߰� ������ �� ��° ���ڿ��� ������ �״�� �� ���ڿ��� �ִ´�.

�׸��� �� �������� ���� ���� 0 �Ǵ� ������ ���� ������� �����ϴ� �۾��� �Ѵ�.
�̴� �迭 2���� ����ϸ� �����ϴ�. �� ������ ������ RLE �������� ���ڿ��� ����� ������ �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����, ���̽� ��ũ, ���Ʈ ���� ��

��ó : JAG 2014SC H��
*/

char a[16384], b[16384], c[16384], ac[1024], bc[1024], cc[1024], tc[2048], rc[2048];
long long ai[1024], bi[1024], ci[1024], ti[2048], ri[2048];
int acnt, bcnt, ccnt, rcnt;

void parse(char* text, char* carr, long long* iarr, int* cnt) {
    *cnt = 0;
    for (int i = 0; text[i] != '$'; i++) {
        if (isupper(text[i])) {
            carr[*cnt] = text[i];
            iarr[(*cnt)++] = strtoll(&text[i + 2], NULL, 10);
        }
    }
}

void replace(int pos, int posi) {
    int rp = 0;
    rcnt = 0;
    for (int i = 0; i < pos; i++) {
        tc[rp] = ac[i];
        ti[rp++] = ai[i];
    }
    tc[rp] = ac[pos];
    ti[rp++] = posi;
    for (int i = 0; i < ccnt; i++) {
        tc[rp] = cc[i];
        ti[rp++] = ci[i];
    }
    tc[rp] = ac[pos + bcnt - 1];
    ti[rp++] = ai[pos + bcnt - 1] - bi[bcnt - 1];
    for (int i = pos + bcnt; i < acnt; i++) {
        tc[rp] = ac[i];
        ti[rp++] = ai[i];
    }

    for (int i = 0; i < rp; i++) {
        if (ti[i] == 0) continue;
        if (i > 0 && tc[i] == rc[rcnt - 1]) ri[rcnt - 1] += ti[i];
        else {
            rc[rcnt] = tc[i];
            ri[rcnt++] = ti[i];
        }
    }
}

int main(void) {
    int t;
    fgets(a, 16000, stdin);
    fgets(b, 16000, stdin);
    fgets(c, 16000, stdin);
    parse(a, ac, ai, &acnt);
    parse(b, bc, bi, &bcnt);
    parse(c, cc, ci, &ccnt);

    rcnt = acnt;
    for (int i = 0; i < acnt; i++) {
        rc[i] = ac[i];
        ri[i] = ai[i];
    }

    if (bcnt == 1) {
        for (int i = 0; i < acnt; i++) {
            if (ac[i] == bc[0] && ai[i] >= bi[0]) {
                replace(i, 0);
                break;
            }
        }
    }
    else {
        for (int i = 0; i <= acnt - bcnt; i++) {
            t = 1;
            if (ac[i] != bc[0] || ai[i] < bi[0]) t = 0;
            for (int j = 1; j < bcnt - 1; j++) {
                if (ac[i + j] != bc[j] || ai[i + j] != bi[j]) t = 0;
            }
            if (ac[i + bcnt - 1] != bc[bcnt - 1] || ai[i + bcnt - 1] < bi[bcnt - 1]) t = 0;
            if (t) {
                replace(i, ai[i] - bi[0]);
                break;
            }
        }
    }

    for (int i = 0; i < rcnt; i++) {
        printf("%c %lld ", rc[i], ri[i]);
    }
    printf("$\n");
    return 0;
}