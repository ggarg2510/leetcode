/*
Problem Statement: Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

Difficulty Level: Easy
*/


int digitCount(int x){
    int c=1;
    long ref=1;
    
    for(;;c++){
        ref = ref*10;
        if(x < ref) return c;
    }
}

long power(int base, int unit){
    long val=1;

    if(unit != 0)
    {
        for(;unit>0; unit--){
            val = val * base;
        }
    }
    return val;
}
bool isPalindrome(int x){
    
    bool rtnVal=0;
    int digC,a,b;    
    long headPow=0,tailPow=0;
    
    if(x>=0)
    {
        rtnVal = 1;
        digC = digitCount(x)-1;
        headPow = power(10,digC);
        tailPow = power(10,0);

        for(; digC>=0; digC--)
        {
            a = (x/headPow)%10;
            b = (x/tailPow)%10;
            if(a!=b)    rtnVal=0;        
            
            headPow = headPow/10;
            tailPow = tailPow*10;            
        }
    }    
        
    return rtnVal;
}
