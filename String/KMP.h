/*
 * @Author: henuzxy
 * @Date: 2020-08-16 17:08:45
 * @LastEditTime: 2020-08-17 09:42:09
 * @description: 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class KMP{
public:
    int match(const string &str,const string &pattern){
        vector<int> next = this->getnext(pattern);
        int i = 0,j = 0;
        while(i < (int)str.size() && j < (int)pattern.size()){
            if(j == -1 || str[i] == pattern[j]){
                i += 1;
                j += 1;
            }else{
                j = next[j];
            }
        }
        if(j == (int)pattern.size()){
            return i-(int)pattern.size();
        }else{
            return -1;
        }
    }
private:
    vector<int> getnext(const string &str){
        vector<int> next(str.size()+1,-1);
        int i = 0,j = -1;
        while(i < (int)str.size()){
            if(j == -1 || str[i] == str[j]){
                next[++i] = ++j;
            }else{
                j = next[j];
            }
        }
        return next;
    }
};
int main(void){



    return 0;
}