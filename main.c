#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main(void)
{
    char *ptr;
    char *ptr1;

    ptr1 = NULL;
    ptr = "Pointer 12345";
    printf("⭐ Test case: just text ⭐\n");
    if (ft_printf("some text\n") == printf("some text\n"))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: c ⭐\n");
    if (ft_printf("%c\n", 'Y') == printf("%c\n", 'Y'))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: s ⭐\n");
    if (ft_printf("String here: %s\n", "String") == printf("String here: %s\n", "String"))
        printf("\nYES 🔥\n\n");
    else
    {
        printf("\nNOOO 💀\n\n");
    }
    printf("⭐ Test case: p ⭐\n");
    if (ft_printf("Pointer here: %p\n", ptr) == printf("Pointer here: %p\n", ptr))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    void *p2 = (void *)0x1234567890ABCDEF;
    if (ft_printf("%p\n", p2) == printf("%p\n", p2))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: d ⭐\n");
    if (ft_printf("This is digit %d\n", 5) == printf("This is digit %d\n", 5))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    if (ft_printf("%d", -42) == printf("%d", -42))
        printf("\n\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    if (ft_printf("%d%d%d%d", -42, 42, 0, 1000000000) == printf("%d%d%d%d", -42, 42, 0, 1000000000))
        printf("\n\nYES 🔥\n\n");
    else
        printf("\n\nNOOO 💀\n\n");
    printf("⭐ Test case: i ⭐\n");
    if (ft_printf("Integer: %i\n", 3) == printf("Integer: %i\n", 3))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: u ⭐\n");
    if (ft_printf("Unsigned: %u\n", 456567) == printf("Unsigned: %u\n", 456567))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    if (ft_printf("Unsigned negative: %u\n", -456567) == printf("Unsigned negative: %u\n", -456567))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: x/X ⭐\n");
    if (ft_printf("%x\n", 3495) == printf("%x\n", 3495))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    if (ft_printf("%X\n", -345) == printf("%X\n", -345))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: %%%% ⭐\n");
    if (ft_printf("%%\n") == printf("%%\n"))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: %% ⭐\n");
    if (ft_printf("%\n") == printf("%\n"))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: multiply conversions of the same type ⭐\n");
    if (ft_printf("%c%c%c%c%c%c", '1', '2', '3', '4', '5', '6') == printf("%c%c%c%c%c%c", '1', '2', '3', '4', '5', '6'))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    if (ft_printf("%c %c %c %c %c %c", '1', '2', '3', '4', '5', '6') == printf("%c %c %c %c %c %c", '1', '2', '3', '4', '5', '6'))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: multiply conversions of the different types ⭐\n");
    if (ft_printf("%p%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", ptr, 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, '0') == printf("%p%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", ptr, 'A', "42", 42, 42, 42, 42, 42, 'B', "-42", -42, -42, -42, -42, 42, 'C', "0", 0, 0, 0, 0, 42, '0'))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: #, 0, -, +, . ⭐\n");
    if (ft_printf("#, 0, -, +, .") == printf("#, 0, -, +, ."))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: #, 0, -, +, . in different boxes ⭐\n");
    if (ft_printf("#"
                  "0"
                  "-"
                  "+"
                  ".") == printf("#"
                                 "0"
                                 "-"
                                 "+"
                                 "."))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: NULL pointer as s ⭐\n");
    if (ft_printf("%s", ptr1) == printf("%s", ptr1))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: NULL pointer as p ⭐\n");
    if (ft_printf("%p", ptr1) == printf("%p", ptr1))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: Empty ⭐\n");
    if (ft_printf("") == printf(""))
        printf("\nYES 🔥\n\n");
    else
        printf("\nNOOO 💀\n\n");
    printf("⭐ Test case: Error ⭐\n");

    fclose(stdout);
    int a = ft_printf("%c", 'A');
    int aa = printf("%c", 'A');
    int b = ft_printf("%d", 1);
    int bb = printf("%d", 1);
    int c = ft_printf("%u", 425);
    int cc = printf("%u", 425);
    int d = ft_printf("%s", "s");
    int dd = printf("%s", "s");
    int e = ft_printf("%p", ptr);
    int ee = printf("%p", ptr);
    int f = ft_printf("%x", 0);
    int ff = printf("%x", 0);
    int g = ft_printf("%%", 0);
    int gg = printf("%%", 0);
    int h = ft_printf("Hello", 0);
    int hh = printf("Hello", 0);

    freopen("/dev/tty", "w", stdout);

    if (a == aa)
        printf("\n case c: %d YES 🔥\n\n", a);
    else
        printf("\n case c: %d NOOO 💀\n\n", a);

    if (b == bb)
        printf("\n case d: %d YES 🔥\n\n", b);
    else
        printf("\n case d: %d NOOO 💀\n\n", b);
    if (c == cc)
    {
        printf("\n case u: %d YES 🔥\n\n", c);
        printf("\n case u: %d YES 🔥\n\n", cc);
    }

    else
    {
        printf("\n case u: %d NOOO 💀\n\n", c);
        printf("\n case u: %d NOOO 💀\n\n", cc);
    }

    if (d == dd)
        printf("\n case s: %d YES 🔥\n\n", d);
    else
        printf("\n case s: %d NOOO 💀\n\n", d);
    if (e == ee)
        printf("\n case p: %d YES 🔥\n\n", e);
    else
        printf("\n case p: %d NOOO 💀\n\n", e);
    if (f == ff)
        printf("\n case x: %d YES 🔥\n\n", f);
    else
        printf("\n case x: %d NOOO 💀\n\n", f);
    if (g == gg)
        printf("\n case %%%%: %d YES 🔥\n\n", g);
    else
        printf("\n case %%%%: %d NOOO 💀\n\n", g);
    if (h == hh)
        printf("\n case no specifiers: %d YES 🔥\n\n", h);
    else
        printf("\n case no specifiers: %d NOOO 💀\n\n", h);

    // printf("⭐ Test case: CRAZY ⭐\n");
    // if (ft_printf
    // 	printf("\nYES 🔥\n\n");
    // else
    // 	printf("\nNOOO 💀\n\n");
    return (0);
}