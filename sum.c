// #include <stdio.h>
// #include <stdarg.h>

// int sum(int count, ...)
// {
//     int total = 0;
//     int i = 0;

//     va_list args;
//     va_start(args, count);

//     while (i < count)
//         total = total + va_arg(args, int);

//     va_end(args);

//     return total;
// }
// int main()
// {
//     printf("Sum of 1, 2, 3: %d\n", sum(3, 1, 2, 3));               // 6
//     printf("Sum of 10, 20, 30, 40: %d\n", sum(4, 10, 20, 30, 40)); // 100
//     return 0;
// }
#include <stdio.h>
#include <stdarg.h>

// Function to find the sum of given numbers
int sum(int count, ...)
{
    int total = 0;

    // Initializing the va_list to store the variable arguments
    va_list args;
    va_start(args, count);
    printf("va_list %d", args);
    // Accessing the arguments one by one
    for (int i = 0; i < count; i++)
    {
        total += va_arg(args, int);
    }

    // Cleaning up
    va_end(args);

    return total;
}

int main()
{
    printf("Sum of 1, 2, 3: %d\n", sum(5, 1, 2, 3, 4, 5));            // 6
    printf("Sum of 10, 20, 30, 40: %d\n", sum(4, 10, 20, 30, 40, 5)); // 100
    return 0;
}