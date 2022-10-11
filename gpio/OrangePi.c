#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "OrangePi.h"

#ifdef CONFIG_ORANGEPI_I96
char *physNames[64] =
{
		"GND      "
		,"GND      "
		,"UART2.CTS"
		,"PWR_BTN_N"
		,"UART2.TX "
		,"RST_BTN_N"
		,"UART2.RX "
		,"SPI2.CLK "
		,"UART2.RTS"
		,"SPI2.DI  "
		,"UART1.TX "
		,"SPI2.CS1 "
		,"UART1.RX "
		,"SPI2.DO  "
		,"I2C2.SCL "
		,"I2S_LRCK "
		,"I2C2.SDA "
		,"I2S.BCK  "
		,"I2C3.SCL "
		,"I2S.DO   "
		,"I2C3.SDA "
		,"I2S.DI   "
		,"G.A A15  "
		,"G.B A20  "
		,"G.C B24  "
		,"G.D D02  "
		,"G.E D03  "
		,"G.F A22  "
		,"G.G A30  "
		,"G.H A29  "
		,"G.I A28  "
		,"G.J 27   "
		,"G.K A26  "
		,"G.L A25  "
		,"V_PAD    "
		,"SYS_DCIN "
		,"VDD_IN   "
		,"SYS_DCIN "
		,"GND      "
		,"GND      ",
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
};
int physToWpi[64] = {
		-1,
		-1,
		40,
		-1,
		104,
		-1,
		103,
		2,
		41,
		4,
		14,
		6,
		102,
		3, 0, 10,1,9,38,13,39,11,15,20,56,66,67,22,30,29,28,27,26,25,
		-1,-1,-1,-1,-1,-1,
		// Padding:
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,   // ... 56
		-1, -1, -1, -1, -1, -1, -1,   // ... 63
};
#endif

#ifdef CONFIG_ORANGEPI_PC2
int physToWpi[64] =
{
		-1,        // 0
		-1,  -1,   // 1, 2
		8,   -1,   // 3, 4
		9,   -1,   // 5, 6
		7,   15,   // 7, 8
		-1,  16,   // 9, 10
		0,    1,   //11, 12
		2,   -1,   //13, 14
		3,    4,   //15, 16
		-1,   5,   //17, 18
		12,  -1,   //19, 20
		13,   6,   //21, 22
		14,  10,   //23, 24
		-1,  11,   //25, 26
		30,  31,   //27, 28
		21,  -1,   //29, 30
		22,  26,   //31, 32
		23,  -1,   //33, 34
		24,  27,   //35, 36
		25,  28,   //37, 38
		-1,  29,   //39, 40
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
		-1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};

