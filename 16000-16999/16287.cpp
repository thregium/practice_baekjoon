#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <random>
using namespace std;

/*
���� : N(N <= 5000)���� ������ �ִ�. �� ������ ���Դ� 200000 ������ �ڿ����̸�, ��� ������ ���Դ� �ٸ���.
�̶�, 4���� ���� �ٸ� ������ ���� ���� W(10 <= W <= 799994)�� �Ǵ� ��찡 �ִ� �� ���Ѵ�.

�ذ� ��� : ������ �������ϰ� ���� �� ���� ���� �� 2���� ���� �Ͱ�,
���� ���� �� 2���� ���� ���� ���� ������ �迭�� �����Ѵ�. �� �� �� �迭�� ��ȸ�ϸ鼭
���� W�� �Ǵ� ��찡 �ִ� �� Ȯ���Ѵ�. �̷��� �տ��� 2���� �̰� �ڿ��� 2���� �̴� ��찡 ������ ����
37.5%�� �ȴ�. �����(30ȸ �̻�) �ݺ��ϸ� �ſ� ���� Ȯ��(99.9999% �̻�)�� ������ ã�� �� �ִ�.
�ݺ� Ƚ���� �߿��ϹǷ� ��� ���� ����ȭ�� �̷������ �ϸ� ���� �Լ��� �� Ȯ���ؾ� �Ѵ�.

�ֿ� �˰��� : �� �� �� �̵�, ������ȭ

��ó : Seoul 2018I F��
*/

int a[5120];
char memlo[103000 * 4], memhi[103000 * 4];

int main(void) {
    int w, n, r = 0;
    scanf("%d %d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        //a[i] = i + 1;
    }
    for (int randi = 0; randi < 39; randi++) {
        shuffle(a, a + n, std::default_random_engine(clock() * 401 + randi * 31));
        for (int i = 0; i < (n >> 1); i++) {
            for (int j = i + 1; j < (n >> 1); j++) {
                memlo[a[i] + a[j]] = 1;
            }
        }
        for (int i = n >> 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                memhi[a[i] + a[j]] = 1;
            }
        }
        for (int i = 2; i <= w && i <= 400000; i++) {
            if (w - i > 400000) continue;
            if (memlo[i] && memhi[w - i]) r = 1;
        }
        memset(memlo, 0, sizeof(memlo));
        memset(memhi, 0, sizeof(memhi));
    }
    printf("%s", r ? "YES" : "NO");
    return 0;
}