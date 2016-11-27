#include <stdio.h>
extern void p1();
extern void p2();
extern void p3();
extern void p4();
extern void p8();
extern void p9();
extern void p10();
extern void p12();
extern void p48();
extern void p49();
extern void p50();
#define P1 0
#define P2 0
#define P3 0
#define P4 0
#define P8 0
#define P9 0
#define P10 0
#define P12 1
#define P48 0
#define P49 0
#define P50 0
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
#if (P9 == 1)
	p9();
#endif
#if (P10 == 1)
	p10();
#endif
#if (P12 == 1)
	p12();
#endif
#if (P48 == 1)
	p48();
#endif
#if (P49 == 1)
	p49();
#endif
#if (P50 == 1)
	p50();
#endif

	while (1);
}