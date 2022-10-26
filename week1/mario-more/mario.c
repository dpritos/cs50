#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        // Prompt user for height
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    int pyramidMargin = 2;
    int canvasColumns = (n * 2) + pyramidMargin;

    // Create rows
    for (int i = 1; i <= n; i++)
    {
        // Calculate pyramid A base ranges
        int baseAMin = n - i;
        int baseAMax = (canvasColumns - pyramidMargin) - (n - 1);

        // Calculate pyramid B base ranges
        int baseBMin = n + pyramidMargin;
        int baseBMax = baseBMin + i + 1;

        // Create columns per row
        for (int j = 1; j <= canvasColumns; j++)
        {

            // If the current pixel is greater than or equal to the max base of the second pyramid
            if (j >= baseBMax)
            {
                break;
            }

            // Print hashes if the current pixel is within the base of A and B pyramid ranges otherwise space
            string px = (j > baseAMin && j < baseAMax) || (j > baseBMin && j < baseBMax) ? "#" : " ";
            printf("%s", px);
        }
        printf("\n");
    }
}