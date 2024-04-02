#include <mySimpleComputer.h>
#include <sc.h>

void
printDecodedCommand (int value)
{
  printf ("Decimal: %d\n", value);
  printf ("Octal: %o\n", value);
  printf ("Hexadecimal: %X\n", value);
  printf ("Binary: ");
  for (int i = 31; i >= 0; i--)
    {
      printf ("%d", (value >> i) & 1);
    }
  printf ("\n");
}
