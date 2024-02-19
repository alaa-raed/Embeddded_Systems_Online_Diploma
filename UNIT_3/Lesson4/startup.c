
//startup.c
//ENG.Alaa

#include <stdint.h>
#define STACK_Start_sp 0x20001000

extern int main(void);
static unsigned long Stack_top[256];

void Reset_Handler();

void Deafault_Handler(void)
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias("Deafault_Handler")));;

void H_Fault_Handler(void) __attribute__((weak,alias("Deafault_Handler")));;


//booking 1024  allocated by .bss through un intialized array of int 256 element(4*256=1024 Byte)


void (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) =
{
	//3mltlha casting lnfs no3 elfunction (pointer to function return void) 
	//unsigned long -> 3shan admn eno my3mlsh warning fa bmlo casting l unsigned long
	(void(*)())            ((unsigned long)Stack_top+sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler
};

extern unsigned char _E_text;
extern unsigned char _S_DATA;
extern unsigned char _E_DATA;
extern unsigned char _S_bss;
extern unsigned char _E_bss;



void Reset_Handler()
{
    // Copy data section from flash to ram
    unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
    unsigned char* p_src = (unsigned char*)&_E_text;
    unsigned char* p_dst = (unsigned char*)&_S_DATA;

    for (int i = 0; i < DATA_SIZE; i++)
    {
        *(p_dst++) = *(p_src++);
    }

    // Init bss section to 0 in sram
    unsigned int bss_SIZE = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
    p_dst = (unsigned char*)&_S_bss;

    for (int i = 0; i < bss_SIZE; i++)
    {
        *(p_dst++) = 0;
    }

    // Jump to main()
    main();
}
