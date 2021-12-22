#include <stdio.h>
#include <string.h>

/*
���� : ���� 100 ������ 'N', 'E', 'S', 'W'�� �̷���� ���ڿ��� �־�����. �� �������� ������ ���� ��ġ�� ���ƿ� ��ΰ�
�־��� ��, �� ��δ� �ð�������� ������ ������ �ݽð�������� ������ ������ ���Ѵ�. 180�� ȸ���ϴ� ���� �־����� �ʴ´�.

�ذ� ��� : ������ �������� ȸ���� Ƚ���� ���� �������� ȸ���� Ƚ���� ���� ���Ѵ�. ���������� ȸ���� �͵� �����ؾ� �Ѵ�.
�ð�������� �������ٸ� ��ȸ���� ��ȸ������ 4ȸ ���� ���̰�, �ݽð�������� �������ٸ� ��ȸ���� ��ȸ������ 4ȸ ���� ���̴�.
���� �̸� �̿��ϸ� ���� ���� ���� �� �ִ�.

�ֿ� �˰����� : ������, �ֵ� Ȥ

��ó : USACO 2021F B3��
*/

char s[128];

int main(void) {
    int n, c, w, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        c = 0, w = 0, l = strlen(s);
        for (int j = 0; s[j + 1]; j++) {
            if ((s[j] == 'N' && s[j + 1] == 'E') || (s[j] == 'E' && s[j + 1] == 'S') || (s[j] == 'S' && s[j + 1] == 'W') || (s[j] == 'W' && s[j + 1] == 'N')) c++;
            else if ((s[j] == 'N' && s[j + 1] == 'W') || (s[j] == 'W' && s[j + 1] == 'S') || (s[j] == 'S' && s[j + 1] == 'E') || (s[j] == 'E' && s[j + 1] == 'N')) w++;
        }
        if ((s[l - 1] == 'N' && s[0] == 'E') || (s[l - 1] == 'E' && s[0] == 'S') || (s[l - 1] == 'S' && s[0] == 'W') || (s[l - 1] == 'W' && s[0] == 'N')) c++;
        else if ((s[l - 1] == 'N' && s[0] == 'W') || (s[l - 1] == 'W' && s[0] == 'S') || (s[l - 1] == 'S' && s[0] == 'E') || (s[l - 1] == 'E' && s[0] == 'N')) w++;

        if (c - w == 4) printf("CW\n");
        else if (c - w == -4) printf("CCW\n");
        else return 1;
    }
    return 0;
}