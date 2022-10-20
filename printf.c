#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/*
Prototype: int _printf(const char *format, ...);
Description: produces output according to a format
             Format specifiers: %s : print string
                               %c: print character
                               %d: print integer
*/

int _printf(const char *format, ...)
{
  int n;               // for multiples argument
  va_list valist;
  if(format ==NULL)
  {
    return (-1);
  }
  va_list (valist, format);
    for (n = 0; format[n] != '\0'; n++)
    {
        if (format[n] == '%')
        {
        n++;
        switch (format[n])
        {
            case 'c':
            _putchar(va_arg(valist, int));
            break;
            case 's':
            _puts(va_arg(valist, char *));
            break;
            case 'd':
            print_number(va_arg(valist, int));
            break;
            case 'i':
            print_number(va_arg(valist, int));
            break;
            case 'b':
            print_binary(va_arg(valist, int));
            break;
            case 'o':
            print_octal(va_arg(valist, int));
            break;
            case 'x':
            print_hexa_lower(va_arg(valist, int));
            break;
            case 'X':
            print_hexa_upper(va_arg(valist, int));
            break;
            case 'u':
            print_unsigned(va_arg(valist, int));
            break;
            case 'S':
            print_str_unprintable(va_arg(valist, char *));
            break;
            case 'r':
            print_str_reverse(va_arg(valist, char *));
            break;
            case 'R':
            print_rot13(va_arg(valist, char *));
            break;
            case 'p':
            print_ptr(va_arg(valist, void *));
            break;
            case '%':
            _putchar('%');
            break;
            default:
            _putchar('%');
            _putchar(format[n]);
            break;
        }
        }
        else
        {
        _putchar(format[n]);
        }
    }
