/*
 * 做作业的时候，邻座的小盆友问你：“五乘以七等于多少？”你应该不失礼貌地围笑着告诉他：“五十三。”本题就要求你，对任何一对给定的正整数，倒着输出它们的乘积。

53.jpg

输入格式：
输入在第一行给出两个不超过 1000 的正整数 A 和 B，其间以空格分隔。

输出格式：
在一行中倒着输出 A 和 B 的乘积。

输入样例：
5 7
输出样例：
53
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int m = a * b, sum = 0, d[100], i;
    for (i = 0; m != 0; ++i) {
        d[i] = m % 10;
        m /= 10;
    }
    for (int j = i; j >= 0; --j) {
        sum += d[i - j] * pow(10, j - 1);
    }
    cout << sum;
}