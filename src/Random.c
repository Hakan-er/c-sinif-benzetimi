/**
 * @file					Test.c
 * @description				Random kütüphanesinin kaynak dosyasi
 * @course					Programlama Dillerinin Prensipleri
 * @assignment				Ödev 3
 * @date					14/04/2019
 * @author					Hakan Eryücel   hakan.eryucel@ogr.sakarya.edu.tr
 */
#include "Random.h"
Random RandomOlustur()
{
	Random this;
	this = (Random) malloc(sizeof(struct RANDOM));
	this->Seed = &seed;
	this->Getir = &getir;
	this->GetirBoolean = &getirBoolean;
	this->GetirInt = &getirInt;
	this->GetirDouble = &getirDouble;
	this->YeniSeed = &yeniSeed;
	this->Yoket= &RandomYoket;
	this->YeniSeed(this);
	return this;
}
void seed(const Random this)//RANDOM struct da tutulan seed degiskenine yeniler.
{
	time_t seconds;
    seconds = time(NULL);
	double tmp = pow((this->seed+((seconds%10+1)*M_PI)),8);
	tmp -= floor(tmp);//Seed degiskeninde her zaman 0 ile 1 arasinda bir deger tutulacak. Bu yüzden tamsayi kismini çikartiyor.
	this->seed = tmp;
}
double getir(const Random this)//Seed degikenini yeniler ve döndürür.
{
	this->Seed(this);
	return this->seed;
}
boolean getirBoolean(const Random this)//Enum olarak olusturmus boolean tipinde sonuc döndürür.
{
	return this->GetirInt(this)%2==0;
}
int getirInt(const Random this)//GetirDouble fonksiyonundan gelen degeri integere çevirip döndürür.
{
	int tmp = fmod(this->GetirDouble(this),(double)INT_MAX);
	return tmp;
}
double getirDouble(const Random this)// Seed yenilenir ve geriye double türünden deger döndürülür.
{
	this->Seed(this);
	double tmp = this->seed;
	while(tmp-floor(tmp)>0.00000001)//Seed degiskenindeki deger 0 ile 1 arasinda oldundan virgülden sonrasindan kurtulana kadar 10 ile çarparak sayiyi büyütüyoruz.
	{
		tmp*=10;
	}
	return tmp;
}
void yeniSeed(const Random this)//Seed degiskeninin ilk deger atamasi için kullanilan fonksiyon.
{
	time_t seconds;
    seconds = time(NULL);
	double seed = seconds;
	while(seed>1)
	{
		seed/=10;
	}
	this->seed=seed;
}
void RandomYoket(Random this)//Heap bellekte olusturulan RANDOM structinin yerini bellege teslim eder.
{
	if(this==NULL)
	{
		return;
	}
	free(this);
}