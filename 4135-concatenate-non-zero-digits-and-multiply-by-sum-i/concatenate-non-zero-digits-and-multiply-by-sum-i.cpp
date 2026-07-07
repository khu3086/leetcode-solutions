class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num=0;
        long long sum=0;
        while(n){
            long long last=n%10;
            n/=10;
            if(last) num=num*10+last;
            sum+=last;
        }
        long long num2=0;
        while(num){
            num2=num%10+num2*10;
            num/=10;
        }
        return num2*sum;
    }
};