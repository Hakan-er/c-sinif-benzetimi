/**
 * @file					Test.c
 * @description				RastgeleKarakter kütüphanesinin kaynak dosyasi
 * @course					Programlama Dillerinin Prensipleri
 * @assignment				Ödev 3
 * @date					14/04/2019
 * @author					Hakan Eryücel   hakan.eryucel@ogr.sakarya.edu.tr
 */
#include "RastgeleKarakter.h"

RastgeleKarakter RastgeleKarakterOlustur()
{
	RastgeleKarakter this;
	this = (RastgeleKarakter)malloc(sizeof (struct RASTGELEKARAKTER));
	this->super = RandomOlustur();
	this->KarakterUret=&karakterUret;
	this->Karakter=&karakter;
	this->CokKarakterUret=&cokKarakterUret;
	this->AraKarakter=&araKarakter;
	this->CokAraKarakter=&cokAraKarakter;
	this->BelirtilenKarakter=&belirtilenKarakter;
	this->CokBelirtilenKarakter=&cokBelirtilenKarakter;
	this->CumleOlustur=&cumleOlustur;
	this->Yoket=&RastgeleKarakterYoket;
	return this;
}
char karakterUret(const RastgeleKarakter this)// Aralik verilmeden karakter üretir. Varsayilan olarak A-z arasi kabul eder.
{
	return this->Karakter(this,'A','z');
}
char karakter(const RastgeleKarakter this,int baslangic,int bitis)// Verilen iki karakter arasindaki karakterlerden birini rastgele döndürür.
{
	int aralik;
	if(bitis-baslangic<0)
	{
		aralik=baslangic-bitis;
	}
	else
	{
		aralik=bitis-baslangic;
	}
	char karakter = (char)(this->super->GetirInt(this->super)%aralik+baslangic);
	while(karakter<97&&karakter>90)
	{
		karakter =(char)(this->super->GetirInt(this->super)%aralik+baslangic);
	}
	return karakter;
}
char* cokKarakterUret(const RastgeleKarakter this,int karakterSayisi)// Aralik verilmeden istenilen sayida karakter üretir.
{
	char *str = (char*)malloc(karakterSayisi*sizeof(char)+1);
	int i=0;
	for(i;i<karakterSayisi;i++)
	{
		str[i]=this->Karakter(this,'A','z');// Karakater fonksiyonundan dönen char degiskenleri bir char* de tutar.
	}
	str[karakterSayisi]='\0';
	return str;
}
char araKarakter(const RastgeleKarakter this,char baslangicKarakteri,char bitisKarakteri)// Verilen iki karakter arasindan rastgele bir karakteri geri döndürür.
{
	if(baslangicKarakteri<bitisKarakteri)
	{
		return this->Karakter(this,baslangicKarakteri+1,bitisKarakteri);
	}
	else
	{
		return this->Karakter(this,bitisKarakteri+1,baslangicKarakteri);
	}
}
char* cokAraKarakter(const RastgeleKarakter this,char baslangicKarakteri,char bitisKarakteri,int karakterSayisi)// Verilen iki karakter arasindan istenilen sayida karakter geri döndürür.
{
	char *str = (char*)malloc(karakterSayisi*sizeof(char)+1);
	int i=0;
    for(i;i<karakterSayisi;i++)
    {
		str[i]=this->AraKarakter(this,baslangicKarakteri,bitisKarakteri);
    }
	str[karakterSayisi]='\0';
    return str;
}
char belirtilenKarakter(const RastgeleKarakter this,char karakterler[]) //Belirtilen karakterlerden rastgele birini geri döndürür.
{
	return karakterler[this->super->GetirInt(this->super)%strlen(karakterler)];
}
char* cokBelirtilenKarakter(const RastgeleKarakter this,char karakterler[],int karakterSayisi) // Belirtilen karakterlerden rastgele istenilen sayida döndürür.
{
	char *str = (char*)malloc(karakterSayisi*sizeof(char)+1);
	int i=0;
	for(i;i<karakterSayisi;i++)
	{
		str[i]=this->BelirtilenKarakter(this,karakterler);
	}
	str[karakterSayisi]='\0';
	return str;
}
char* cumleOlustur(const RastgeleKarakter this) // Rastgele cümle döndürür.
{
	int kelimeSayisi=this->super->GetirInt(this->super)%10+4; //4 ile 13 arasinda bir kelime sayisi belirlenir.
    int i=0,karakterSayisi=0;
	int sayiDizi[kelimeSayisi];
	for(i;i<kelimeSayisi;i++) // Her kelime için 3 ile 12 harf arasinda bir kelime uzunlugu belirleniyor.
	{
		sayiDizi[i]=this->super->GetirInt(this->super)%10+3;
		karakterSayisi+=sayiDizi[i];
	}
	char *str = (char*)malloc((karakterSayisi+2)*sizeof(char));
	str[0]=this->Karakter(this,'A','Z');
	int j=1;
    for(i=0;i<kelimeSayisi;i++)// Rastgele kelimeler olusturulacak.
    {
        if(i!=kelimeSayisi-1) // Son kelime degilse nokta koyulmayacak..
        {   
			char *tmp = this->CokAraKarakter(this,'a','z',sayiDizi[i]-1);
			int x=0;
			for(x;x<sayiDizi[i]-1;x++)// Kelime uzunlugu kadar rastgele harf bulunuyor.
			{
				str[j]=tmp[x];
				j++;
			}
			str[j]=' ';
			j++;
        }
        else // Son kelime olusturulduktan sonra nokta koyulacak.
        {
			char *tmp = this->CokAraKarakter(this,'a','z',sayiDizi[i]-1);
			int x=0;
			for(x;x<sayiDizi[i]-1;x++)
			{
				str[j]=tmp[x];
				j++;
			}
			str[karakterSayisi]='.';
			j++;
        }
    }
	str[karakterSayisi+1]='\0';
    return str;
}
void RastgeleKarakterYoket(RastgeleKarakter this) //Heap bellekte olusan RANDOM ve RASTGELEKARAKTER struct alanlarini bellege teslim eder.
{
	if(this==NULL)
	{
		return;
	}
	this->super->Yoket(this->super);
	free(this);
}