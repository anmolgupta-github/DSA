#include<stdio.h>
#include<string.h>

int nfind(char *string , char *pat)
{
    int i,j,start = 0;
    int lasts = strlen(string)-1;
    int lastp = strlen(pat)-1;
    int endmatch = lastp;

    for(i=0;endmatch<=lasts;endmatch++,start++)
    {
        if(string[endmatch]==pat[lastp])
        {
            for(j=0,i=start;j<lastp && string[i]==pat[j];i++,j++); 
            {
                if(j==lastp)
                {
                    return start;
                }
            }
        }
    }
    return -1;
  }

  void main()
  {
    char string[1000];
    char pat[1000];
    printf("Enter the string:\n");
    scanf("%s",string);
    printf("Enter the pattern if its present in the string:");
    scanf("%s",pat);
    int x = nfind(string,pat);
    printf("Pattern found at index:%d",x);
  }
