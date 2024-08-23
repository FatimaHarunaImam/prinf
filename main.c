#include <stdarg.h>
#include <unistd.h>

/* _printf function implementation */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    const char *p;

    va_start(args, format);

    for (p = format; *p != '\0'; p++)
    {
        if (*p == '%')
        {
            p++;
            if (*p == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*p == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    write(1, str++, 1);
                    count++;
                }
            }
            else if (*p == '%')
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1, p, 1);
            count++;
        }
    }

    va_end(args);
    return count;
}

/* Test the _printf function */
int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent sign: %%\n");
    return 0;
}
