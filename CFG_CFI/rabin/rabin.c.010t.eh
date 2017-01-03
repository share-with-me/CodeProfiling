
;; Function search (search, funcdef_no=0, decl_uid=2367, symbol_order=0)

search (char * pat, char * txt, int q)
{
  int h;
  int t;
  int p;
  int j;
  int i;
  int N;
  int M;
  int D.2441;
  int D.2438;
  int D.2437;
  char D.2436;
  char * D.2435;
  sizetype D.2434;
  int D.2433;
  int D.2432;
  int D.2431;
  int D.2430;
  int D.2429;
  char D.2428;
  char * D.2427;
  sizetype D.2426;
  int D.2423;
  char D.2418;
  char * D.2417;
  sizetype D.2416;
  char D.2415;
  char * D.2414;
  sizetype D.2413;
  int D.2412;
  int D.2409;
  int D.2408;
  char D.2407;
  char * D.2406;
  sizetype D.2405;
  int D.2404;
  int D.2403;
  int D.2402;
  char D.2401;
  char * D.2400;
  sizetype D.2399;
  int D.2398;
  int D.2397;
  int D.2396;
  long unsigned int D.2395;
  long unsigned int D.2394;

  D.2394 = strlen (pat);
  M = (int) D.2394;
  D.2395 = strlen (txt);
  N = (int) D.2395;
  p = 0;
  t = 0;
  h = 1;
  i = 0;
  goto <D.2377>;
  <D.2376>:
  D.2396 = h * 256;
  h = D.2396 % q;
  i = i + 1;
  <D.2377>:
  D.2397 = M + -1;
  if (D.2397 > i) goto <D.2376>; else goto <D.2378>;
  <D.2378>:
  i = 0;
  goto <D.2380>;
  <D.2379>:
  D.2398 = p * 256;
  D.2399 = (sizetype) i;
  D.2400 = pat + D.2399;
  D.2401 = *D.2400;
  D.2402 = (int) D.2401;
  D.2403 = D.2398 + D.2402;
  p = D.2403 % q;
  D.2404 = t * 256;
  D.2405 = (sizetype) i;
  D.2406 = txt + D.2405;
  D.2407 = *D.2406;
  D.2408 = (int) D.2407;
  D.2409 = D.2404 + D.2408;
  t = D.2409 % q;
  i = i + 1;
  <D.2380>:
  if (i < M) goto <D.2379>; else goto <D.2381>;
  <D.2381>:
  i = 0;
  goto <D.2386>;
  <D.2385>:
  if (p == t) goto <D.2410>; else goto <D.2411>;
  <D.2410>:
  j = 0;
  goto <D.2384>;
  <D.2383>:
  D.2412 = i + j;
  D.2413 = (sizetype) D.2412;
  D.2414 = txt + D.2413;
  D.2415 = *D.2414;
  D.2416 = (sizetype) j;
  D.2417 = pat + D.2416;
  D.2418 = *D.2417;
  if (D.2415 != D.2418) goto <D.2419>; else goto <D.2420>;
  <D.2419>:
  goto <D.2382>;
  <D.2420>:
  j = j + 1;
  <D.2384>:
  if (j < M) goto <D.2383>; else goto <D.2382>;
  <D.2382>:
  if (j == M) goto <D.2421>; else goto <D.2422>;
  <D.2421>:
  printf ("Pattern found at index %d \n", i);
  <D.2422>:
  <D.2411>:
  D.2423 = N - M;
  if (D.2423 > i) goto <D.2424>; else goto <D.2425>;
  <D.2424>:
  D.2426 = (sizetype) i;
  D.2427 = txt + D.2426;
  D.2428 = *D.2427;
  D.2429 = (int) D.2428;
  D.2430 = D.2429 * h;
  D.2431 = t - D.2430;
  D.2432 = D.2431 * 256;
  D.2433 = i + M;
  D.2434 = (sizetype) D.2433;
  D.2435 = txt + D.2434;
  D.2436 = *D.2435;
  D.2437 = (int) D.2436;
  D.2438 = D.2432 + D.2437;
  t = D.2438 % q;
  if (t < 0) goto <D.2439>; else goto <D.2440>;
  <D.2439>:
  t = t + q;
  <D.2440>:
  <D.2425>:
  i = i + 1;
  <D.2386>:
  D.2441 = N - M;
  if (D.2441 >= i) goto <D.2385>; else goto <D.2387>;
  <D.2387>:
  return;
}



;; Function main (main, funcdef_no=1, decl_uid=2388, symbol_order=1)

main ()
{
  int q;
  char pat[5];
  char txt[16];
  int D.2442;

  txt = "GEEKS FOR GEEKS";
  pat = "GEEK";
  q = 101;
  search (&pat, &txt, q);
  D.2442 = 0;
  goto <D.2444>;
  <D.2444>:
  txt = {CLOBBER};
  pat = {CLOBBER};
  goto <D.2443>;
  <D.2443>:
  return D.2442;
}


