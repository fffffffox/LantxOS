#include "lib.h"
#include "printk.h"
#include "gate.h"
#include "trap.h"


void lxKrnlMain(void)
{
	int *addr = (int *)0xffff800000a00000;
	int i;

	pos.xResolution = 1440;
	pos.yResolution = 900;

	pos.xPosition = 0;
	pos.yPosition = 0;

	pos.xCharSize = 8;
	pos.yCharSize = 16;

	pos.FB_addr = (int *)0xffff800000a00000;
	pos.FB_length = (pos.xResolution * pos.yResolution * 4);

	colorPrint(WHITE,BLACK,"Starting...");

	colorPrint(WHITE,BLACK,"Loading TR:8");
	loadTR(8);

	colorPrint(WHITE,BLACK,"Set TSS64");
	setTss64(
		0xffff800000007c00,
		0xffff800000007c00,
		0xffff800000007c00,
		0xffff800000007c00,
		0xffff800000007c00,
		0xffff800000007c00,
		0xffff800000007c00,
		0xffff800000007c00,
		0xffff800000007c00,
		0xffff800000007c00,
	);

	colorPrint(WHITE,BLACK,"sysVectorInit...");
	sysVectorInit();

	struct globalMemoryDescriptor memoryManagement = {{0},0};

	colorPrint(WHITE,BLACK,"Done");
	while (1)
		;
}
