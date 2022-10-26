#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

const string INVALID = "INVALID";
const string AMEX = "AMEX";
const string MASTERCARD = "MASTERCARD";
const string VISA = "VISA";

long get_card_number(void);
string get_card_provider(long cardNumber);
bool validate_checksum(long cardNumber);

int main(void)
{
    // Ask the card number
    long cardNumber = get_card_number();
    bool isValidChecksum = validate_checksum(cardNumber);
    if (!isValidChecksum)
    {
        printf("%s\n", INVALID);
    }
    else
    {
        string cardProvider = get_card_provider(cardNumber);
        printf("%s\n", cardProvider);
    }
}

long get_card_number(void)
{
    long cardNumber;
    do
    {
        // Prompt user for card number
        cardNumber = get_long("Number: ");
    }
    while (!cardNumber || cardNumber < 0);

    return cardNumber;
}

short get_digits_total(short n)
{
    short tmp = n;
    short t = 0;

    do
    {
        t += tmp % 10;
        tmp /= 10;
    }
    while (tmp > 0);

    return t;
}

bool validate_checksum(long cardNumber)
{
    short doubledTotal = 0;
    short notDoubledTotal = 0;
    short i = 1;
    // Loop each digit through right to left
    for (long tmp = cardNumber ; tmp > 0 ; i++)
    {
        // Get each digit
        short digit = tmp % 10;

        // If counter i is even, double the digit and add to doubledTotal
        if (i % 2 == 0)
        {
            short doubledDigit = digit * 2;
            doubledTotal += get_digits_total(doubledDigit);
        }
        else
        {
            // add to notDoubledTotal
            notDoubledTotal += digit;
        }
        // Removing last digit
        tmp /= 10;
    }

    // Valid if the total of the doubledTotal and notDoubledTotal ends with 0
    return (doubledTotal + notDoubledTotal) % 10 == 0;
}

short get_card_length(long cardNumber)
{
    short l = 0;
    for (long tmp = cardNumber ; tmp > 0 ; l++)
    {
        // Removing last digit
        tmp /= 10;
    }

    return l;
}

short get_card_first_two_digits(long cardNumber)
{
    long n = cardNumber;
    while (n >= 100)
    {
        n = n / 10;
    }

    return n;
}


string get_card_provider(long cardNumber)
{

    short length = get_card_length(cardNumber);
    short firstTwoDigits = get_card_first_two_digits(cardNumber);

    string card = INVALID;
    switch (firstTwoDigits)
    {
        // AMEX
        case 34:
        case 37:
            if (length == 15)
            {
                card = AMEX;
            }
            break;

        // MASTERCARD
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            if (length == 16)
            {
                card = MASTERCARD;
            }
            break;

        default:
            if ((length == 13 || length == 16) && (firstTwoDigits / 10) == 4)
            {
                card = VISA;
            }
    }

    return card;
}