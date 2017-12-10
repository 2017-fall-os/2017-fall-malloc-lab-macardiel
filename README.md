# FALL 2017 OS - malloc lab
# Marco Antonio Cardiel

This directory contains:

myAllocator.c: first-fit and best-fit allocators
myAllocator.h: header file

myAllocatorTest1.c: a test program first-fit (provided)
bestFitTest1.c: a test program for my best-fit allocator
resizeTest1.c: a test program for the resize function

malloc.c: a replacement for malloc that uses my allocator
test1.c: a test program that uses this replacement malloc

addendum:
    The implementation of best-fit follows the idea that when
    allocating a certain amount of memory, you should allocate to one that
    either has the exact amount or find the largest block of unallocated 
    memory, as this reduces fragmentation; if you allocate to a block that
    is only slightly greater than the requested amount, you will end up
    with a chunk that may be too small to allocate anything to it, resulting
    in unused space, thus fragmenting memory.

    Regarding resize, the idea of improving the original implementation
    came from first alligning the requested amount by 8. The provided
    situations were usefull, but for the missing case where you have an 
    adjacent free block, you need to "fuse" them (r+s), it is a function of
    the requested amount + constant size of pre/suffix - current amount used.

There are two different testers as some implementations of printf
call malloc to allocate buffer space. This causes test1 to behave
improperly as it uses myAllocator as a malloc replacement. In this
case myAllocatorTest1 will function correctly. The only difference
between the programs is that test1 uses myAllocator as a malloc
replacement and myAllocatorTest1 uses myAllocator directly.

Makefile: a fairly portable "makefile", targets "all" and "clean"

To compile: 
 $ make 
To clean:
 $ make clean

The cygwin runtime uses malloc() and brk() extensively.  It is
interesting to compare the output of test1 & myAllocatorTest1.  All
those extra allocated regions are being used by cygwin's libraries!

Discussion of implementation and algorithms was had amongst author and the following colleagues:
    Edward Seymour (Resize and mechanisms of provided code)
    Daniel Pacheco (best fit, next fit, and algorithms)
    Jesus Padilla (best fit algorithms and C synthax)
    
Thank you!
    

