#include<bits/stdc++.h>
using namespace std;

map<string,int>result; //创建一个以字符串值为主键的map
map<string,int>::iterator iter; //声明一个迭代器

int main(){
    int Len,i,Result_number;
    cin >> Len; //读取长度
    string t,Temp,Result_string;
    cin >> t; //读取字符串
    for (i=0;i<=t.length()-Len;i++)
    {
      Temp=t.substr(i,Len); //截取字符串
      result[Temp]++; //在map中主键为截取到的字符串的迭代器的int值+1
    }
    iter=result.begin(); //返回指向map头部的迭代器
    Result_number = iter->second; //将头部迭代器的int值赋给 Result_number 变量
    Result_string = iter->first; //将头部迭代器的string值赋给 Result_string 变量
    while(iter != result.end())
    {
      if (iter->second > Result_number) //当前迭代器中的 int 值大于 Result_number 变量的值时
      {
        Result_number = iter ->second; //将当前迭代器的int值赋给 Result_number 变量
        Result_string = iter->first; //将当前迭代器的string值赋给 Result_string 变量
      }
      iter++;
    }
    cout << Result_string << ' ' << Result_number << endl; //输出
    return 0;
}