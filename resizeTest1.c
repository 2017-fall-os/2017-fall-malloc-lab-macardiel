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
  p1 = resizeRegion( (void *) 0, 32 );
  
  printf( "1) initial p1: %p\n", p1-8 );
  arenaCheck();
  
  printf( "Testing Old Size is large enough (given case)\n" );\
  arenaCheck();
  p1 = realloc(p1, 16);
  printf( "2) p1: %p\n", p1 );
  arenaCheck();
  
  return 0;
}



