#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"
#include "sys/time.h"
#include <sys/resource.h>
#include <unistd.h>

double diffTimeval(struct timeval *t1, struct timeval *t2) {
  double d = (t1->tv_sec - t2->tv_sec) + (1.0e-6 * (t1->tv_usec - t2->tv_usec));
  return d;
}

void getutime(struct timeval *t)
{
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  *t = usage.ru_utime;
}

int main() 
{

  void *p1, *p2, *p3, *p4;
  arenaCheck();
  p1 = bestFitAllocRegion(100);
  printf("---1) allocated p1=%p\n", p1-8);
  arenaCheck();
  p2 = bestFitAllocRegion(50);
  printf("---2) allocated p2=%p\n", p2-8);
  arenaCheck();
  p3 = bestFitAllocRegion(100);
  printf("---3) allocated p3=%p\n", p3-8);
  arenaCheck();
  
  printf("--- freeing p2\n" );
  freeRegion(p2);
  arenaCheck();
  
  p3 = bestFitAllocRegion(30);
  printf("---4) allocated p4=%p\n", p3-8);
  arenaCheck();
  freeRegion(p3);
  arenaCheck();
  freeRegion(p1);
  arenaCheck();
  freeRegion(p4);
  arenaCheck();
  {				// measure time for 10000 mallocs
    struct timeval t1, t2;
    int i;
    getutime(&t1);
    for(i = 0; i < 10000; i++)
      if (bestFitAllocRegion(4) == 0) 
	break;
    getutime(&t2);
    printf("%d bestFitAllocRegion(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
  }
  return 0;
  
    
    /*
    void *p1, *p2, *p3;
    arenaCheck();
    p1 = bestFitAllocRegion(254);
    arenaCheck();
    */
  
}



