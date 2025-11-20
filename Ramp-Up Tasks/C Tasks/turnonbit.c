#include <stdio.h>
#include <stdlib.h>
#include "turnonbit.h"

int position_bit_on( int num, const int bit_pos )
{
    int mask;
    int final;

    mask = 1 << bit_pos; //puts a 1 in the place which has been entered
    
    final = num | mask; //simple masking with 'or' to turn on the desired bit
    printf("Your new number is %d", final);
    
    return final;
}

int position_bit_off( int num, const int bit_pos )
{
    int mask;
    int final;

    mask = 1 << bit_pos; //puts a 1 in the place which has been entered
    
    final = num & ~mask; //simple masking with NOT 'and' to put a 1 in the place and turn off a bit
    printf("Your new number is %d", final);

    return final;
}

int position_bit_toggle(int num, const int bit_pos)
{
    int mask;
    int final;

    mask = 1 << bit_pos; // 'xor' makes it so that you don't need to check for value in current bit
    final = num ^ mask; // because if it is 0, it will become 1 and if it is 1, it will become 0 (toggled)
    printf("Your new number is %d", final);

    return (final);
}

int right_most_one_off(int num)
{
    int result = num & ( num - 1 );
    printf("The original number was %d\n", num);
    printf("The new number with the rightmost bit turnt off is %d\n", result);
    return(result);
}

int count_num_one_bits(int num)
{
    unsigned int mask = 1;
    int x = 0; //acts as a counter of the number of ones there are
    while(mask) //after certain number of shifts, a is shifted out of bounds of a integer (4 bytes) and becomes 0
    {   
        if(mask & num)
            x++;
        mask = mask << 1;
    }

    printf("The number %d has %d one bits in it\n", num, x);
    return (x);
}

int count_num_zero_bits(int num)
{
    unsigned int mask = 1;
    int x = 0;
    
    while (mask)
    {
        if (!(mask & num)) //same code, just '!' used to indicate not
            x++;
        mask = mask << 1;
    }

    printf("The number %d has %d zero bits in it\n", num, x);
    return (x);
}

int n_bits_from_pos_p(int num, int position, int num_bits) //COMPLETELY DONT UNDERSTAND
{
    int result = 0;
    int x = (1<<num_bits) - 1; 
    x = x << (position - num_bits); 
    result = num & x;
    result = result>>(position - num_bits);
    printf("The bits in %d from the position %d was %d!\n",
        num, position, result);
    return result;
}


int menu()
{
    int choice = 0;
    do
    {
        printf("\nBitwise Operators Demo !!!\n");
        printf("1. Turn On Bit.\n");
        printf("2. Turn Off Bit.\n");
        printf("3. Toggle Bit.\n");
        printf("4. Turn Off RightMost 1 bit.\n");
        printf("5. Get N bits from position.\n");
        printf("6. Count 1 bits.\n");
        printf("7. Count 0 bits.\n");
        printf("8. Get N Bits from Position P.\n");
        printf("9. Exit.\n");
        printf("Enter your choice please: ");
        scanf("%d", &choice);
    } while(choice < 0 || choice > 9);

    return choice;
}

int run_bitwise(){

    int number;
    int bit_numbers;
    int bitPosition;
    int choice;
    int exit_checker = 0;


    while(exit_checker == 0)    
    
    {
        choice = menu();

        switch(choice){
            case 1:
                printf("Enter a number: ");
                scanf("%d", &number);
                printf("Enter a bit position (0-indexing): ");
                scanf("%d", &bitPosition);
                return(position_bit_on(number, bitPosition));
                break;

            case 2:
                printf("Enter a number: ");
                scanf("%d", &number);
                printf("Enter a bit position (0-indexing): ");
                scanf("%d", &bitPosition);  
                return(position_bit_off(number, bitPosition));          
                break;

            case 3:
                printf("Enter a number: ");
                scanf("%d", &number);
                printf("Enter a bit position (0-indexing): ");
                scanf("%d", &bitPosition);
                return(position_bit_toggle(number, bitPosition));
                break;

            case 4:
                printf("Enter a number: ");
                scanf("%d", &number);
                return(right_most_one_off(number));
                break;
            
            case 5:
                printf("Enter a number: ");
                scanf("%d", &number);
                printf("Enter a position: ");
                scanf("%d", &bitPosition);
                printf("Enter the number of bits you want: ");
                scanf("%d", &bit_numbers);
                return(n_bits_from_pos_p(number, bitPosition, bit_numbers));
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%d", &number);
                return(count_num_one_bits(number));
                break;
            
            case 7:
                printf("Enter a number: ");
                scanf("%d", &number);
                return(count_num_zero_bits(number));
                break;
            
            case 8:
                printf("Enter a number: ");
                scanf("%d", &number);
                printf("Enter a position: ");
                scanf("%d", &bitPosition);
                printf("Enter the number of bits you want: ");
                scanf("%d", &bit_numbers);
                return(n_bits_from_pos_p(number, bitPosition, bit_numbers));
                break;

            case 9:
                printf("Thanks for using this code, see ya!");
                exit_checker = 1;
                break;

            default:
                printf("\nThat hasn't been built yet!\n");
                break;
        }
    }

    return(0);
}