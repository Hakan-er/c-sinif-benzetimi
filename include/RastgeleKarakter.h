/**
 * @file					RastgeleKarakter.h
 * @description				RastgeleKarakter kütüphanesinin baslik dosyasi
 * @course					Programlama Dillerinin Prensipleri
 * @assignment				Ödev 3
 * @date					14/04/2019
 * @author					Hakan Eryücel   hakan.eryucel@ogr.sakarya.edu.tr
 */
#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H

#include <string.h>
#include "Random.h"

struct RASTGELEKARAKTER
{
	Random super;
	char (*KarakterUret)(struct RASTGELEKARAKTER*);
	char (*Karakter)(struct RASTGELEKARAKTER*,int,int);
	char* (*CokKarakterUret)(struct RASTGELEKARAKTER*,int);
	char (*AraKarakter)(struct RASTGELEKARAKTER*,char,char);
	char* (*CokAraKarakter)(struct RASTGELEKARAKTER*,char,char,int);
	char (*BelirtilenKarakter)(struct RASTGELEKARAKTER*,char[]);
	char* (*CokBelirtilenKarakter)(struct RASTGELEKARAKTER*,char[],int);
	char* (*CumleOlustur)(struct RASTGELEKARAKTER*);
	void (*Yoket)(struct RASTGELEKARAKTER*);
};
typedef struct RASTGELEKARAKTER* RastgeleKarakter;

RastgeleKarakter RastgeleKarakterOlustur();
char karakterUret(const RastgeleKarakter);
char karakter(const RastgeleKarakter,int,int);
char* cokKarakterUret(const RastgeleKarakter,int);
char araKarakter(const RastgeleKarakter,char,char);
char* cokAraKarakter(const RastgeleKarakter,char,char,int);
char belirtilenKarakter(const RastgeleKarakter,char[]);
char* cokBelirtilenKarakter(const RastgeleKarakter,char[],int);
char* cumleOlustur(const RastgeleKarakter);
void RastgeleKarakterYoket(RastgeleKarakter);
#endif