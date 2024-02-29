
//startup.c
//ENG.Alaa

#include <stdint.h>
#define STACK_Start_sp 0x20001000

extern int main(void);
extern unsigned int _stack_top;

void Reset_Handler();

void Deafault_Handler(void)
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias("Deafault_Handler")));;

void H_Fault_Handler(void) __attribute__((weak,alias("Deafault_Handler")));;

void NM_Fault_Handler(void) __attribute__((weak,alias("Deafault_Handler")));;

void Bus_Fault(void) __attribute__((weak,alias("Deafault_Handler")));;

void Usage_Fault_Handler(void) __attribute__((weak,alias("Deafault_Handler")));;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t)   &_stack_top,
	(uint32_t)  &Reset_Handler,
	(uint32_t)  &NMI_Handler,
	(uint32_t)  &H_Fault_Handler,
	(uint32_t)  &NM_Fault_Handler,
	(uint32_t)  &Bus_Fault,
	(uint32_t)  &Usage_Fault_Handler
	
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
