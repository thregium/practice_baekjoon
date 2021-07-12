#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

/*
���� : ������ ���������� �̷����, ��ȣ�� ������ ���� �־�����. �̶� �� ���� ����� ���Ѵ�. ���� �ִ� 300000����
���� ��ȣ�� �̷���� �ְ�, ��ȣ�� �ٱ��� ���� �����̴�.

�ذ� ��� : Ȧ����° ��ȣ ������ ���� �����̰�, ¦����°(0 ����) ��ȣ ������ ���� �����̴�. ���� �� ��ȣ �ܰ��� ���� �����
���ÿ� ������ �� ��ȣ�� ������ �� �ܰ��� ����� ������ �����ϸ� �ȴ�. �̶� Ȧ�� ��°�� ������ 1�� �ʱ�ȭ�ϰ� ¦�� ��°��
������ 0���� �ʱ�ȭ�� �ξ�� ���� �ٽ� ��ȣ�� ���� �� ������ ����� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ����, ����, �Ľ�

��ó : BAPC 2019P B��
*/

int tokens[327680], stack[327680];
char buff[16];

int main(void) {
    int n, lv = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (buff[0] == '(') tokens[i] = -1;
        else if (buff[0] == ')') tokens[i] = -2;
        else tokens[i] = strtoll(buff, NULL, 10);
        if (i & 1) stack[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (tokens[i] == -1) lv++;
        else if (tokens[i] == -2) {
            lv--;
            if (lv & 1) stack[lv] = ((long long)stack[lv] * stack[lv + 1]) % MOD;
            else stack[lv] = (stack[lv] + stack[lv + 1]) % MOD;

            if (lv & 1) stack[lv + 1] = 0;
            else stack[lv + 1] = 1;
        }
        else {
            if (lv & 1) stack[lv] = ((long long)stack[lv] * tokens[i]) % MOD;
            else stack[lv] = (stack[lv] + tokens[i]) % MOD;
        }
    }
    printf("%d", stack[0]);
    return 0;
}