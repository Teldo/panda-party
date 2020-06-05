#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // only allow 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // turn argv[1] into a string for simplicity
    string s = argv[1];

    // iterate over user input and check for validity
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if not alphabetic return error
        if (isalpha(s[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        // if alphabetic
        if (isalpha(s[i]))
        {
            for (int j = 0; j < i; j++)
            {
                if (s[i] == s[j])
                {
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
            }
        }
    }

    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    int cipher;

    // iterate over plain text
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        // check if alpha, if false print plain as is
        if (isalpha(plain[i]) == 0)
        {
            printf("%c", plain[i]);
        }

        // check if upper, cipher the text and turn original cipher to upper in case it was lower
        if (isupper(plain[i]))
        {
            cipher = plain[i] - 'A';
            printf("%c", toupper(s[cipher]));
        }

        // check if lower, cipher the text and turn original cipher to lower in case it was upper
        if (islower(plain[i]))
        {
            cipher = plain[i] - 'a';
            printf("%c", tolower(s[cipher]));
        }
    }
    printf("\n");
    return 0;

}
