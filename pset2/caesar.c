#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check for correct user input
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // create variable to determine strlen for loop
    string s = argv[1];

    // check if input consists of digits only
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert user input into integer
    int k = atoi(argv[1]);


    // make sure user input is positive integer
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // prompt user for plaintext
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    // variable for cipher[i]
    char cipher;

    // iterate over plain text
    for (int i = 0, n = strlen(plain); i < n; i++)
    {

        if (isalpha(plain[i]) == 0)
        {
            cipher = plain[i];
            printf("%c", cipher);
        }

        if (isupper(plain[i]))
        {
            cipher = ((plain[i] - 'A') % 26) + 'A' + k;
            printf("%c", cipher);
        }

        if (islower(plain[i]))
        {
            cipher = ((plain[i] - 'a') % 26) + 'a' + k;
            printf("%c", cipher);
        }



    }
    printf("\n");
    return 0;
}
