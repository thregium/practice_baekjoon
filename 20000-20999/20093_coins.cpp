#include "20093_coins.h"

/*
���� : 0�� 1�� ������ 64���� ĭ�� �� �� ĭ�� ���¸� �������� Ư���� ĭ C�� ã�´�.

�ذ� ��� : ��� ĭ�� �� ��Ʈ ���°� 1�� ĭ�� ������ ���� XOR�Ѵ�. �� �������� C�� XOR�ϰ� ���� ����� ĭ�� �����´�.
�׷��� ��Ʈ ���°� 1�� ������ XOR�� ����� C�� �ȴ�.

�ֿ� �˰��� : ����, ��Ʈ����ŷ

��ó : IOI 2017 P3��
*/

std::vector<int> coin_flips(std::vector<int> b, int c) {
    std::vector<int> flips(1);
    int xors = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) xors ^= i;
    }
    xors ^= c;
    flips[0] = xors;
    return flips;
}

int find_coin(std::vector<int> b) {
    int xors = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) xors ^= i;
    }
    return xors;
}
