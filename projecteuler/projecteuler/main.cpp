#include <stdio.h>
extern void p1();
extern void p2();
extern void p3();
extern void p4();
extern void p8();
#define P1 0
#define P2 0
#define P3 1
#define P4 0
#define P8 0
int main()
{
#if (P1 == 1)
	p1();
#endif
#if (P2 == 1)
	p2();
#endif
#if (P3 == 1)
	p3();
#endif
#if (P4 == 1)
	p4();
#endif
#if (P8 == 1)
	p8();
#endif

	while (1);
}