#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    // get user input
    string text = get_string("Text: ");

    // amount of letters / words
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // iterate over length of input and check for amount of letters
    for (int i = 0; i < strlen(text); i++)
    {
        // count letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        // count words
        if (isspace(text[i]))
        {
            words++;
        }
        // count sentences
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    // print out amount of letters, words and sentences
    // printf("%i letter(s)\n%i word(s)\n%i sentence(s)\n", letters, words, sentences);


    // math to determine the readability grade
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    // Coleman-Liau Index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // rounding the results into an integer
    int result = round(index);

    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}
