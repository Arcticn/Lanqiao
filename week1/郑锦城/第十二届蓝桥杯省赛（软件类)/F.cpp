#include<iostream>
#include<cmath>
using namespace std;
static int b[10000];
bool judge(int m,int mm)
{
    for(int *p=b;p<b+mm;p++)
    {
        if(m==*p)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int b_num1=0;
    int b_num2;
    for(int i=0;i<n;i++)//拿到一个新的数
    {
        b_num2=b_num1;
         if(judge(a[i],b_num2))//判断这个数存不存在
         {
             b[b_num1++]=a[i];
         }
        for(int j=0;j<b_num2;j++)//判断这个数与其他数的组合存在吗，+
        {
            if(judge(a[i]+b[j],b_num2))
            {
                b[b_num1++]=a[i]+b[j];
            }
            if(judge(abs(a[i]-b[j]),b_num2))
               {
                   b[b_num1++]=a[i]+b[j];
               }
        }
    }
    cout<<b_num1;

    return 0;
}
