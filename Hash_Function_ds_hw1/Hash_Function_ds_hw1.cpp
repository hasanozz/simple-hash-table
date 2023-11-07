#include <stdio.h>
#include <string.h>

#define AILE_UYE_SAYISI 10


struct AileUye {	// A kümesindeki isimleri tutar
	char isim[10];
};


struct AileBilgileri {
	struct AileUye uye;
	int dolu;
};

struct AileBilgileri hashTablosu[AILE_UYE_SAYISI];



int hash(char* isim)	// ismin ascii kodlarını toplama ekleyerek isimden tam sayı oluşturur
{
	int toplam = 0;
	for (int i = 0; i < strlen(isim); i++) {
		toplam += isim[i];
	}
	return toplam % AILE_UYE_SAYISI;
}



void ekle(struct AileUye uye)	// A kümesindeki isimleri hash tablosuna ekler
{
	int indis = hash(uye.isim);

	// ismin yerleştirileceği indis doluysa çatışmayı çözmek için yeni indis belirler
	while (hashTablosu[indis].dolu) {
		printf("--> %d.indis dolu %s bir sonraki indise tasindi\n", indis, uye.isim);
		indis = (indis + 1) % AILE_UYE_SAYISI;
	}
	printf("--> %s, %d.indise eklendi\n", uye.isim, indis);
	hashTablosu[indis].uye = uye;
	hashTablosu[indis].dolu = 1;
}



void yazdir()	// Hash tablosunu yazdırır
{
	printf("\nHash Tablosu\n");
	for (int i = 0; i < AILE_UYE_SAYISI; i++) {
		if (hashTablosu[i].dolu)
			printf("%d: %s\n", i, hashTablosu[i].uye.isim);
		else
			printf("%d: Bos\n", i);
	}
}



int main()
{
	struct AileUye A_kumesi[AILE_UYE_SAYISI] =
	{
		{"Hasan"},
		{"Turhan"},
		{"Emre"},
		{"Yasemin"},
		{"Zeynep"},
		{"Selin"},
		{"Fatih"},
		{"Enes"},
		{"Elif"},
		{"Ahmet" }
	};

	printf("Aile Uyeleri\n");
	for (int i = 0; i < AILE_UYE_SAYISI; i++) {
		printf("%d: %s\n", i, A_kumesi[i]);		// Tabloya eklenmeden önceki sıralama
	}


	for (int i = 0; i < AILE_UYE_SAYISI; i++) {	// A kümesindeki elemanları indislerine göre hash tablosuna ekler
		ekle(A_kumesi[i]);
	}

	yazdir();



	return 0;
}