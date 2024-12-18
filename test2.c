#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (-1);
    return (1);
}
void ft_putnbr(int nb)
{
    unsigned int nbr;

    if (nb < 0)
    {
        ft_putchar('-');
        nbr = nb * -1;
    }
    else
        nbr = nb;
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + '0');
}

void ft_putstr(char *str)
{
    int len;
    len = 0;
    while (str[len])
    {
        len++;
    }
    write(1, str, len);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    va_start(args, format);
    // printf("Starting ft_printf with format: %s\n", format); // Debugging

    while (format[i])
    {
        // printf("Current character: %c\n", format[i]); // Debugging
        if (format[i] == '%')
        {
            format++;
            // printf("Found a format specifier: %c\n", format[i]); // Debugging

            if (format[i] == 'd')
            {
                int num = va_arg(args, int);
                // printf("Extracted argument (integer): %d\n", num); // Debugging
                ft_putnbr(num);
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char *);
                // printf("Extracted argument (string: %s\n", str); // Debugging
                ft_putstr(str);
            }
            else
            {
                // printf("Unrecognized format specifier: %c\n", format[i]); // Debugging
                ft_putchar('%'); // Print the '%' character
                // ft_putchar(format[i]);
            }
        }
        else
        {
            // printf("Printing character: %c\n", format[i]); // Debugging
            ft_putchar(format[i]);
        }
        format++;
    }

    va_end(args);
    // printf("Finished processing format string.\n"); // Debugging
    return (0);
}
int main(void)
{
    char *s = "abc";
    // char k = 'c';
    int num = 42;
    int result = printf("Hello %s, ABC %d\n", s, num);

    ft_printf("cf: Hello %q, ABC %d\n", s, num);

    printf("of: Hello %q, ABC %d\n", s, num);
    // ft_putstr("hello\n");
    // ft_putstr("hello\n");
    // ft_putstr("hi\n");
    // ft_putnbr(num);
    // ft_putchar('\n');
    // ft_putchar(k);
    // ft_putchar('\n');
    // printf("Hello %x, number %d\n", 87687678, num);
    return (0);
}