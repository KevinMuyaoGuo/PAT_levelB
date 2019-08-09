/*
 * 一个分数一般写成两个整数相除的形式：N/M，其中 M 不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N
​1
​​ /M
​1
​​  和 N
​2
​​ /M
​2
​​ ，要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

输入格式：
输入在一行中按 N/M 的格式给出两个正分数，随后是一个正整数分母 K，其间以空格分隔。题目保证给出的所有整数都不超过 1000。

输出格式：
在一行中按 N/M 的格式列出两个给定分数之间分母为 K 的所有最简分数，按从小到大的顺序，其间以 1 个空格分隔。行首尾不得有多余空格。题目保证至少有 1 个输出。

输入样例：
7/18 13/20 12
输出样例：
5/12 7/12
 */

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {//最大公约数
    int l;
    while (b != 0) {
        l = a % b;
        a = b;
        b = l;
    }
    return a;
}

int main() {
    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
    double d1, d2;
    d1 = (double)k*n1 / m1;
    d2 = (double)k*n2 / m2;
    if (d1 > d2) {
        swap(d1, d2);
    }

    vector<int> v;
    for (int i = 1; i < k; ++i) {
        if (gcd(i, k) == 1 && 1.0 * i > d1 && 1.0 * i < d2) {
            v.emplace_back(i);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << "/" << k;
        if(i!=v.size()-1){
            cout << " ";
        }
    }

}
