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
  p1 = firstFitAllocRegion(32);
  printf( "\n\n0) initial p1: %p\n", p1-8 );
  arenaCheck();
  
  printf( "\nTesting Old Size is large enough (given case)\n" );\
  arenaCheck();
  p1 = resizeRegion(p1, 16);
  printf( "1) p1: %p\n", p1-8 );
  arenaCheck();
  
  printf("\nTesting Next block is large enough\n" );
  p2 = firstFitAllocRegion(16);
  printf("2.1) p2: %p\n", p2-8);
  freeRegion(p1);
  arenaCheck();
  p2 = resizeRegion(p2, 40);
  printf("2.2) p2: %p\n", p2-8);
  arenaCheck();
  
  return 0;
}



