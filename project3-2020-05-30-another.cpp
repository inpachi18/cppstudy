#include<bits/stdc++.h>
using namespace std;

map<string,int>result;
map<string,int>::iterator iter;

int main(){
    int Len,i,Result_number;
    cin >> Len;
    string t,Temp,Result_string;
    cin >> t;
    for (i=0;i<=t.length()-Len;i++)
    {
      Temp=t.substr(i,Len);
      result[Temp]++;
    }
    iter=result.begin();
    Result_number = iter->second;
    Result_string = iter->first;
    while(iter != result.end())
    {
      if (iter->second > Result_number)
      {
        Result_number = iter ->second;
        Result_string = iter->first;
      }
      iter++;
    }
    cout << Result_string << ' ' << Result_number << endl;
    return 0;
}