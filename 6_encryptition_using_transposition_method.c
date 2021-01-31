#include <conio.h> 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h>

void main()
{
    char inp[50], out[50], key[20], enc[50], dec[50];
    int i, j, k = 0, ilen, tlen, t, klen;
    char ch = 'A';
    printf("Enter the string to be encrypted: ");
    gets(inp);
    printf("\nEnter the key string: ");
    gets(key);
    ilen = strlen(inp);
    tlen = ilen;
    klen = strlen(key);

    for (t = 0; t < ilen; t++)
    {
        if (inp[t] == ' ') 
            inp[t] = '-';
    }

    while (ilen % klen != 0) 
        inp[ilen++] = '-';
    inp[ilen] = '\0';

    for(ch='A'; ch<='Z'; ch++)
        for(j=0; j<=klen; j++)
            if(toupper(key[j]) == ch)    
                for(i=j; i < ilen; i+=klen)
                    out[k++]=inp[i];  
    
    out[k]='\0';   
    printf("\nThe encrypted message is: %s",out); 

// Decryption part
    for (ch = 'A', k = 0; ch <= 'Z'; ch++)
        for (j = 0; j < klen; j++)
            if (toupper(key[j]) == ch)
                for (i = j; i < ilen; i += klen) 
                    dec[i] = out[k++];
    
    dec[tlen] = '\0';

    for (t = 0; t < tlen; t++)
        if (dec[t] == '-') 
            dec[t] = ' ';

    printf("\nThe decrypted message is: %s", dec);
}