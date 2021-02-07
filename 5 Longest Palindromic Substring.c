/*
Problem Statement: Given a string s, return the longest palindromic substring in s.
Difficulty Level: Medium
*/



char * longestPalindrome(char * s){

    int sLen=strlen(s);
    int i=0;
    signed int left,right;
    int inBetweenFlag=0;
    int substringMaxLength=1;
    char *substringPtr = s;
    
    for(i=0; i<((2*sLen)-1); i++)
    {
        if(inBetweenFlag == 0)
        {
            inBetweenFlag = 1;
            left = i/2;
            right = i/2;
        }
        else
        {
            inBetweenFlag = 0;
            left = i/2;
            right = (i/2) + 1;
        }
        
        while((left>=0) && (right<sLen) && (s[left] == s[right]) )
        {
            if(substringMaxLength < (right-left+1) )
            {
                substringMaxLength = (right-left+1);
                substringPtr = &s[left];
            }
            left--;
            right++;
        }
    }
    
    substringPtr[substringMaxLength] = 0;
    printf("%s", substringPtr);
    
    return substringPtr;
}
