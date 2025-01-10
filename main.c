#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	//1. string test
	puts("STRING TEST:");
	char *s = "hello";
	ft_printf("string 1: %s\n", s);
	printf("string 2: %s\n", s);
	//2. char test
	puts("CHAR TEST:");
	char k = 'w';
	ft_printf("char 1: %c\n", k);
	printf("char 2: %c\n", k);
	//3. integer test
	puts("INT TEST:");
	int num = 42;
	ft_printf("num 1: %d, %d, %d, %d, %d\n", -42, 0, num, INT_MAX, INT_MIN );
	printf("num 2: %d, %d, %d, %d, %d\n", -42, 0, num, INT_MAX, INT_MIN);
	//4. pointer test
	puts("POINTER TEST:");
	int x = 5;
	int *ptr =&x;
	char *ptr3 = "hi";
	char *ptr4 = NULL;
	ft_printf("ptr 1:%p %p %p\n", ptr, ptr3, ptr4);
	printf("ptr 2:%p %p %p\n", ptr, ptr3, ptr4);
	//5. hexagon test
	puts("HEX TEST:");
	unsigned int hex_num = 26475;
	ft_printf("print hex 1 %x and %X\n", hex_num, hex_num);
	printf("print hex 2 %x and %X\n", hex_num, hex_num);
	//6. unsigned int
	puts("UNSIGNED TEST:");
	unsigned int n = 4252;
	ft_printf("print unsigned 1 %u\n", n);
	printf("print unsigned 2 %u\n", n);
	//7. %
	puts("INVALID SPEC TEST:");
	ft_printf("percent 1 %\n");
	printf("percent 2 %\n");
	ft_printf("percent 1 %%\n");
	printf("percent 2 %%\n");
	
	int i, j;
	
	i = printf("1abc %z\n");
    printf("%d\n", i);
    
    j = ft_printf("2abc %z\n");
    printf("%d\n", j);

	//8. Total chars check
	puts("TOTAL CHARS TEST");
	int total_chars1 = 0;
	int total_chars2 = 0;
	int num2 = 42;

	total_chars1 = ft_printf("1%s,%s,%s,%d\n", "one", "two", "3", num2);
	ft_putchar('\n');
	total_chars2 = printf("2%s,%s,%s,%d\n", "one", "two", "3", num);

	printf("total: %d\n", total_chars1);
	printf("total2: %d\n", total_chars2);

	//WRITE ERRROR TEST
	puts("WRITE ERRROR TEST");
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

	printf("1%d\n", a);
	printf("2%d\n", aa);
	printf("1%d\n", b);
	printf("2%d\n", bb);
	printf("1%d\n", c);
	printf("2%d\n", cc);
	printf("1%d\n", d);
	printf("2%d\n", dd);
	printf("1%d\n", e);
	printf("2%d\n", ee);
	printf("1%d\n", f);
	printf("2%d\n", ff);
	printf("1%d\n", g);
	printf("2%d\n", gg);
	printf("1%d\n", h);
	printf("2%d\n", hh);

	return (0);
}