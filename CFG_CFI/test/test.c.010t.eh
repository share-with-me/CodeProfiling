
;; Function helper_function (helper_function, funcdef_no=0, decl_uid=2198, symbol_order=0)

helper_function ()
{
  int D.2209;

  __builtin_puts (&"I am a helper function"[0]);
  D.2209 = 42;
  goto <D.2210>;
  <D.2210>:
  return D.2209;
}



;; Function main (main, funcdef_no=1, decl_uid=2202, symbol_order=1)

main (int argc, char * * argv)
{
  int i;
  int D.2215;
  char * D.2214;
  char * * D.2213;
  long unsigned int D.2212;
  long unsigned int D.2211;

  printf ("argc: %i\n", argc);
  i = 0;
  goto <D.2206>;
  <D.2205>:
  D.2211 = (long unsigned int) i;
  D.2212 = D.2211 * 8;
  D.2213 = argv + D.2212;
  D.2214 = *D.2213;
  printf ("argv[%i]: %s\n", D.2214);
  i = i + 1;
  <D.2206>:
  if (i < argc) goto <D.2205>; else goto <D.2207>;
  <D.2207>:
  helper_function ();
  D.2215 = 0;
  goto <D.2216>;
  <D.2216>:
  return D.2215;
}


