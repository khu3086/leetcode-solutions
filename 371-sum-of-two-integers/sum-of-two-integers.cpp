class Solution {
public:
    int getSum(int a, int b) {
        int carry=(a&b)<<1;
        int sum=a^b;
        while(carry!=0){
            int temp1=carry;
            int temp2=sum;
            sum=temp1^temp2;
            carry=(temp1&temp2)<<1;
        }
        return sum;
    }
};