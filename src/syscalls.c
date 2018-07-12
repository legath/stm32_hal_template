#include <sys/types.h>
#define	ENOMEM 12
volatile extern int errno;
volatile extern int  _heap;
volatile extern int  _eheap;

caddr_t _sbrk ( int incr )
{
  static unsigned char *heap = NULL;
  static unsigned char *eheap = NULL;
  unsigned char *prev_heap;

  if (heap == NULL)
    heap = (unsigned char *)&_heap;

  if(heap+incr>(unsigned char *)&_eheap || heap+incr<(unsigned char *)&_heap)
  {
    errno = ENOMEM;
    return (caddr_t)-1;
  }
  prev_heap = heap;
  heap += incr;
  return (caddr_t) prev_heap;
}

/* --------------------------------- End Of File ------------------------------ */
