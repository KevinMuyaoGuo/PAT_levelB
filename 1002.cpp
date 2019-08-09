/**
 * 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100
​​ 。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
 */

#include <iostream>

using namespace std;

void int_pinyin(int n){
    switch(n){
        case 0:  cout<<"ling";   break;
        case 1:  cout<<"yi";   break;
        case 2:  cout<<"er";   break;
        case 3:  cout<<"san";   break;
        case 4:  cout<<"si";   break;
        case 5:  cout<<"wu";   break;
        case 6:  cout<<"liu";   break;
        case 7:  cout<<"qi";   break;
        case 8:  cout<<"ba";   break;
        case 9:  cout<<"jiu";   break;
    }
}

int main() {
    char s[101];
    cin>>s;
    int i=0,sum=0;
    while(s[i]!='\0'){
        sum+=s[i]-'0';
        i++;
    }

    int j=0,b[11];
    while(sum!=0){
        b[j]=sum%10;
        sum/=10;
        j++;
    }

    for (int k = j-1; k >0; --k) {
        int_pinyin(b[k]);
        cout << " ";
    }

    int_pinyin(b[0]);

    return 0;
}