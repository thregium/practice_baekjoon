#include <stdio.h>
#include <string.h>

/*
���� : 200�� ������ ���ڿ� 2���� �� ���ڿ� ������ �հ� ���� ������ ���ڿ��� �־�����.
�̶�, �� ���ڿ��� ������ �ٲ��� �ʰ� ��� �� ��° ���ڿ��� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �ذ��Ѵ�. �� ��° ���ڿ��� ������� Ȯ���ϸ� ù ��° ���ڿ��� �� ��° ���ڿ�����
���������� �� ��ġ���� �߰� ���������� �Ź� Ȯ���غ���. ������ ���ڱ��� �����ϴٸ� ���� �� �ִ� ���̰�,
�Ұ����ϴٸ� ���� �� ���� ���̴�.

�ֿ� �˰��� : DP

��ó : PacNW 2004 B��
*/

char s1[256], s2[256], s3[512];
int mem[256][256];

int main(void) {
    int t, l1, l2;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\b.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\b_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s %s %s", s1, s2, s3);
        l1 = strlen(s1), l2 = strlen(s2);
        mem[0][0] = 1;
        for (int i = 1; i <= l1 + l2; i++) {
            for (int j = 0; j <= l2; j++) {
                if (i - j > l1) continue;
                if (i - j < 0) break;
                if (i - j > 0 && mem[i - j - 1][j] && s1[i - j - 1] == s3[i - 1]) mem[i - j][j] = 1;
                else if (j > 0 && mem[i - j][j - 1] && s2[j - 1] == s3[i - 1]) mem[i - j][j] = 1;
                else mem[i - j][j] = 0;
            }
        }
        printf("Data set %d: %s\n", tt, mem[l1][l2] ? "yes" : "no");
    }
    return 0;
}