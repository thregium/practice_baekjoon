#include <stdio.h>
#include <string.h>

/*
���� : �������� P�� ���� ������ �ٱ� �������� ���� A, B�̰� ���� �������� ���� a, b�� ���� �ڸ� �� �ִ��� ���Ѵ�.

�ذ� ��� : ���� �ڸ��� ���� �� ���� �ٸ� �� ���ʿ� ���ų� �� ���� ���� ���������� �ִ� ���� ������.
���� ù ��° ����, ū ���� ���� �������� ���� ���� �ٱ� ���������� ũ�ų� ���ƾ� �ϰ�,
ū ���� �ٱ� �������� ���� ���������ٴ� �۾ƾ� �Ѵ�.
�� ��° ���� �� ���� �������� ���� ���� �������� �� ���Ͽ��� �Ѵ�.

�ֿ� �˰��� : ������

��ó : NWRRC 2006 H��
*/

char dir[128] = "E:\\PS\\ICPC\\Northern Eurasia\\North&West\\2006\\tests\\halloween\\tests\\";
char buff[32];

int main(void) {
    int ao, ai, bo, bi, p;
    /*
    for (int i = 1; i <= 56; i++) {
        dir[66] = i / 10 + '0';
        dir[67] = i % 10 + '0';
        dir[68] = '\0';
        freopen(dir, "r", stdin);
        */
        scanf("%d %d %d %d %d", &ao, &ai, &bo, &bi, &p);
        if (ao <= bi && bo <= p) printf("Yes");
        else if (ai >= bo && ao <= p) printf("Yes");
        else if (ao + bo <= p) printf("Yes");
        else printf("No");
        /*
        dir[68] = '.';
        dir[69] = 'a';
        freopen(dir, "r", stdin);
        scanf("%s", buff);
        printf(" : %s\n", buff);
    }
    */
    return 0;
}