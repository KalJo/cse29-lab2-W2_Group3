#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

   // implement the UTF-8 analyzer here
    //isAllAscii function for utf_8analyzer
 int isAllAscii(char str[])
{
        for(int i = 0; str[i] != 0; i ++)
        {
            if(str[i] > 0x7F)
            {
                return 1;
            }
        }
        return 0;
    }
   int getByteLen(char str[])
    {
        int len = 0;
        for(int i = 0; str[i] != 0; i++)
        {
            //case 1: single byte
            if(str[i] >= 0 && str[i] <= 127)
            {
                len += 1;
                continue;
            }
            //check if two bytes
            if((str[i] & 0xE0) == 0xC0)
            {
                len +=2;
                continue;
            }
            //check if three bytes
            if((str[i] & 0xF0) == 0xE0)
            {
                len+=3;
                i = i + 1;
                continue;
            }
            if((str[i] & 0xF8) == 0xF0)
            {
                len+=4;
                i = i + 2;
                continue;
            }
            else
            {
                len += 0;
            }
        }
        return len;
    }
int countCodepoints(char str[])
     {
          int len = 0;
          for(int i = 0; str[i] != 0; i++)
          {
              //case 1: single byte
              if(str[i] >= 0 && str[i] <= 127)
              {
                  len += 1;
                  continue;
              }
              //check if two bytes
              if((str[i] & 0xE0) == 0xC0)
              {
                  len +=1;
                  i++;
                  continue;
              }
              //check if three bytes
              if((str[i] & 0xF0) == 0xE0)
              {
                  len+=1;
                  i+=2;
                  continue;
              }
              if((str[i] & 0xF1) == 0xF0)
              {
                  len+=1;
                  i+=3;
                  continue;
              }
          }
          return len;
      }
void codetodec(char str[])
{
    int result = 0;
    for(int i = 0; str[i] != 0; i++)
    {   
        char word[4]; 
        //single byte
        if(str[i] >= 0 && str[i] <= 127)
        {
            word[0] = str[i];
            printf("%d ", word[0]);
            continue;
        }
        if((str[i] & 0xD0) == 0xC0)
        {
            word[0] = (str[i] & 0x1F);
            word[1] = (str[i] & 0x3F);
            result = ((word[0] << 6) | word[2]);
            printf("%d ", result);
        }
        if((str[i] & 0xF0) == 0xE0)
        {
            ;
        }
    }
}
    void utf_8analyzer(char str[])
    {
        int isAscii = isAllAscii(str);
        if(isAscii)
        {
            printf("Valid ASCII: true\n");
        }
        else
        {
            printf("Valid ASCII: false\n");
        }
        int length = getByteLen(str);
        printf("Length in Bytes: %d\n", length);
        int amount = countCodepoints(str);
        printf("Number of Code Points: %d\n", amount);

    }
    
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
    else
    {
        utf_8analyzer(argv[1]);
    }
}
 
