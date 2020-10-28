/*Program to simulate bit stuffing &Destuffing where the flag byte is 01111110 */

#include <stdio.h>
#include <conio.h> 
#include <string.h>

int main() {
        char ch, array[50] = { "01111110" }, recd_array[50];
        int counter = 0, i = 8, j, k;

        printf("Enter the original data stream for bit stuffing: ");

        while ((ch = getche()) != '\r') {
            if (ch == '1')
                ++counter;
            else
                counter = 0;
            array[i++] = ch;
            if (counter == 5) /*If 5 ones are encountered append a zero */
            {
                array[i++] = '0';
                counter = 0;
            }
        }

        array[i] = '\0';
        strcat(array, "01111110");
        array[i + 8] = '\0';
        printf("\n\nThe stuffed data stream is : %s \n", array);

        /*Destuffing */
        counter = 0;
        for (j = 8, k = 0; j < (strlen(array) - 8); ++j) {
            if (array[j] == '1')
                ++counter;
            else
                counter = 0;
            recd_array[k++] = array[j];

            if (counter == 5) /*If five ones appear, delete the following zero */
            {
                ++j;
                counter = 0;
            }
        }

        recd_array[k] = '\0';
        printf("\nThe destuffed data stream is % s \n", recd_array);

    return 0;
    }