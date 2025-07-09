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
            if(str[i] > 127)
            {
                return 0;
            }
        }
        return 1;
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
                i++;
                continue;
            }
            //check if three bytes
            if((str[i] & 0xF0) == 0xE0)
            {
                len+=3;
                i+=2;
                continue;
            }
            if((str[i] & 0xF1) == 0xF0)
            {
                len+=4;
                i+=3;
                continue;
            }
        }
        return len;
    }
int getCodepoints(char str[])
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
                  i++;
                  continue;
              }
              //check if three bytes
              if((str[i] & 0xF0) == 0xE0)
              {
                  len+=3;
                  i+=2;
                  continue;
              }
              if((str[i] & 0xF1) == 0xF0)
              {
                  len+=4;
                  i+=3;
                  continue;
              }
          }
          return len;
      }
    void utf_8analyzer(char str[])
    {
        int isAscii = isAllAscii(str);
        if(isAscii)
        {
            printf("Valid ASCII: true");
        }
        else
        {
            printf("Valid ASCII: false");
        }
        int length = getByteLen(str);
        printf("Length in Bytes
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
 
