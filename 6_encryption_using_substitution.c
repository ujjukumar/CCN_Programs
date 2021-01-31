#include <string.h>
#include <stdio.h>

void main()
    {
        char data[50], encoded[50], decoded[50];
        int i, len, key;
        printf("\nEnter data to be encoded:");
        gets(data);

        len = strlen(data);
        printf("\nEnter the key for encryption :");
        scanf("%d", &key);

        for (i = 0; i < len; i++) {
            encoded[i] = 'a' + ((data[i] - 'a') + key)%25;
        }
        encoded[i] = '\0';
        printf("\nThe encrypted data is %s", encoded);

        /*decryption */
        for (i = 0; i < len; i++) {
            decoded[i] = 'a' + (((encoded[i] - 'a') + (26 - key))%26);
        }
        decoded[i] = '\0';

        printf("\nThe decrypted message is %s", decoded);
    }