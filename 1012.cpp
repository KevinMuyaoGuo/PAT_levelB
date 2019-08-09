/**
 * 给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

A
​1
​​  = 能被 5 整除的数字中所有偶数的和；
A
​2
​​  = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n
​1
​​ −n
​2
​​ +n
​3
​​ −n
​4
​​ ⋯；
A
​3
​​  = 被 5 除后余 2 的数字的个数；
A
​4
​​  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A
​5
​​  = 被 5 除后余 4 的数字中最大数字。
输入格式：
每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：
对给定的 N 个正整数，按题目要求计算 A
​1
​​ ~A
​5
​​  并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出 N。

输入样例 1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例 1：
30 11 2 9.7 9
输入样例 2：
8 1 2 4 5 6 7 9 16
输出样例 2：
N 11 2 N 9
 */

#include<iostream>

using namespace std;

int IsEven(int n){
    if(n%2==0){
        return n;
    } else{
        return 0;
    }
}



int main() {
    int a1=0,a2=0,a3=0,a5=0,n;
    bool f1= false,f2= false,f3= false,f4= false,f5= false;
    float a4=0.0;
    cin>>n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int m,k;
    int count3 = 0, count1 = 0;
    int max = nums[0];
    for (int j = 0; j < n; ++j) {
        m=nums[j]%5;
        switch (m){
            case 0:{
                if(nums[j]%2==0){
                    f1=true;
                    a1+=nums[j];
                }
                break;
            }
            case 1:{
                f2=true;
                count1++;
                if(count1%2==1){
                    k=1;
                } else{
                    k=-1;
                }
                a2 += k * nums[j];
                break;
            }
            case 2:{
                f3=true;
                a3++;
                break;
            }
            case 3:{
                f4=true;
                a4+=nums[j];
                count3++;
                break;
            }
            case 4:{
                f5=true;
                if(nums[j]>max){
                    max = nums[j];
                    break;
                }
            }
        }
    }

    a4=a4/count3;
    a5=max;

    if(f1){
        cout<<a1;
    } else{
        cout<<"N";
    }
    cout<<" ";
    if(f2){
        cout<<a2;
    } else{
        cout<<"N";
    }
    cout<<" ";
    if(f3){
        cout<<a3;
    } else{
        cout<<"N";
    }
    cout<<" ";
    if(f4){
        printf("%.1f",a4);
    } else{
        cout<<"N";
    }
    cout<<" ";
    if(f5){
        cout<<a5;
    } else{
        cout<<"N";
    }
    return 0;
}