char *physNames[64] =
{
		NULL,

		"    3.3v", "5v      ",
		"   SDA.0", "5V      ",
		"   SCL.0", "0v      ",
		"  GPIO.7", "TxD3    ",
		"      0v", "RxD3    ",
		"    RxD2", "GPIO.1  ",
		"    TxD2", "0v      ",
		"    CTS2", "GPIO.4  ",
		"    3.3v", "GPIO.5  ",
		"    MOSI", "0v      ",
		"    MISO", "RTS2    ",
		"    SCLK", "CE0     ",
		"      0v", "GPIO.11 ",
		"   SDA.1", "SCL.1   ",
		" GPIO.21", "0v      ",
		" GPIO.22", "RTS1    ",
		" GPIO.23", "0v      ",
		" GPIO.24", "CTS1    ",
		" GPIO.25", "TxD1    ",
		"      0v", "RxD1    ",
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		"GPIO.17", "GPIO.18",
		"GPIO.19", "GPIO.20",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_2G_IOT
char *physNames[64] =
{
		NULL,

		"    3.3v", "5v      ",
		"   SDA.0", "5V      ",
		"   SCL.0", "0v      ",
		"  GPIO.7", "TxD2    ",
		"      0v", "RxD2    ",
		"    RxD1", "GPIO.1  ",
		"    TxD1", "0v      ",
		"    CTS1", "GPIO.4  ",
		"    3.3v", "GPIO.5  ",
		" SPI2_DI", "0v      ",
		"SPI2_DIO", "RTS1    ",
		"SPI2_CLK", "SPI2_CS0",
		"      0v", "SPI2_CS1",
		"   SDA.1", "SCL.1   ",
		" GPIO.21", "0v      ",
		" GPIO.22", "RTS2    ",
		" GPIO.23", "0v      ",
		" GPIO.24", "CTS2    ",
		" GPIO.25", "SCL.2   ",
		"      0v", "SDA.2   ",
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};

int physToWpi[64] =
{
		-1,        // 0
		-1,  -1,   // 1, 2
		8,   -1,   // 3, 4
		9,   -1,   // 5, 6
		7,   15,   // 7, 8
		-1,  16,   // 9, 10
		0,    1,   //11, 12
		2,   -1,   //13, 14
		3,    4,   //15, 16
		-1,   5,   //17, 18
		12,  -1,   //19, 20
		13,   6,   //21, 22
		14,  10,   //23, 24
		-1,  11,   //25, 26
		30,  31,   //27, 28
		21,  -1,   //29, 30
		22,  26,   //31, 32
		23,  -1,   //33, 34
		24,  27,   //35, 36
		25,  28,   //37, 38
		-1,  29,   //39, 40
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
		-1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};
#endif

#ifdef CONFIG_ORANGEPI_A64
char *physNames [64] =
{
		NULL,

		"    3.3v", "5v      ",
		"   SDA.1", "5V      ",
		"   SCL.1", "0v      ",
		"  GPIO.7", "S_TX    ",
		"      0v", "S_RX    ",
		"    RxD3", "GPIO.1  ",
		"    TxD3", "0v      ",
		"    CTS3", "GPIO.4  ",
		"    3.3v", "GPIO.5  ",
		"    MOSI", "0v      ",
		"    MISO", "RTS3    ",
		"    SCLK", "CE0     ",
		"      0v", "GPIO.11 ",
		"   SDA.2", "SCL.2   ",
		" GPIO.21", "0v      ",
		" GPIO.22", "RTS2    ",
		" GPIO.23", "0v      ",
		" GPIO.24", "CTS2    ",
		" GPIO.25", "TxD2    ",
		"      0v", "RxD2    ",
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		"GPIO.17", "GPIO.18",
		"GPIO.19", "GPIO.20",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};

int physToWpi [64] =
{
		-1,        // 0
		-1,  -1,   // 1, 2
		8,  -1,   // 3, 4
		9,  -1,   // 5, 6
		7,  15,   // 7, 8
		-1,  16,   // 9, 10
		0,   1,   //11, 12
		2,  -1,   //13, 14
		3,   4,   //15, 16
		-1,   5,   //17, 18
		12,  -1,   //19, 20
		13,   6,   //21, 22
		14,  10,   //23, 24
		-1,  11,   //25, 26
		30,  31,   //27, 28
		21,  -1,   //29, 30
		22,  26,   //31, 32
		23,  -1,   //33, 34
		24,  27,   //35, 36
		25,  28,   //37, 38
		-1,  29,   //39, 40
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
		-1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};
#endif

#ifdef CONFIG_ORANGEPI_H3
int physToWpi[64] =
{
		-1,        // 0
		-1,  -1,   // 1, 2
		8,  -1,   // 3, 4
		9,  -1,   // 5, 6
		7,  15,   // 7, 8
		-1,  16,   // 9, 10
		0,   1,   //11, 12
		2,  -1,   //13, 14
		3,   4,   //15, 16
		-1,   5,   //17, 18
		12,  -1,   //19, 20
		13,   6,   //21, 22
		14,  10,   //23, 24
		-1,  11,   //25, 26
		30,  31,   //27, 28
		21,  -1,   //29, 30
		22,  26,   //31, 32
		23,  -1,   //33, 34
		24,  27,   //35, 36
		25,  28,   //37, 38
		-1,  29,   //39, 40
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
		-1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};

char *physNames[64] =
{
		NULL,

		"    3.3v", "5v      ",
		"   SDA.0", "5V      ",
		"   SCL.0", "0v      ",
		"  GPIO.7", "TxD3    ",
		"      0v", "RxD3    ",
		"    RxD2", "GPIO.1  ",
		"    TxD2", "0v      ",
		"    CTS2", "GPIO.4  ",
		"    3.3v", "GPIO.5  ",
		"    MOSI", "0v      ",
		"    MISO", "RTS2    ",
		"    SCLK", "CE0     ",
		"      0v", "GPIO.11 ",
		"   SDA.1", "SCL.1   ",
		" GPIO.21", "0v      ",
		" GPIO.22", "RTS1    ",
		" GPIO.23", "0v      ",
		" GPIO.24", "CTS1    ",
		" GPIO.25", "TxD1    ",
		"      0v", "RxD1    ",
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		"GPIO.17", "GPIO.18",
		"GPIO.19", "GPIO.20",
		NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
};
#endif

#ifdef CONFIG_ORANGEPI_ZERO
int physToWpi [64] =
{
		-1,        // 0

		-1,  -1,   // 1, 2
		8,  -1,   // 3, 4
		9,  -1,   // 5, 6
		7,  15,   // 7, 8
		-1,  16,   // 9, 10
		0,   1,   //11, 12
		2,  -1,   //13, 14
		3,   4,   //15, 16
		-1,   5,   //17, 18
		12,  -1,   //19, 20
		13,   6,   //21, 22
		14,  10,   //23, 24
		-1,  11,   //25, 26

		30,  -1,   //27, 28

		-1,  -1,   //29, 30
		-1,  -1,   //31, 32
		-1,  -1,   //33, 34
		-1,  -1,   //35, 36
		-1,  -1,   //37, 38
		-1,  -1,   //39, 40
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //41-> 55
		-1, -1, -1, -1, -1, -1, -1, -1 // 56-> 63
};

char *physNames[64] =
{
		NULL,

		"    3.3v", "5v      ",
		"   SDA.0", "5V      ",
		"   SCL.0", "0v      ",
		"  GPIO.7", "TxD3    ",
		"      0v", "RxD3    ",
		"    RxD2", "GPIO.1  ",
		"    TxD2", "0v      ",
		"    CTS2", "GPIO.4  ",
		"    3.3v", "GPIO.5  ",
		"    MOSI", "0v      ",
		"    MISO", "RTS2    ",
		"    SCLK", "CE0     ",
		"      0v", "GPIO.11 ",

		"STAT-LED", "PWR-LED ",

		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL, NULL,
		NULL,
};
#endif
/*
 * ReadAll 
 */
void OrangePiReadAll(void)
{
	int pin;

#ifdef CONFIG_ORANGEPI_PC2
	printf (" +-----+-----+----------+------+---+-Orange Pi PC2+---+---+------+---------+-----+--+\n");
#elif defined(CONFIG_ORANGEPI_2G_IOT)
	printf (" +-----+-----+----------+------+---+-Orange Pi 2G-IOT+---+---+------+---------+-----+--+\n");
#elif defined(CONFIG_ORANGEPI_I96)
	printf (" +-----+-----+----------+------+---+-Orange Pi I96+---+---+------+---------+-----+--+\n");
#elif defined(CONFIG_ORANGEPI_H3)
	printf (" +-----+-----+----------+------+---+-Orange Pi H3+---+---+------+---------+-----+--+\n");
#elif defined(CONFIG_ORANGEPI_ZERO)
	printf (" +-----+-----+----------+------+---+-Orange Pi Zero+---+---+------+---------+-----+--+\n");
#elif defined(CONFIG_ORANGEPI_A64)
	printf (" +-----+-----+----------+------+---+-Orange Pi Win/Win+ +---+---+------+---------+-----+--+\n");
#endif
	printf (" | RDA | wPi |   Name    | Mode | V | Physical | V | Mode | Name      | wPi | RDA |\n");
	printf (" +-----+-----+-----------+------+---+----++----+---+------+-----------+-----+-----+\n");

	for (pin = 0 ; pin < 40 ; pin += 2)
		readallPhys(pin) ;

	printf (" +-----+-----+-----------+------+---+----++----+---+------+-----------+-----+-----+\n");
	printf (" | RDA | wPi |   Name    | Mode | V | Physical | V | Mode | Name      | wPi | RDA |\n");
#ifdef CONFIG_ORANGEPI_PC2
	printf (" +-----+-----+----------+------+---+-Orange Pi PC2+---+------+----------+-----+-----+\n");
#elif defined(CONFIG_ORANGEPI_I96)
	printf (" +-----+-----+----------+------+---+-Orange Pi I96+---+------+----------+-----+-----+\n");
#elif defined(CONFIG_ORANGEPI_2G_IOT)
	printf (" +-----+-----+----------+------+---+-Orange Pi 2G-IOT+---+------+----------+-----+-----+\n");
#elif defined(CONFIG_ORANGEPI_H3)
	printf (" +-----+-----+----------+------+---+-Orange Pi H3+---+------+----------+-----+-----+\n");
#elif defined(CONFIG_ORANGEPI_ZERO)
	printf (" +-----+-----+----------+------+---+-Orange Pi Zero+---+------+----------+-----+-----+\n");
#elif defined(CONFIG_ORANGEPI_A64)
	printf (" +-----+-----+----------+------+---+-Orange Pi Win/Win+ +---+------+----------+-----+-----+\n");
#endif
}

