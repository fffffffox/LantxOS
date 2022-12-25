#include "trap.h"
#include "gate.h"

/*

*/

void do_divide_error(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_divide_error(0),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_debug(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_debug(1),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_nmi(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_nmi(2),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_int3(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_int3(3),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_overflow(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_overflow(4),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_bounds(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_bounds(5),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_undefined_opcode(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_undefined_opcode(6),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_dev_not_available(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_dev_not_available(7),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_double_fault(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_double_fault(8),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_coprocessor_segment_overrun(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_coprocessor_segment_overrun(9),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_invalid_TSS(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_invalid_TSS(10),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);

	if(error_code & 0x01)
		colorPrint(RED,BLACK,"The exception occurred during delivery of an event external to the program,such as an interrupt or an earlier exception.\n");

	if(error_code & 0x02)
		colorPrint(RED,BLACK,"Refers to a gate descriptor in the IDT;\n");
	else
		colorPrint(RED,BLACK,"Refers to a descriptor in the GDT or the current LDT;\n");

	if((error_code & 0x02) == 0)
		if(error_code & 0x04)
			colorPrint(RED,BLACK,"Refers to a segment or gate descriptor in the LDT;\n");
		else
			colorPrint(RED,BLACK,"Refers to a descriptor in the current GDT;\n");

	colorPrint(RED,BLACK,"Segment Selector Index:%#010x\n",error_code & 0xfff8);

	while(1);
}

/*

*/

void do_segment_not_present(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_segment_not_present(11),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);

	if(error_code & 0x01)
		colorPrint(RED,BLACK,"The exception occurred during delivery of an event external to the program,such as an interrupt or an earlier exception.\n");

	if(error_code & 0x02)
		colorPrint(RED,BLACK,"Refers to a gate descriptor in the IDT;\n");
	else
		colorPrint(RED,BLACK,"Refers to a descriptor in the GDT or the current LDT;\n");

	if((error_code & 0x02) == 0)
		if(error_code & 0x04)
			colorPrint(RED,BLACK,"Refers to a segment or gate descriptor in the LDT;\n");
		else
			colorPrint(RED,BLACK,"Refers to a descriptor in the current GDT;\n");

	colorPrint(RED,BLACK,"Segment Selector Index:%#010x\n",error_code & 0xfff8);

	while(1);
}

/*

*/

void do_stack_segment_fault(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_stack_segment_fault(12),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);

	if(error_code & 0x01)
		colorPrint(RED,BLACK,"The exception occurred during delivery of an event external to the program,such as an interrupt or an earlier exception.\n");

	if(error_code & 0x02)
		colorPrint(RED,BLACK,"Refers to a gate descriptor in the IDT;\n");
	else
		colorPrint(RED,BLACK,"Refers to a descriptor in the GDT or the current LDT;\n");

	if((error_code & 0x02) == 0)
		if(error_code & 0x04)
			colorPrint(RED,BLACK,"Refers to a segment or gate descriptor in the LDT;\n");
		else
			colorPrint(RED,BLACK,"Refers to a descriptor in the current GDT;\n");

	colorPrint(RED,BLACK,"Segment Selector Index:%#010x\n",error_code & 0xfff8);

	while(1);
}

/*

*/

void do_general_protection(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_general_protection(13),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);

	if(error_code & 0x01)
		colorPrint(RED,BLACK,"The exception occurred during delivery of an event external to the program,such as an interrupt or an earlier exception.\n");

	if(error_code & 0x02)
		colorPrint(RED,BLACK,"Refers to a gate descriptor in the IDT;\n");
	else
		colorPrint(RED,BLACK,"Refers to a descriptor in the GDT or the current LDT;\n");

	if((error_code & 0x02) == 0)
		if(error_code & 0x04)
			colorPrint(RED,BLACK,"Refers to a segment or gate descriptor in the LDT;\n");
		else
			colorPrint(RED,BLACK,"Refers to a descriptor in the current GDT;\n");

	colorPrint(RED,BLACK,"Segment Selector Index:%#010x\n",error_code & 0xfff8);

	while(1);
}

/*

*/

void do_page_fault(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	unsigned long cr2 = 0;

	__asm__	__volatile__("movq	%%cr2,	%0":"=r"(cr2)::"memory");

	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_page_fault(14),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);

	if(!(error_code & 0x01))
		colorPrint(RED,BLACK,"Page Not-Present,\t");

	if(error_code & 0x02)
		colorPrint(RED,BLACK,"Write Cause Fault,\t");
	else
		colorPrint(RED,BLACK,"Read Cause Fault,\t");

	if(error_code & 0x04)
		colorPrint(RED,BLACK,"Fault in user(3)\t");
	else
		colorPrint(RED,BLACK,"Fault in supervisor(0,1,2)\t");

	if(error_code & 0x08)
		colorPrint(RED,BLACK,",Reserved Bit Cause Fault\t");

	if(error_code & 0x10)
		colorPrint(RED,BLACK,",Instruction fetch Cause Fault");

	colorPrint(RED,BLACK,"\n");

	colorPrint(RED,BLACK,"CR2:%#018lx\n",cr2);

	while(1);
}

/*

*/

void do_x87_FPU_error(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_x87_FPU_error(16),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_alignment_check(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_alignment_check(17),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_machine_check(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_machine_check(18),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_SIMD_exception(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_SIMD_exception(19),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void do_virtualization_exception(unsigned long rsp,unsigned long error_code) {
	unsigned long * p = NULL;
	p = (unsigned long *)(rsp + 0x98);
	colorPrint(RED,BLACK,"do_virtualization_exception(20),ERROR_CODE:%#018lx,RSP:%#018lx,RIP:%#018lx\n",error_code , rsp , *p);
	while(1);
}

/*

*/

void sysVectorInit() {
	setTrapGate(0,1,divide_error);
	setTrapGate(1,1,debug);
	setIntrGate(2,1,nmi);
	setSystemGate(3,1,int3);
	setSystemGate(4,1,overflow);
	setSystemGate(5,1,bounds);
	setTrapGate(6,1,undefined_opcode);
	setTrapGate(7,1,dev_not_available);
	setTrapGate(8,1,double_fault);
	setTrapGate(9,1,coprocessor_segment_overrun);
	setTrapGate(10,1,invalid_TSS);
	setTrapGate(11,1,segment_not_present);
	setTrapGate(12,1,stack_segment_fault);
	setTrapGate(13,1,general_protection);
	setTrapGate(14,1,page_fault);
	//15 Intel reserved. Do not use.
	setTrapGate(16,1,x87_FPU_error);
	setTrapGate(17,1,alignment_check);
	setTrapGate(18,1,machine_check);
	setTrapGate(19,1,SIMD_exception);
	setTrapGate(20,1,virtualization_exception);

	//setSystemGate(SYSTEM_CALL_VECTOR,7,system_call);

}





