#include <MKL25Z4.h>
# include "string.h"
#define Mask(n) (1UL<<n)

void UART0_init(void);
void DELAY(int);
int main (void) {
int k,i,n; 
char Names[] = "Sahlah and Aaminah \r\n";
char IDs[] = "ID is 61200 and 61415 \r\n";

UART0_init(); //calling the UART0 function.

//Enabling the clock of port B and port E
SIM_SCGC5 |= SIM_SCGC5_PORTE(1);  
SIM_SCGC5 |=SIM_SCGC5_PORTB(1) ; 

//Setting pins as GPIO
PORTB_PCR0 |= PORT_PCR_MUX(1);    /* make PTB0 pin as GPIO */
PORTB_PCR1 |= PORT_PCR_MUX(1);    /* make PTB1 pin as GPIO */
PORTB_PCR2 |= PORT_PCR_MUX(1);    /* make PTB2 pin as GPIO */
PORTB_PCR3 |= PORT_PCR_MUX(1);    /* make PTB3 pin as GPIO */

PORTE_PCR0 |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK; /* PTE0 pin as GPIO, and Pull Enable*/
PORTE_PCR1 |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK;  /* PTE1 pin as GPIO, and Pull Enable */
PORTE_PCR2 |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK;   /*PTE2 pin as GPIO, and Pull Enable */
PORTE_PCR3 |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK;  /*PTE3 pin as GPIO, and Pull Enable */

//Setting the direction of port B as output 
GPIOB_PDDR |= Mask(0); 
GPIOB_PDDR |= Mask(1); 
GPIOB_PDDR |= Mask(2); 
GPIOB_PDDR |= Mask(3); 	

//Setting the direction of port E as input
//GPIOE_PDDR |=0;
GPIOE_PDDR &=~Mask(0);   
GPIOE_PDDR &=~Mask(1);   
GPIOE_PDDR &=~Mask(2);   
GPIOE_PDDR &=~Mask(3);   


while (1){ //start of infinite loop
///////////////////ROW 1///////////////////////
//R1=0, R2=1, R3=1, R4=1: 
GPIOB_PDOR &= ~Mask(0); //set the pin 0 of port B to 0 
GPIOB_PDOR |= Mask(1); //set the pin 1 of port B to 1 
GPIOB_PDOR |= Mask(2); //set the pin 2 of port B to 1 
GPIOB_PDOR |= Mask(3); //set the pin 3 of port B to 1 

	
//If C1=0, C2=1, C3=1, C4=1 
if((GPIOE_PDIR & Mask(0))==0){
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
UART0_D = '1'; }//Then transmit the number 1	

//If C1=1, C2=0, C3=1, C4=1	
if ((GPIOE_PDIR & Mask(1))==0){
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
UART0_D ='2'; 	//Then transmit the number 2	
}//END OF IF C =0D

//If C1=1, C2=1, C3=0, C4=1	
if ((GPIOE_PDIR & Mask(2))==0){  
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
UART0_D = '3'; 	//Then transmit the number 3	
}//END OF IF C=0B

//If C1=1, C2=1, C3=1, C4=0
if ((GPIOE_PDIR & Mask(3))==0){  
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
UART0_D = 'A'; 	//Then transmit the number A		
}// END OF C=07
			
///////////////////ROW 2//////////////////////////			
//DELAY(1);		
//R1=1, R2=0, R3=1, R4=1: 
GPIOB_PDOR |= Mask(0); //set the pin 0 of port B to 1 
GPIOB_PDOR &= ~Mask(1); //set the pin 1 of port B to 0 
GPIOB_PDOR |= Mask(2); //set the pin 2 of port B to 1 
GPIOB_PDOR |= Mask(3); //set the pin 3 of port B to 1 
//DELAY(1); 									
//If C1=0, C2=1, C3=1, C4=1
if ((GPIOE_PDIR & Mask(0))==0){
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = '4'; 		//Then transmit the number 0x04
		}

//If C1=1, C2=0, C3=1, C4=1
if ((GPIOE_PDIR & Mask(1))==0){
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = '5'; 		//Then transmit the number 5
}
//If C1=1, C2=1, C3=0, C4=1	
if ((GPIOE_PDIR & Mask(2))==0){  
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = '6'; 		//Then transmit the number 6
}
//If C1=1, C2=1, C3=1, C4=0
if ((GPIOE_PDIR & Mask(3))==0){
	while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = 'B'; 		//Then transmit B
		}

///////////////	ROW 3////////////////////
//DELAY(1);			
//R1=1, R2=1, R3=0, R4=1: 

GPIOB_PDOR |= Mask(0); //set the pin 0 of port B to 1 
GPIOB_PDOR |= Mask(1); //set the pin 1 of port B to 1 
GPIOB_PDOR &= ~Mask(2); //set the pin 2 of port B to 0 
GPIOB_PDOR |= Mask(3); //set the pin 3 of port B to 1 
//DELAY(1); 								
//If C1=0, C2=1, C3=1, C4=1
if ((GPIOE_PDIR & Mask(0))==0){
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = '7'; 		//Then transmit the number 7
}
DELAY(1);
//If C1=1, C2=0, C3=1, C4=1
if ((GPIOE_PDIR & Mask(1))==0){
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = '8'; 		//Then transmit the number 8
}
//If C1=1, C2=1, C3=0, C4=1	
if ((GPIOE_PDIR & Mask(2))==0){  
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = '9'; 		//Then transmit the number 9
}
//DELAY(1);
//If C1=1, C2=1, C3=1, C4=0
if ((GPIOE_PDIR & Mask(3))==0){
	while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = 'C'; 		//Then transmit C
}
//DELAY(1);
////////////////ROW 4//////////////////////		
//R1=1, R2=1, R3=1, R4=0: 
GPIOB_PDOR |= Mask(0); //set the pin 0 of port B to 1 
GPIOB_PDOR |= Mask(1); //set the pin 1 of port B to 1 
GPIOB_PDOR |= Mask(2); //set the pin 2 of port B to 1 
GPIOB_PDOR &= ~Mask(3); //set the pin 3 of port B to 0 

//DELAY(1); 								
//If C1=0, C2=1, C3=1, C4=1
if ((GPIOE_PDIR & Mask(0))==0){ 
	for (k=0; k<strlen(Names); k++){// Start a for loop to iterate over the ID characters
	while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
		UART0_D = Names[k]; // Sends the current character of the ID string UART0_D, which will transmit it.
		DELAY(1);
		}		
}

//If C1=1, C2=0, C3=1, C4=1
if ((GPIOE_PDIR & Mask(1))==0){
while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = '0'; 		//Then transmit the number 0
}
//If C1=1, C2=1, C3=0, C4=1	
if ((GPIOE_PDIR & Mask(2))==0){ 
	for (i=0; i<strlen(IDs); i++){// Start a for loop to iterate over the ID characters
	while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
		UART0_D = IDs[i]; // Sends the current character of the ID string UART0_D, which will transmit it.
		DELAY(1);
		}		
}
//If C1=1, C2=1, C3=1, C4=0
if ((GPIOE_PDIR & Mask(3))==0){
	while((UART0_S1 & UART0_S1_TDRE(1))==0) {}  
	UART0_D = 'D'; 		//Then transmit the number D
		}// 
}//WHILE LOOP
}//MAIN LOOP
void DELAY(int n) {
  int i,j;
for(i = 0 ; i < n; i++)
for (j = 0; j < 3495000; j++) {}
}
void UART0_init(void)
         {        
        MCG_C1 |= MCG_C1_CLKS(0);     /*Select PLL/FLL as clock source*/
        MCG_C1 |= MCG_C1_IREFS(1);    /*Select Inernal Reference clock, source for FLL*/
        MCG_C4 |= MCG_C4_DRST_DRS(1); /* Select DCO range as Mid range, DCO generates the FLL Clock*/
        MCG_C4 |= MCG_C4_DMX32(1);    /* Select DCO frequency as 48Mhz*/                      
  SIM_SCGC4 |=SIM_SCGC4_UART0(1);                    /* enable clock for UART0 */
        SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1); /* use FLL output for UART Baud rate generator   */
        SIM_SCGC5 |= SIM_SCGC5_PORTA(1);   /* Enable PORTA clock*
        PORTA_PCR1 |=  PORT_PCR_MUX(2); /* PTA1 as ALT2 (UART0) for Receive Rx enable */
        PORTA_PCR2 |=  PORT_PCR_MUX(2);  /* PTA2 as ALT2 (UART0) for Transmit Tx enable */
        UART0_C4 = 0x0F;               /* Set Over Sampling Ratio as 16 (15+1) */
        UART0_BDH = 0x01;
        UART0_BDL = 0x38;      /* Set 9600 as Baudrate */
        UART0_C1  = 0x00; /* Configure Serial Port as 8-N-1 (8 data bits, No parity and 1 stop bit) */     
        UART0_C2  |= UART_C2_TE(1);  /*Transmit Tx Enabled */
        UART0_C2  |= UART_C2_RE(1);  /* Receive Rx Enabled */

               }
