#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"
#include "sys/time.h"
#include <sys/resource.h>
#include <unistd.h>

int main() 
{
  void *p1, *p2, *p3;
  
  // initial p1
  
  arenaCheck();
  p1 = firstFitAllocRegion(254);
  printf( "1) initial p1: %p\n", p1-8 );
  arenaCheck();
  
  printf( "Testing Old Size is large enough (given case)\n" );\
  arenaCheck();
  p1 = resizeRegion(p1, 15);
  printf( "2) p1: %p\n", p1-8 );
  arenaCheck();
  
  return 0;
}



