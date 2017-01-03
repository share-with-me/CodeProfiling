
;; Function main (main, funcdef_no=0, decl_uid=2197, symbol_order=0)

main ()
{
  int x;
  int D.2204;

  x = 10;
  if (x == 10) goto <D.2201>; else goto <D.2202>;
  <D.2201>:
  __builtin_puts (&"Allowed!"[0]);
  goto <D.2203>;
  <D.2202>:
  __builtin_puts (&"Who are you?"[0]);
  <D.2203>:
  D.2204 = 0;
  goto <D.2205>;
  <D.2205>:
  return D.2204;
}


