#include <stdio.h>

/*
���� : �� ���� �� ������ ������������ �ߴ�. �� ���� ���� ��, �ٸ� ����� ���� �Ϳ� ��� ����
������ �̱�� ����� �ִ� ����� �ִ���, �ִٸ� �������� ���Ѵ�.

�ذ� ��� : �� ����� ���� �޼����� ������ ��, ��밡 ���� �Ϳ� ��� ���� �̱����, �Ǵ� �������� ������ ��
�̱������ Ȯ���Ѵ�. �׷��� ���� ������ �̱�� ���̰�, �׷��� ����� ������ �� ����� ����ϸ� �ȴ�.

�ֿ� �˰����� : ���Ʈ ����, ���̽� ��ũ

��ó : ������ 2018B C��
*/

int rps(char a, char b) {
    //�� ����� ���������� ����� ����Ѵ�.
    if (a == b) return 0;
    if ((a == 'R' && b == 'P') || (a == 'P' && b == 'S') || (a == 'S' && b == 'R')) return -1;
    return 1;
}

int main(void) {
    char ml, mr, tl, tr, m = 0, t = 0;
    scanf("%c %c %c %c", &ml, &mr, &tl, &tr);
    if ((rps(ml, tl) + rps(ml, tr) == 2) || (rps(mr, tl) + rps(mr, tr) == 2)) m = 1;
    if ((rps(ml, tl) + rps(mr, tl) == -2) || (rps(ml, tr) + rps(mr, tr) == -2)) t = 1;
    if (m && !t) printf("MS");
    else if (t && !m) printf("TK");
    else printf("?");
    return 0;
}