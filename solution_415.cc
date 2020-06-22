class Solution {
public:
    string addStrings(string num1, string num2) {
    	int l1 = num1.size();
    	int l2 = num2.size();
        string result(std::max(l1, l2), '0');
        int p1 = l1 - 1;
        int p2 = l2 - 1;
        int ps = result.size() - 1;
        int carry = 0;
        while(p1 >= 0 && p2 >=0){
        	int sum = num1[p1--] - '0' + num2[p2--] - '0' + carry;
        	carry = sum / 10;
        	sum = sum % 10;
        	result[ps--] = sum + '0';
        }
        if(p2 >= 0){
        	p1 = p2;
        	num1 = std::move(num2);
        }
        while(p1 >= 0){
        	int sum = num1[p1--] - '0' + carry;
        	carry = sum / 10;
        	sum = sum % 10;
        	result[ps--] = sum + '0';
        }
        if(carry > 0){
        	char c = (char) ('0' + carry);
        	return c + result;
        }else{
        	return result; 
        }
    }
};