class Solution {
public:
    bool isThree(int n) {
        // from upto 2 we have two divisors 
        // we have to check whether the number is perfect square or not 
        
        if (n <= 2)
            return false;
        if (floor(sqrt(n)) != ceil(sqrt(n))){
            return false;
        }
        for (int i = 2; i*i < n; i++){
            if (n%i == 0)
                return false;
        }
        return true;
    }
};