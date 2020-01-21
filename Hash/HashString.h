/*************************************************************************
	> File Name: HashString.h
	> Author: 
	> Mail: 
	> Created Time: 一  1/13 01:47:39 2020
 ************************************************************************/

#ifndef _HASHSTRING_H
#define _HASHSTRING_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Hash{
typedef long long ll;
private:
  vector<ll> table1,table2;
  vector<ll> store1,store2;
  const ll Mod1 = 1e9+7,Mod2 = 998244353;
  const ll B1 = 131,B2 = 13131;
public:
  Hash(const string &str){
    table1.resize(str.size());
    table2.resize(str.size());
    store1.resize(str.size());
    store2.resize(str.size());
    for(int i=0;i<str.size();++i){
      if(i == 0){
        table1[i] = table2[i] = str[i];
        store1[i] = store2[i] = 1;
      }else{
        table1[i] = (table1[i-1]*B1 + str[i])%Mod1;
        store1[i] = (store1[i-1]*B1)%Mod1;
        
        table2[i] = (table2[i-1]*B2 + str[i])%Mod2;
        store2[i] = (store2[i-1]*B2)%Mod2;
      }
    }
  }
  ll getHashValue1(int l,int r){
    if(l == 0){
      return table1[r];
    }else{
      ll value1 = (table1[r]-table1[l-1]*store1[r-l+1])%Mod1;
      value1 = (value1+Mod1)%Mod1;
      return value1;
    }
  }
  ll getHashValue2(int l,int r){
    if(l == 0){
      return table2[r];
    }else{
      ll value2 = (table2[r]-table2[l-1]*store2[r-l+1])%Mod2;
      value2 = (value2+Mod2)%Mod2;
      return value2;
    }
  }
};
#endif
