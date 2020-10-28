/* C Program to compute polynomial code checksum */
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>

#define degree 4
int result[50];
int gen[20] = { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }; //ccitt polynomial* x16 + x12 + x5 + 1
int length;
void calcrc();

void calcrc() {
    int pos = 0, j, i;
    while (pos < (length - degree)) {
        j = 0;
        for (i = pos; i <= (pos + degree); i++, j++) {
            result[i] = result[i] ^ gen[j];
        }
        i = pos;
        while (result[i++] == 0)
            pos++;
    }
}

int main() {
    int array[50], flag = 0;
    int i = 0;
    char ch;

    printf("Enter frame: ");
    while ((ch = getche()) != '\r') {
        array[i++] = ch - '0';
    }
    length = i;
    for (i = length; i < length + degree; i++) {
        array[i] = 0;
    }
    length = length + degree;
    for (i = 0; i < length; i++) {
        result[i] = array[i];
    }
    calcrc();
    for (i = 0; i < length; ++i) {
        result[i] = (result[i] | array[i]);
    }
    printf("\nThe result is \n");
    for (i = 0; i < length; i++)
        printf("%d", result[i]);

    printf("\nEnter the stream for which CRC has to be checked : ");
    i = 0;
    while ((ch = getche()) != '\r')
        array[i++] = ch - '0';
    length = i;
    for (i = 0; i < length; i++)
        result[i] = array[i];
    calcrc();
    printf("\nChecksum is: ");

    for (i = 0; i < length; i++) {
        printf("%d", result[i]);
        if (result[i] != 0)
            flag = 1;
    }

    if (flag)
        printf("\nError in transmission\n");
    else
        printf("\nNo error in transmission\n");
    
    return 0;
}