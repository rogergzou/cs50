#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Number: ");
    long long cardNumber = GetLongLong();
    // prompts user to enter credit card number
    // gets the number from the user
    long long numberCopy = cardNumber;
    long long numTwoDigits;
    string cardType;
    // card type will be what is used at end.
    
    // int cardLength = sizeof(cardNumberCopy);
    // int cardLengthHolder = cardLength;
    int cardLength = 0;
    // gets the length of the card number
    int holder = 0;
    int oddDigit;
    int evenDigit;
     
    // will hold numbers for calculation. Set a 0 for start.
    while (cardNumber > 0)
    {
        oddDigit = cardNumber % 10;
        holder += oddDigit;
        cardNumber /= 10;
        // printf("odd%inumba\n", oddDigit);
        // adds odd digits to holder, moves to the next number
        evenDigit = cardNumber % 10;
        evenDigit *= 2;
        if (evenDigit > 9)
        {
            int firstDigit = evenDigit % 10;
            int secondDigit = 1;
            // must be 1 b/c if single digit multipled by 2, range 0-18
            evenDigit = firstDigit + secondDigit;
        }
        holder += evenDigit;
        // printf("even%inumba\n", evenDigit);
        // multiplies even digits by two, then adds them to holder
        cardNumber /= 10;
        // moves to the next number then
        if ((evenDigit != 0) || (cardNumber > 0))
        {
            cardLength += 2;
        }
        else
        {
            cardLength += 1;
        }
        
        // decreases count by 2, repeats loop until count <= 0
        // even if odd number of digits, even digit line still works
        // will just add zero to the holder
    }    
    // printf("CardLen%iHolder", cardLength);
    bool cardValid = 0;
    // printf("%i", holder);
    if ((holder % 10) == 0)
    {
        cardValid = true;
    }
    else if ((holder % 10) != 0)
    {
        cardValid = false;
        cardType = "INVALID\n";
        // if not divisible by 10, invalid
    }
    // checks if divisible by 10 and if valid
    if (cardValid == true)
    {
        switch (cardLength)
            // different cases based on card length
        {
            case 16:
                // VISA or MasterCard card
                // VISA check
                if ((numberCopy / 1000000000000000) == 4)
                    // takes off last 15 digits, checks first digit
                {
                    cardType = "VISA\n";
                    break;
                }
                
            // MasterCard check
            // checks digits 51-56
                
                numTwoDigits = numberCopy / 100000000000000;
            // takes off last 14 digits, checks first two digits
            // printf("%lli", cardNumberTwoDigits);
                if ((numTwoDigits < 56) && (numTwoDigits > 50))
                {
                    cardType = "MASTERCARD\n";
                    break;
                }
                
                cardType = "INVALID3\n";
            // if was 16 digits and didn't match above cases, invalid
                break;
            case 15:
                // American Express card
                numTwoDigits = numberCopy;
                numTwoDigits /= 10000000000000;
            // takes off last 13 digits
                if ((numTwoDigits == 34) || (numTwoDigits == 37))
                {
                    cardType = "AMEX\n";
                    break;
                }
                cardType = "INVALID\n";
            // if was 15 digits and didn't match above cases, invalid
                break;
            case 13:
                // VISA card
                if (numberCopy / 1000000000000 == 4)
                {
                    cardType = "VISA\n";
                    break;
                }
                cardType = "INVALID\n";
            // if was 15 digits and didn't match above cases, invalid
                break;
            default:
                cardType = "INVALID\n";
            // if not 13, 15, 16 digits, invalid automatically
                break;
        }
    }
   
    printf("%s", cardType);
    // prints card type   
}

