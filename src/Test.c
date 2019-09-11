/**
 * @file					Test.c
 * @description				RastgeleKarakter kütüphanesinin test dosyas¹
 * @course					Programlama Dillerinin Prensipleri
 * @assignment				Ödev 3
 * @date					14/04/2019
 * @author					Hakan Eryücel   hakan.eryucel@ogr.sakarya.edu.tr
 */
#include "stdio.h"
#include "conio.h"
#include "RastgeleKarakter.h"

int main()
{
	RastgeleKarakter rnd = RastgeleKarakterOlustur();
	
	printf("Rastgele Tek karakter : %c\n",rnd->KarakterUret(rnd));
    printf("Rastgele Tek karakter : %c\n",rnd->KarakterUret(rnd));
	printf("Rastgele Tek karakter : %c\n",rnd->KarakterUret(rnd));
	printf("Rastgele Tek karakter : %c\n",rnd->KarakterUret(rnd));
	printf("Rastgele Tek karakter : %c\n",rnd->KarakterUret(rnd));
	printf("Rastgele Tek karakter : %c\n",rnd->KarakterUret(rnd));
	printf("Rastgele Tek karakter : %c\n",rnd->KarakterUret(rnd));
    
	printf("-----------------------------------\n");
	
    char *str1 =rnd->CokKarakterUret(rnd,100);
    char *str2 =rnd->CokKarakterUret(rnd,90);
    char *str3 =rnd->CokKarakterUret(rnd,80);
	char *str4 =rnd->CokKarakterUret(rnd,70);
	char *str5 =rnd->CokKarakterUret(rnd,70);
	char *str6 =rnd->CokKarakterUret(rnd,80);
	char *str7 =rnd->CokKarakterUret(rnd,90);
	char *str8 =rnd->CokKarakterUret(rnd,100);
	
	printf("Rastgele 100 karakter : %s\n",str1);
    printf("Rastgele 90 karakter  : %s\n",str2);
    printf("Rastgele 80 karakter  : %s\n",str3);
	printf("Rastgele 70 karakter  : %s\n",str4);
	printf("Rastgele 70 karakter  : %s\n",str5);
	printf("Rastgele 80 karakter  : %s\n",str6);
	printf("Rastgele 90 karakter  : %s\n",str7);
	printf("Rastgele 100 karakter  : %s\n",str8);
    
	free(str1);
    free(str2);
    free(str3);
	free(str4);
	free(str5);
	free(str6);
	free(str7);
	free(str8);
	
	printf("-----------------------------------\n");
    
	printf("d-h arasi rastgele tek karakter : %c\n",rnd->AraKarakter(rnd,'d','h'));
    printf("a-e arasi rastgele tek karakter : %c\n",rnd->AraKarakter(rnd,'a','e'));
    printf("g-p arasi rastgele tek karakter : %c\n",rnd->AraKarakter(rnd,'g','p'));
    printf("A-Z arasi rastgele tek karakter : %c\n",rnd->AraKarakter(rnd,'A','Z'));
    printf("K-N arasi rastgele tek karakter : %c\n",rnd->AraKarakter(rnd,'K','N'));
    printf("p-t arasi rastgele tek karakter : %c\n",rnd->AraKarakter(rnd,'p','t'));
    printf("C-R arasi rastgele tek karakter : %c\n",rnd->AraKarakter(rnd,'C','R'));
    printf("e-j arasi rastgele tek karakter : %c\n",rnd->AraKarakter(rnd,'e','j'));
    
	printf("-----------------------------------\n");
	
    str1 =rnd->CokAraKarakter(rnd,'t','z',100);
	str2 =rnd->CokAraKarakter(rnd,'f','l',95);
	str3 =rnd->CokAraKarakter(rnd,'A','Z',90);
	str4 =rnd->CokAraKarakter(rnd,'B','E',85);
	str5 =rnd->CokAraKarakter(rnd,'d','h',85);
	str6 =rnd->CokAraKarakter(rnd,'T','Z',90);
	str7 =rnd->CokAraKarakter(rnd,'u','y',95);
	str8 =rnd->CokAraKarakter(rnd,'c','z',100);
	
	printf("t-z arasi rastgele 100 karakter: %s\n",str1);
    printf("f-l arasi rastgele 95 karakter : %s\n",str2);
    printf("A-Z arasi rastgele 90 karakter : %s\n",str3);
    printf("B-E arasi rastgele 85 karakter: %s\n",str4);
    printf("d-h arasi rastgele 85 karakter: %s\n",str5);
    printf("T-Z arasi rastgele 90 karakter: %s\n",str6);
    printf("u-y arasi rastgele 95 karakter: %s\n",str7);
    printf("c-z arasi rastgele 100 karakter: %s\n",str8);
	
    free(str1);
    free(str2);
    free(str3);
	free(str4);
	free(str6);
	free(str7);
	free(str8);
	
	printf("-----------------------------------\n");
    
	printf("a-k-g-h-n arasindan rastgele bir karakter : %c\n",rnd->BelirtilenKarakter(rnd,"akghn"));
    printf("a-s-d-f-g arasindan rastgele bir karakter : %c\n",rnd->BelirtilenKarakter(rnd,"asdfg"));       
    printf("q-w-E arasindan rastgele bir karakter : %c\n",rnd->BelirtilenKarakter(rnd,"qwE"));         
    printf("X-K-L-M-N-P-R arasindan rastgele bir karakter : %c\n",rnd->BelirtilenKarakter(rnd,"XKLMNPR"));   
    printf("t-r-i-m arasindan rastgele bir karakter : %c\n",rnd->BelirtilenKarakter(rnd,"trim"));        
    printf("P-r-Q-v-W-y-Z-T-R arasindan rastgele bir karakter : %c\n",rnd->BelirtilenKarakter(rnd,"PrQvWyZTR"));        
    printf("S-n-E-a-K arasindan rastgele bir karakter : %c\n",rnd->BelirtilenKarakter(rnd,"SnEaK"));      
    printf("L-i-n-k-E-D arasindan rastgele bir karakter : %c\n",rnd->BelirtilenKarakter(rnd,"LinkeD"));
    
	printf("-----------------------------------\n");
	
	str1 =rnd->CokBelirtilenKarakter(rnd,"qWz",100);
	str2 =rnd->CokBelirtilenKarakter(rnd,"avlro",90);
	str3 =rnd->CokBelirtilenKarakter(rnd,"mlPrTV",80);
	str4 =rnd->CokBelirtilenKarakter(rnd,"cCdD",75);
	str5 =rnd->CokBelirtilenKarakter(rnd,"RGNDMLTA",75);
	str6 =rnd->CokBelirtilenKarakter(rnd,"qwerty",80);
	str7 =rnd->CokBelirtilenKarakter(rnd,"asDFGhj",90);
	str8 =rnd->CokBelirtilenKarakter(rnd,"ZkLmx",100);
	
	printf("q-W-z arasindan rastgele 100 karakter: %s\n",str1);
    printf("a-v-l-r-o arasindan rastgele 90 karakter : %s\n",str2);
    printf("m-l-P-r-T-V arasindan rastgele 80 karakter: %s\n",str3);
    printf("c-C-d-D arasindan rastgele 75 karakter: %s\n",str4);
    printf("R-G-N-D-M-L-T-A arasindan rastgele 75 karakter: %s\n",str5);
    printf("q-w-e-r-t-y arasindan rastgele 80 karakter: %s\n",str6);
    printf("a-s-D-F-G-h-j arasindan rastgele 90 karakter: %s\n",str7);
    printf("Z-k-L-m-x arasindan rastgele 100 karakter: %s\n",str8);
	
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
	free(str7);
	free(str8);
	
	printf("-----------------------------------\n");
    
	str1=rnd->CumleOlustur(rnd);
	str2=rnd->CumleOlustur(rnd);
	str3=rnd->CumleOlustur(rnd);
	str4=rnd->CumleOlustur(rnd);
	str5=rnd->CumleOlustur(rnd);
	str6=rnd->CumleOlustur(rnd);
	str7=rnd->CumleOlustur(rnd);
	str8=rnd->CumleOlustur(rnd);
	
	printf("Rastgele cumle: %s\n",str1);
    printf("Rastgele cumle: %s\n",str2);
    printf("Rastgele cumle: %s\n",str3);
    printf("Rastgele cumle: %s\n",str4);
    printf("Rastgele cumle: %s\n",str5);
    printf("Rastgele cumle: %s\n",str6);
    printf("Rastgele cumle: %s\n",str7);
    printf("Rastgele cumle: %s\n",str8);
	
	free(str1);
	free(str2);
	free(str3);
	free(str4);
	free(str5);
	free(str6);
	free(str7);
	free(str8);
	
	getch();
}