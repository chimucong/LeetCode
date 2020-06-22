#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
    	if(num1 == "0" || num2 == "0"){
    		return "0";
    	}
        int l1 = num1.size();
        int l2 = num2.size();
        vector<int> n1(l1);
        vector<int> n2(l2);
        vector<int> s(l1 + l2 - 1);
        for(int i = 0; i < l1; i++){
        	n1[i] = num1[i] - '0';
        }
        for(int i = 0; i < l2; i++){
        	n2[i] = num2[i] - '0';
        }
        for(int i = 0; i < l1; i++){
        	for(int j = 0; j < l2; j++){
        		s[i + j] += n1[i] * n2[j];
        	}
        }
        int carry = 0;
        for(int i = s.size() - 1; i >= 0; i--){
        	int sum = s[i] + carry;
        	carry = sum / 10;
        	sum = sum % 10;
        	s[i] = sum;
        }
        string result(s.size(), '\0');
        for(int i = 0; i < s.size(); i++){
        	result[i] = (char) (s[i] + '0');
        }
        if(carry == 0){
        	return result;
        }else{
        	char c = (char) ('0' + carry);
        	return c + result;
        }
    }
};

int main(){
	string a, b;
	cin >> a >> b;
	Solution sol;
	cout << sol.multiply(a, b);
	return 0;
}