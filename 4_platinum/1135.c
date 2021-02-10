#include <stdio.h>
#include <stdlib.h>

/*
���� : Ʈ�� ���·� �� ȸ�簡 �ְ�, �� ������� �ڽ��� ���� ���Ͽ��Ը� ������ �� �ִٰ� �Ѵ�. �� ����� ��ȭ�� �ϴµ� 1�о� �ɸ���, ���ÿ� ��ȭ�� �� ���� ���ٰ� �� ��
������ ��� ����鿡�� ������ ���ϴµ� �ɸ��� �ð��� ���Ѵ�. ����� ���� 50�� �����̴�.

�ذ� ��� : Ʈ���� ������ȸ�ϸ� ���ܺ��� �ش� ����� ��� ���Ͽ��� ������ ���ϴµ� �ɸ��� �ð��� ���Ѵ�. �ָ��� ����� ��� ���ϰ� �����Ƿ� 0���̰�,
���ϰ� �ִ� ��쿡�� �ð��� ���� �ɸ��� ������� ������� ��ȭ�� �Ǵ�. �� �� �ڽ��� ��ȭ�� �Ŵµ� �ɸ� �ð��� �ش� ����� ���Ͽ��� ���ϴµ� �ɸ��� �ð��� ����
���� ū ���� �ڽ��� ���� �ð��� �ȴ�. �̸� �ݺ��Ͽ� ������� �����ϸ� ������ ���� �ð��� ����Ѵ�.
*/

int inf[64][64]; //������ ���
int tm[64]; //��� ���Ͽ��� ������ ���ϴµ� �ɸ��� �ð�

int big(int a, int b) {
     return a > b ? a : b;
}

int infcmp(const void* a, const void* b) {
     int ai = tm[*(int*)a];
     int bi = tm[*(int*)b];

     return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int makeinfs(int a) {
     int x = 0;
     for (int i = 1; i <= inf[a][0]; i++) {
          makeinfs(inf[a][i]);
     }
     if (inf[a][0] == 0) return tm[a] = 0;
     
     qsort(&inf[a][1], inf[a][0], sizeof(int), infcmp);
     for (int i = 1; i <= inf[a][0]; i++) {
          x = big(x, i + tm[inf[a][i]]);
     }
     return tm[a] = x;
}

int main(void) {
     int n, a;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a);
          if(a >= 0) inf[a][++inf[a][0]] = i;
     }
     printf("%d", makeinfs(0));
     return 0;
}