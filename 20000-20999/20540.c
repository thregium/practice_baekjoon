#include <stdio.h>

/*
���� : MBTI ������ �־��� ��, �׿� �ݴ�Ǵ� ������ ã�´�.

�ذ� ��� : 4�ڸ��� ����� �ϵ��ڵ��Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : ���ϴ� 2020 A��
*/

char m[8];

int main(void) {
    scanf("%s", &m);
    if (m[0] == 'I') printf("E");
    else printf("I");
    if (m[1] == 'N') printf("S");
    else printf("N");
    if (m[2] == 'F') printf("T");
    else printf("F");
    if (m[3] == 'P') printf("J");
    else printf("P");
    return 0;
}