/*
 * 输入两个非负 10 进制整数 A 和 B (≤2
​30
​​ −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
 */

#include<iostream>

using namespace std;

int main() {
    int a, b, d, digit[31] = {0};
    cin >> a >> b >> d;
    int sum = a + b, i;
    for (i = 0; sum / d; ++i) {
        digit[i] = sum % d;
        sum /= d;
    }
    digit[i] = sum;
    while (i >= 0) {
        cout << digit[i--];
    }
}
