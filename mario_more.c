  #include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {

        n = get_int("Get positive number: ");

    }
    while (n < 1 || n > 8);
    int hash = 0;
    // iterate through height
    for (int i = 0; i < n; i++)
    {
        // iterate through width
        for (int j = 0; j < n; j++)
        {
            // print spaces to align pyramid to the right
            if (i + j < n - 1)
            printf(" ");
            // print actual pyramid blocks
            else
            {
                printf("#");
                hash++;     // count how many blocks are being printed to mirror it on opposite site
            }
            // check if half of pyramid has been printed
            if (j == n - 1)
            {
                // print spaces seperating the halves
                printf("  ");
                // print other half with hash counter
                for (int k = 0; k < hash; k++)
                {
                    printf("#");
                }
                hash = 0;
            }
        }
        printf("\n");

    }

}
