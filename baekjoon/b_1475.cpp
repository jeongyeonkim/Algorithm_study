// 방 번호
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string str;
int num[10], result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i=0; i<str.length(); i++){
        string s;
        s += str[i];
        num[stoi(s)]++; // 문자 숫자 치환
    }
    for(int i=0; i<=9; i++){
        if(i == 9 || i == 6){ continue; }
        result = max(result, num[i]); // 최대의 세트 갯수 result에 저장
    }

    int temp = 0; 
    // 6, 9는 한세트에서 써도 되니까 둘 중에 작은 세트 재사용
    if(num[6] > num[9]){
        temp = num[9];
        if((num[6] - num[9])%2 == 0){ temp += (num[6] - num[9])/2; }
        else{ temp += (num[6] - num[9])/2 + 1; }
    }else if(num[6] < num[9]){
        temp = num[6];
        if((num[9] - num[6])%2 == 0){ temp += (num[9] - num[6])/2; }
        else{ temp += (num[9] - num[6])/2 + 1; }
    }else{ temp = num[6]; }

    result = max(result, temp);
    cout << result;
    return 0;
}