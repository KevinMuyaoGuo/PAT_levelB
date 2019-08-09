/*
 * 本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

输入格式：
输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

输出格式：
在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118
 */

#include <iostream>

using namespace std;

int odd_or_even(int n) {//奇数为1，偶数为0
    if (n % 2) {
        return 1;
    }
    return 0;
}

void encrypt(char a, char b, int i) {
    if (odd_or_even(i)) {
        int r = ((a - '0') + (b - '0')) % 13;
        if (r == 10) {
            cout << "J";
        } else if (r == 11) {
            cout << "Q";
        } else if (r == 12) {
            cout << "K";
        } else {
            cout << r;
        }
    } else {
        int r = (b - '0') - (a - '0');
        if (r < 0) {
            r += 10;
        }
        cout << r;
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    int al = a.length(), bl = b.length();
    if (al < bl) {
        for (int i = 0; i < bl - al; ++i) {
            a = "0" + a;
        }
    } else if (al > bl) {
        for (int i = 0; i < al - bl; ++i) {
            b = "0" + b;
        }
    }

    int len = a.length();
    int index=0;
    if (odd_or_even(len)) {
        index++;
    }
    for (int i = 0; i < len; ++i) {
        encrypt(a[i],b[i],index);
        index++;
    }
}
