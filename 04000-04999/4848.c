#include <stdio.h>
#include <string.h>

/*
���� : ���� ǥ������� ��Ÿ�� �� �ڿ���(�Ǵ� 0)�� �־��� ��, �� ���� ���� ���� ǥ������� ��Ÿ����.
�� ���� ���� �ִ� 15�̴�.
���� ǥ����� 0�� {}�� ��Ÿ���� 1 �̻��� ���� �ش� �� �̸��� ��� ���� ���� �������� ��Ÿ���� ���̴�.
���� ��� 1�� {{}}�� ��Ÿ����, 2�� {{},{{}}}�� ��Ÿ����.

�ذ� ��� : 15 ������ ���� ǥ������� ��Ÿ�� ������ �̸� ���� �����صд�.
�̴� ���ڿ� ������ ���� DP�� ����� ������� �� �� �ִ�. �� ����, �� ������ ���̵� �̸� �����صд�.
���ķ� ������ �Է¹��� ����, �� ���� ���̸� ���ϰ� �ش� ���̿� ���� �� ���� Ȯ���Ѵ�.
��� ���� ���̰� �ٸ��� ������ �� ����� ��� �����ϴ�. �� ���� Ȯ���ϸ� �� ���� �տ� �ش��ϴ� ���� ǥ��� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : Rocky 2007 I��
*/

char nums[16][103000], a[103000], b[103000];
int len[16];

int main(void) {
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2007\\addition\\cases\\test1\\addition.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2007\\addition\\cases\\test1\\addition_t.out", "w", stdout);
    strcpy(nums[0], "{}");
    for (int i = 1; i <= 15; i++) {
        nums[i][0] = '{';
        for (int j = 0; j < i; j++) {
            strcat(nums[i], nums[j]);
            if (j < i - 1) strcat(nums[i], ",");
        }
        strcat(nums[i], "}");
    }
    for (int i = 0; i <= 15; i++) len[i] = strlen(nums[i]);
    int n, an, bn, al, bl;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s", a, b);
        an = -1, bn = -1;
        al = strlen(a), bl = strlen(b);
        for (int j = 0; j <= 15; j++) {
            if (al == len[j]) an = j;
            if (bl == len[j]) bn = j;
        }
        if (an < 0 || bn < 0) return 1;
        printf("%s\n", nums[an + bn]);
    }
    return 0;
}