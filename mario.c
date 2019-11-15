#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
int main(void)

{
    int n = get_positive_int("Height: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = -1; j < i; j++)
        {
             printf("#");     
        }
        printf("\n"); 
    } 
}    
    
int get_positive_int(string prompt)
{
    int n;
    do
    {
       n = get_int("%s", prompt);
    }
    while(n < 1 || n > 8);   
    return n; 
}
