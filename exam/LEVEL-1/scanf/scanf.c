// ft_scanf.c
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        if (!isspace(c))
        {
            ungetc(c, f);
            break;
        }
    }
    return 0;
}

int match_char(FILE *f, char c)
{
    int ch = fgetc(f);
    if (ch == c)
        return 1;
    if (ch != EOF)
        ungetc(ch, f);
    return 0;
}

int scan_char(FILE *f, va_list ap)
{
    int c = fgetc(f);
    if (c == EOF)
        return 0;
    char *out = va_arg(ap, char *);
    *out = c;
    return 1;
}

int scan_int(FILE *f, va_list ap)
{
    int c;
    int sign = 1;
    int result = 0;
    int has_digit = 0;

    match_space(f);

    c = fgetc(f);
    if (c == '-' || c == '+')
    {
        if (c == '-')
            sign = -1;
        c = fgetc(f);
    }

    while (isdigit(c))
    {
        has_digit = 1;
        result = result * 10 + (c - '0');
        c = fgetc(f);
    }

    if (c != EOF)
        ungetc(c, f);

    if (!has_digit)
        return 0;

    int *out = va_arg(ap, int *);
    *out = result * sign;
    return 1;
}

int scan_string(FILE *f, va_list ap)
{
    match_space(f);

    char *out = va_arg(ap, char *);
    int c;
    int i = 0;

    while ((c = fgetc(f)) != EOF && !isspace(c))
    {
        out[i++] = c;
    }

    if (c != EOF)
        ungetc(c, f);

    if (i == 0)
        return 0;

    out[i] = '\0';
    return 1;
}

int match_conv(FILE *f, const char **format, va_list ap)
{
    switch (**format)
    {
        case 'c':
            return scan_char(f, ap);
        case 'd':
            match_space(f);
            return scan_int(f, ap);
        case 's':
            match_space(f);
            return scan_string(f, ap);
        case EOF:
            return -1;
        default:
            return -1;
    }
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
    int nconv = 0;

    int c = fgetc(f);
    if (c == EOF)
        return EOF;
    ungetc(c, f);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (match_conv(f, &format, ap) != 1)
                break;
            else
                nconv++;
        }
        else if (isspace(*format))
        {
            if (match_space(f) == -1)
                break;
        }
        else if (match_char(f, *format) != 1)
            break;
        format++;
    }

    if (ferror(f))
        return EOF;
    return nconv;
}

int ft_scanf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return ret;
}


int main()
{
    int num;
    char str[100];
    char ch;

    printf("Enter an integer: ");
    if (ft_scanf("%d", &num) == 1)
        printf("You entered: %d\n", num);
    else
        printf("Invalid input for integer.\n");

    printf("Enter a string: ");
    if (ft_scanf("%s", str) == 1)
        printf("You entered: %s\n", str);
    else
        printf("Invalid input for string.\n");

    printf("Enter a character: ");
    if (ft_scanf("%c", &ch) == 1)
        printf("You entered: %c\n", ch);
    else
        printf("Invalid input for character.\n");

    return 0;
}