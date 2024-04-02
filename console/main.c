#include <mySimpleComputer.h>

int
main ()
{
  int value;
  puts ("\n");
  sc_memoryInit ();
  sc_regInit ();
  sc_icounterInit ();
  sc_accumulatorInit ();
  sc_memorySet (1, 5);
  sc_memorySet (-2, 4);
  sc_memorySet (3, 3);
  for (int i = 0; i < 3; i++)
    {
      sc_memoryGet (i + 1, &value);
      printf ("RAM[%d] = %d\n", i + 1, value);
    }
  printf ("Save RAM\n");
  sc_memorySave ("./mySimpleComputer/mem.bin");
  printf ("Load RAM\n");
  sc_memoryLoad ("./mySimpleComputer/mem.bin");
  for (int i = 0; i < 3; i++)
    {
      sc_memoryGet (i + 1, &value);
      printf ("RAM[%d] = %d\n", i + 1, value);
    }
  puts ("\n");
  sc_memorySet (10, 54);
  sc_memoryGet (10, &value);
  printf ("RAM[%d] = %d\n", 10, value);

  sc_regInit ();

  sc_regSet (WRONG_FLAG, 1);

  sc_regGet (OUT_OF_MEMORY_BOUNDS, &value);
  printf ("\nRegister: %d, Value: %d ", OUT_OF_MEMORY_BOUNDS, value);

  sc_regGet (WRONG_FLAG, &value);
  printf ("\nRegister: %d, Value: %d ", WRONG_FLAG, value);

  sc_regGet (OPERATION_OVERFLOW, &value);
  printf ("\nRegister: %d, Value: %d ", OPERATION_OVERFLOW, value);

  sc_regGet (INCORRECT_COMMAND_RECEIVED, &value);
  printf ("\nRegister: %d, Value: %d ", INCORRECT_COMMAND_RECEIVED, value);

  sc_regGet (DIVISION_ERR_BY_ZERO, &value);
  printf ("\nRegister: %d, Value: %d ", DIVISION_ERR_BY_ZERO, value);
  puts ("\n");
  sc_accumulatorInit ();
  sc_accumulatorSet (42);
  sc_accumulatorGet (&value);
  sc_icounterInit ();
  sc_icounterSet (5);
  sc_icounterGet (&value);
  int f = 0, f_c = 0, f_o = 0;
  sc_commandEncode (0xb, 0x1, &f);
  printf ("Encoded command: %x  \n", f);
  sc_commandDecode (f, &f_c, &f_o);
  printf ("Command: %x   operand: %x  \n", f_c, f_o);
  puts ("\n");
  printCell (1);
  printAccumulator ();
  printCounters ();
  printFlags ();
  puts ("\n");
  printDecodedCommand (0xa);

  return 0;
}