#ifndef _GATE_H_
#define _GATE_H_

inline void setIntrGate(unsigned int n, unsigned char ist, void *addr) {
    _set_gate(IDT_Table + n, 0x8E, ist, addr);
}

inline void setTrapGate(unsigned int n, unsigned char ist, void *addr) {
    _set_gate(IDT_Table + n, 0x8F, ist, addr);
}

inline void setSystemGate(unsigned int n, unsigned char ist, void *addr) {
    _set_gate(IDT_Table + n, 0xEF, ist, addr);
}

#define _set_gate(gate_selector_addr, attr, ist, code_addr)                 \
do {                                                                        \
    unsigned long _d0,_di;                                                  \
    __asm__ __volatile__(  "movw  %%dx,  %%ax   \n\t"                      \
                            "andq  $0x7,  %%rcx  \n\t"                      \
                            "addq  %4,    %%rcx  \n\t"                      \
                            "shlq  $32,   %%rcx  \n\t"                      \
                            "addq  %%rcx, %%rax  \n\t"                      \
                            "xorq  %%rcx, %%rcx  \n\t"                      \
                            "movl  %%edx, %%ecx  \n\t"                      \
                            "shrq  $16,   %%rcx  \n\t"                      \
                            "shlq  $48    %%rcx  \n\t"                      \
                            "addq  %%rcx, %%rax  \n\t"                      \
                            "movq  %%rax, %0     \n\t"                      \
                            "shrq  $32,   %%rdx  \n\t"                      \
                            "movq  %%rdx  %1     \n\t"                      \
                            :"=m"(*((unsigned long)(gate_selector_addr))),  \
                            "=m"(*(1 + (unsigned long *)(gate_selector_addr
                            ))),"=&a"(_d0), "=&d"(_d1)                      \
                            :"i"(attr << 8),                                \
                            "3"((unsigned long *)(code_addr)),"2"(0x8 << 
                            16),"c"(ist)                                    \
                            :"memory"                                       \
                        );                                                  \ 

} while(0)

void setTss64(unsigned int * Table,unsigned long rsp0,unsigned long rsp1,unsigned long rsp2,unsigned long ist1,unsigned long ist2,unsigned long ist3,
unsigned long ist4,unsigned long ist5,unsigned long ist6,unsigned long ist7)
{
	*(unsigned long *)(Table+1) = rsp0;
	*(unsigned long *)(Table+3) = rsp1;
	*(unsigned long *)(Table+5) = rsp2;

	*(unsigned long *)(Table+9) = ist1;
	*(unsigned long *)(Table+11) = ist2;
	*(unsigned long *)(Table+13) = ist3;
	*(unsigned long *)(Table+15) = ist4;
	*(unsigned long *)(Table+17) = ist5;
	*(unsigned long *)(Table+19) = ist6;
	*(unsigned long *)(Table+21) = ist7;	
}

#define loadTR(n) 							\
do{									\
	__asm__ __volatile__(	"ltr	%%ax"				\
				:					\
				:"a"(n << 3)				\
				:"memory");				\
}while(0)
#endif