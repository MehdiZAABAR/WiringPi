#ifndef _ORANGEPI_H
#define _ORANGEPI_H

#if defined ( CONFIG_ORANGEPI_2G_IOT) || defined (CONFIG_ORANGEPI_I96)
/********** OrangePi 2G-IOT *************/

#define PROT_READ	0x1		/* Page can be read.  */
#define PROT_WRITE	0x2		/* Page can be written.  */
#define PROT_EXEC	0x4		/* Page can be executed.  */
#define PROT_NONE	0x0		/* Page can not be accessed.  */
#define MAP_SHARED	0x01		/* Share changes.  */
#define RDA_IO_MUX_REG_BASE_ADDR	0x11A09000
#define RDA_IO_MUX_PORTA_ADDR 		0x11A0900C
#define RDA_IO_MUX_PORTB_ADDR 		0x11A09010
#define RDA_IO_MUX_PORTC_ADDR 		0x11A09008
#define RDA_IO_MUX_PORTD_ADDR 		0x11A09014
#define PG_SIZE						4096

/********* local data ************/
#define GPIOA_BASE                         0x20930000
#define GPIOB_BASE                         0x20931000
#define GPIOC_BASE                         0x11A08000
#define GPIOD_BASE                         0x20932000
#define GPIO_NUM                           (0x80)
#define GPIO_BIT(x)                        (1UL << (x))

#define OEN_VAL_REGISTER                   (0x00)
#define OEN_SET_OUT_REGISTER               (0x04)
#define SET_IN_REGISTER                    (0x08)
#define VAL_REGISTER                       (0x0C)
#define SET_REGISTER                       (0x10)
#define CLR_REGISTER                       (0x14)

#define MEM_INFO                           (512)
#define MAP_SIZE_L                         (4 * 4096)

#endif /* CONFIG_ORANGEPI_2G_IOT */

#ifdef CONFIG_ORANGEPI_PC2
/************** OrangePi H5 ***********************/
#define GPIOA_BASE                         (0x01C20000)
#define GPIO_NUM                           (0x40)
#define GPIO_BASE_MAP                      (0x01C20800)
#define MEM_INFO                           (1024)
#define MAP_SIZE_L                         (4096 * 2)
#endif

/************** OrangePi A64 ***********************/
#ifdef CONFIG_ORANGEPI_A64
#define GPIOA_BASE                         (0x01C20000)
#define GPIO_NUM                           (0x40)
#define GPIO_BASE_MAP                      (0x01C20800)
#define MEM_INFO                           (1024)
#define GPIOL_BASE                         (0x01F02c00)
#define GPIOL_BASE_MAP                     (0x01F02000)  
#define MAP_SIZE_L                         (4096 * 2)
#endif

/************** OrangePi H3 ***********************/
#ifdef CONFIG_ORANGEPI_H3
#define GPIOA_BASE                         (0x01C20000)
#define GPIO_NUM                           (0x40)
#define GPIO_BASE_MAP                      (0x01C20800)
#define MEM_INFO                           (1024)
#define MAP_SIZE_L                         (4096 * 2)
#endif

/************** OrangePi Zero ***********************/
#ifdef CONFIG_ORANGEPI_ZERO
#define GPIOA_BASE                         (0x01C20000)
#define GPIO_NUM                           (0x40)
#define GPIO_BASE_MAP                      (0x01C20800)
#define MEM_INFO                           (1024)
#define MAP_SIZE_L                         (4096 * 2)
#endif

/****************** Global data *********************/
/* Current version */
#define PI_MAKER_ORANGEPI  4
#define MAX_PIN_NUM        GPIO_NUM
#define MAP_SIZE           MAP_SIZE_L
#define MAP_MASK           (MAP_SIZE - 1)
#define PI_GPIO_MASK       (~(GPIO_NUM - 1))
#define GPIO_BASE          GPIOA_BASE
#define ORANGEPI_MEM_INFO  MEM_INFO

#ifdef CONFIG_ORANGEPI_I96
	#define PIN_ARRAY_SZ 133
#else
	#define PIN_ARRAY_SZ 64
#endif
extern int pinToGpioOrangePi[PIN_ARRAY_SZ];
extern int physToGpioOrangePi[64];
extern int physToPinOrangePi[PIN_ARRAY_SZ];
extern int physToWpiOrangePi[PIN_ARRAY_SZ];
extern volatile uint32_t *OrangePi_gpio;
extern volatile uint32_t *OrangePi_gpioC;

extern unsigned int readR(unsigned int addr);
extern void writeR(unsigned int val, unsigned int addr);
extern int OrangePi_set_gpio_mode(int pin, int mode);
extern int isOrangePi_2G_IOT(void);
extern int isOrangePi(void);
extern unsigned int readR(unsigned int addr);
extern void writeR(unsigned int val, unsigned int addr);
extern int OrangePi_digitalWrite(int pin, int value);
extern int OrangePi_digitalRead(int pin);
int RDA8810_GetPinModeInOutAlt(int pin);
void UnmapIoMuxReg();
unsigned int *MmapIoMuxReg();
unsigned int IoMuxReadReg( unsigned int addr);

#ifdef CONFIG_ORANGEPI
extern const char *piModelNames[6];
extern unsigned int *IoMuxMappedAddr;
#endif

#if defined ( CONFIG_ORANGEPI_2G_IOT) || defined (CONFIG_ORANGEPI_I96)
extern int ORANGEPI_PIN_MASK[4][32];
#elif CONFIG_ORANGEPI_PC2
extern int ORANGEPI_PIN_MASK[9][32];
#elif CONFIG_ORANGEPI_A64
extern int ORANGEPI_PIN_MASK[12][32];
#elif CONFIG_ORANGEPI_H3
extern int ORANGEPI_PIN_MASK[9][32];
#elif CONFIG_ORANGEPI_ZERO
extern int ORANGEPI_PIN_MASK[12][32];
#endif
#endif
