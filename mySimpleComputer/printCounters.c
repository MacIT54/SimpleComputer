#include <mySimpleComputer.h>
#include <sc.h>

void
printCounters ()
{
  int icounter_value;
  sc_icounterGet (&icounter_value);
  printf ("Instruction Counter value: %d\n", icounter_value);
}