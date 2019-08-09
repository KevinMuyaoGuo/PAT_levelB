/**
 * 如果某个数 K 的平方乘以 N 以后，结果的末尾几位数等于 K，那么就称这个数为“N-自守数”。例如 3×92
​2
​​ =25392，而 25392 的末尾两位正好是 92，所以 92 是一个 3-自守数。

本题就请你编写程序判断一个给定的数字是否关于某个 N 是 N-自守数。

输入格式：
输入在第一行中给出正整数 M（≤20），随后一行给出 M 个待检测的、不超过 1000 的正整数。

输出格式：
对每个需要检测的数字，如果它是 N-自守数就在一行中输出最小的 N 和 NK
​2
​​  的值，以一个空格隔开；否则输出 No。注意题目保证 N<10。

输入样例：
3
92 5 233
输出样例：
3 25392
1 25
No
 */

#include <iostream>

using namespace std;

int len(int n){
    int len=1;
    while (n){
        len*=10;
        n/=10;
    }
    return len;
}

int main() {
    int m;
    cin >> m;
    int a[m];
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    int l;
    bool flag;
    for (int j = 0; j < m; ++j) {
        l=len(a[j]);
        flag= false;
        for (int i = 1; i < 10; ++i) {
            if((i*a[j]*a[j]-a[j])%l==0){
                flag=true;
                cout<<i<<" "<<i*a[j]*a[j]<<endl;
                break;
            }
        }
        if (!flag) {
            cout << "No"<<endl;
        }
    }
    return 0;
}