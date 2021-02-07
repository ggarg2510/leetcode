/*
Problem Statement: Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
Difficulty Level: Medium
*/
//#define DEBUG_FLAG
//#define PRINT_RESULT_STRING
void print_map(int **map, int s1Len, int s2Len, char *s1, char *s2)
{
	int i,j;
#ifdef DEBUG_FLAG
    printf("print_map(): s1Len=%d, s1Len=%d\r\n", s1Len, s2Len);
#endif
	for(i=0; i<s1Len; i++)
	{
		if(i==0)
		{
			printf(" |");
			for(j=0; j<s2Len; j++)
			{
				printf("%c ", s2[j]);
			}
			printf("\r\n");
			printf("-+");
			for(j=0; j<s2Len; j++)
			{
				printf("--");
			}
			printf("\r\n");
		}

		for(j=0; j<s2Len; j++)
		{
			if(j==0)
			{
				printf("%c|", s1[i]);
			}
			printf("%d ", map[i][j]);
		}
		printf("\r\n");
	}
	printf("\r\n");
}


int longestPalindromeSubseq(char * s){
	char *sRev, *resultStr;
	int sLen=0, resultStrLen=0;
	int result = 0, i, j;
	int **map, **ptrMap;

    sLen = strlen(s);
    
    sRev = (char *)malloc(sizeof(char) * (1+sLen));
	memset(sRev, 0, 1+sLen);
    
    for(i=0; i<sLen; i++)
    {
        *(sRev + sLen-i-1) = s[i];            
    }


#ifdef DEBUG_FLAG
	printf("%s\r\n%s\r\n", s, sRev);
#endif

    map = (int **)malloc(sizeof(int*)*sLen);
	ptrMap = (int **)malloc(sizeof(int*)*sLen);
	for(j=0; j<sLen; j++)
	{
		map[j] = (int *)malloc(sizeof(int) * sLen);
		ptrMap[j] = (int *)malloc(sizeof(int) * sLen);
	}

	for(i=0; i<sLen; i++)
	{
		for(j=0; j<sLen; j++)
		{
			map[i][j]=0;
			ptrMap[i][j]=0;
		}
	}

#ifdef DEBUG_FLAG
	print_map(map, sLen, sLen, s, sRev);
	print_map(ptrMap, sLen, sLen, s, sRev);
#endif

	for(i=0; i<sLen; i++)
	{
		for(j=0; j<sLen; j++)
		{
			if(s[i] == sRev[j]){
				if(!i || !j)    map[i][j] = 1;
				else		    map[i][j] = 1 + map[i-1][j-1];
				ptrMap[i][j]=3;
			}
			else{
				if(i>0 && j>0){
					if(map[i-1][j] >= map[i][j-1]){
						map[i][j] = map[i-1][j];
						ptrMap[i][j]=2;
					}
					else{
						map[i][j] = map[i][j-1];
						ptrMap[i][j]=1;
					}					
				}
				else if(i==0 && j>0){
					map[i][j] = map[i][j-1];
					ptrMap[i][j]=1;
				}
				else if(j==0 && i>0){
					map[i][j] = map[i-1][j];
					ptrMap[i][j]=2;
				}
			}
		}
	}

#ifdef DEBUG_FLAG
	print_map(map, sLen, sLen, s, sRev);
	print_map(ptrMap, sLen, sLen, s, sRev);
#endif
    resultStrLen = map[sLen-1][sLen-1];
    printf("%d", resultStrLen);


#ifdef PRINT_RESULT_STRING
	resultStr = (char *)malloc(sizeof(char) * (1+resultStrLen));

	memset(resultStr, 0, 1+resultStrLen);
	i = sLen - 1;
	j = sLen - 1;
#ifdef DEBUG_FLAG
	printf("%d, %d, %d %d\r\n", i, j, resultStrLen, sLen-1);
#endif

	while(resultStrLen)
	{
		if(ptrMap[i][j] == 3){
			*(resultStr + resultStrLen - 1) = s[i];
			resultStrLen--;
			i--;
			j--;
		}
		else if(ptrMap[i][j] == 2){
			i--;
		}
		else if(ptrMap[i][j] == 1){
			j--;
		}
	}

	printf("string: %s\r\n",resultStr);
#endif

    free(sRev);

	for(j=0; j<sLen; j++)
	{
		free(map[j]);
		free(ptrMap[j]);
	}
  //  free(*map);
    //free(*ptrMap);

    return resultStrLen;
}








