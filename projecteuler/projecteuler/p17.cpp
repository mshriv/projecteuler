#include <stdio.h>
#include <string.h>

int hundred()
{
	static unsigned long len = -1;

	if (len != -1)
		return len;

	unsigned long len10 = strlen("one") + strlen("two")
		+ strlen("three") + strlen("four")
		+ strlen("five") + strlen("six")
		+ strlen("seven") + strlen("eight")
		+ strlen("nine");

	unsigned long len20 = strlen("eleven") + strlen("twelve")
		+ strlen("thirteen") + strlen("fourteen")
		+ strlen("fifteen") + strlen("sixteen")
		+ strlen("seventeen") + strlen("eighteen")
		+ strlen("nineteen");

	unsigned long twenty = strlen("twenty");
	unsigned long thirty = strlen("thirty");
	unsigned long forty = strlen("forty");
	unsigned long fifty = strlen("fifty");
	unsigned long sixty = strlen("sixty");
	unsigned long seventy = strlen("seventy");
	unsigned long eighty = strlen("eighty");
	unsigned long ninety = strlen("ninety");
	

	unsigned long len100 = len10 * 9 + strlen("ten") + len20
		+ twenty * 10 + thirty * 10 + forty * 10 + fifty * 10 + sixty * 10 + seventy * 10
		+ eighty * 10 + ninety * 10;

	len = len100;
}


void p17()
{
	unsigned long hundred1 = strlen("onehundred");
	unsigned long hundred2 = strlen("twohundred");
	unsigned long hundred3 = strlen("threehundred");
	unsigned long hundred4 = strlen("fourhundred");
	unsigned long hundred5 = strlen("fivehundred");
	unsigned long hundred6 = strlen("sixhundred");
	unsigned long hundred7 = strlen("sevenhundred");
	unsigned long hundred8 = strlen("eighthundred");
	unsigned long hundred9 = strlen("ninehundred");
	unsigned long and = strlen("and");
	unsigned len100 = hundred();

	unsigned len = 10 * len100 + 100 * hundred1 + 100 * hundred2 + 100 * hundred3 + 100 * hundred4
		+ 100 * hundred5 + 100 * hundred6 + 100 * hundred7 + 100 * hundred8 + 100 * hundred9 + 9 * 99 * and + strlen("onethousand");


	printf("%lu", len);
	while (1);
}