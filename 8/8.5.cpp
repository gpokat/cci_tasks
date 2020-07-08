//Recursive Multiply: Write a recursive function to multiply two positive integers without using the
//* operator. You can use addition, subtraction, and bit shifting, but you should minimize the number
//of those operations.

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//The solution could extremely optimize to using by LongAddition.
//Or pretty good solution showed in the book !!! Anyway this solution doesn't cover
//extreme cases with big integers due to overflow (but LongAddition does).

//recursive add b times a value to itself
//Space is O(1) (or O(b) if stack is included), runtime is O(b)
int RecursiveMultiplication(int a, int b)
{
    if (b <= 0)
        return 0;

    return a + RecursiveMultiplication(a, b - 1);
}


//Space is O(1) (or O(log(a)) if stack is included), runtime is O(log(a))
int RecursiveMult(int a, int b)
{
    //edge cases
    if (a == 0)        return 0;
    if (a == 1)        return b;

    int div_by_two = a / 2;
    int double_mult = RecursiveMult(div_by_two, b); //going to bottom as possible

    if (a % 2 == 0)
    {                                     //if a is even
        return double_mult + double_mult; //just doubled
    }
    else
    {                                         //if a is odd
        return double_mult + double_mult + b; //doubled & add extra 'odd' part
    }
}

int RecursiveMultBook(int a, int b)
{
    if (a > b)
        swap(a, b);
    return RecursiveMult(a, b); //must be as (smaller, bigger) pattern
}
