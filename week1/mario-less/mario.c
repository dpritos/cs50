#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do {
        // Prompt user for height
        n = get_int("Height: ");
    } while (n < 1 || n > 8);

    // Create rows
    for (int i = 1; i <= n; i++) {

        // Create columns per row
        for (int j = 1; j <= n; j++) {

            // Get the inverse base pixel by subtracting current row with height
            int base = n - i;

            // Print hashes if the current pixel is greater than to base otherwise space
            string px = j > base ? "#" : " ";

            printf("%s", px);
        }
        printf("\n");
    }
}