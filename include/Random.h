/**
 * @file					Test.c
 * @description				Random kütüphanesinin baslik dosyasi
 * @course					Programlama Dillerinin Prensipleri
 * @assignment				Ödev 3
 * @date					14/04/2019
 * @author					Hakan Eryücel   hakan.eryucel@ogr.sakarya.edu.tr
 */
#ifndef ORDER_H
#define ORDER_H
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>
typedef enum BOOL{ false, true}boolean;
struct RANDOM
{
	double seed;
	void (*Seed)(struct RANDOM*);
	double (*Getir)(struct RANDOM*);
	boolean (*GetirBoolean)(struct RANDOM*);
	int (*GetirInt)(struct RANDOM*);
	double (*GetirDouble)(struct RANDOM*);
	void (*YeniSeed)(struct RANDOM*);
	void (*Yoket)(struct RANDOM*);
};
typedef struct RANDOM* Random;
Random RandomOlustur();
void seed(const Random);
double getir(const Random);
boolean getirBoolean(const Random);
int getirInt(const Random);
double getirDouble(const Random);
void yeniSeed(const Random);
void RandomYoket(Random);
#endif