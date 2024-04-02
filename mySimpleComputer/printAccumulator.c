#include <mySimpleComputer.h>
#include <sc.h>

void
printAccumulator ()
{
  int accumulator_value;
  sc_accumulatorGet (&accumulator_value);
  printf ("Accumulator value: %d\n", accumulator_value);
}