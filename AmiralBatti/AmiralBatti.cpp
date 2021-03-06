// AmiralBatti.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string isim1;
string isim2;

// 1. ve 2. kullanıcıların haritası 1 olan karelerde gemi mevcut, 0 olanlar boş veya patlatılmış.
int harita1[10][10];
int harita2[10][10];

// 2 karelik gemiler
int mayinGemisi1[] = { 0,0,0,2 };
int mayinGemisi2[] = { 0,0,0,2 };

// 3 karelik gemiler
int firkateyn1[] = { 0,0,0,3 };
int firkateyn2[] = { 0,0,0,3 };

// 3 karelik gemiler
int denizalti1[] = { 0,0,0,3 };
int denizalti2[] = { 0,0,0,3 };

// 4 karelik gemiler
int kruvazor1[] = { 0,0,0,4 };
int kruvazor2[] = { 0,0,0,4 };

// 5 karelik gemiler
int ucakGemisi1[] = { 0,0,0,5 };
int ucakGemisi2[] = { 0,0,0,5 };

// kullanıcıdan geminin başlangıç koordinatlarını ve geminin yatay veya dikey konumlandırılacağı bilgisini alır
void GemiGir(int gemi[])
{
	cout << "gemi x koordinati (0-9) : ";
	cin >> gemi[0];
	cout << "gemi y koordinati (0-9) : ";
	cin >> gemi[1];
	cout << "gemi yonu (0:yatay, 1:dikey) : ";
	cin >> gemi[2];
}

// parametre verilen gemi, parametre verilen haritaya yerleştirilir
void HaritayaGemiYerlestir(int harita[10][10], int gemi[])
{
	int x = gemi[0];
	int y = gemi[1];
	int yon = gemi[2];
	int uzunluk = gemi[3];
	for (int i = 0; i < uzunluk; i++)
	{
		harita[x][y] = 1;
		if (yon == 0) // yatay ise
		{
			y++;
		}
		else // dikey sie
		{
			x++;
		}
	}
}

// parametre verilen harita ekrana çizdirilir
void HaritayiCiz(int harita[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << harita[i][j] << " ";
		}
		cout << endl;
	}
}

// verilen haritada x,y koordinatlarına atış yapılır. başarılı hamle ise true döner, değilse false döner.
bool HamleYap(string isim, int harita[10][10])
{
	cout << isim << " hamle sirasi sende!" << endl;
	int x, y;
	cout <<"x koordinati gir : ";
	cin >> x;
	cout << "y koordinati gir : ";
	cin >> y;

	// başarılı hamle. verilen koordinatlarda gemi mevcut.
	if (harita[x][y] == 1)
	{
		// girilen koordinatlarındaki gemi bölümü patlatıldı.
		harita[x][y] = 0;
		return true;
	}
	else // başarısız hamle.
	{
		return false;
	}
}

// parametre verilen haritanın gemilerden temizlenip temizlenmediği kontrol edilir. temizlenmiş ise true döner, gemi bölümü mevcut ise false döner
bool GalibiyetKontrol(int harita[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (harita[i][j] == 1)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	cout << "1. oyuncu ismini gir : ";
	cin >> isim1;
	GemiGir(mayinGemisi1);
	GemiGir(firkateyn1);
	GemiGir(denizalti1);
	GemiGir(kruvazor1);
	GemiGir(ucakGemisi1);
	HaritayaGemiYerlestir(harita1, mayinGemisi1);
	HaritayaGemiYerlestir(harita1, firkateyn1);
	HaritayaGemiYerlestir(harita1, denizalti1);
	HaritayaGemiYerlestir(harita1, kruvazor1);
	HaritayaGemiYerlestir(harita1, ucakGemisi1);
	HaritayiCiz(harita1);
	cout << "2. oyuncu ismini gir : ";
	cin >> isim2;
	GemiGir(mayinGemisi2);
	GemiGir(firkateyn2);
	GemiGir(denizalti2);
	GemiGir(kruvazor2);
	GemiGir(ucakGemisi2);
	HaritayaGemiYerlestir(harita2, mayinGemisi2);
	HaritayaGemiYerlestir(harita2, firkateyn2);
	HaritayaGemiYerlestir(harita2, denizalti2);
	HaritayaGemiYerlestir(harita2, kruvazor2);
	HaritayaGemiYerlestir(harita2, ucakGemisi2);
	HaritayiCiz(harita2);
	bool oyuncu1vurdu = true;
	bool oyuncu2vurdu = true;
	while (true)
	{
		while (oyuncu1vurdu == true)
		{
			oyuncu1vurdu = HamleYap(isim1, harita2);
			if (oyuncu1vurdu == true)
			{
				HaritayiCiz(harita2);
				bool sonuc = GalibiyetKontrol(harita2);
				if (sonuc == true)
				{
					cout << isim1 << " " << isim2 << " e ait gemilerini yerle bir ettin ! Tebrikler  !!! "<<endl;
					cout << "Kazanan " << isim1<<"!!!"<<endl;
					system("pause");
					exit(0);
				}
			}
			else
			{
				oyuncu2vurdu = true;
			}
		}
		while (oyuncu2vurdu)
		{
			oyuncu2vurdu = HamleYap(isim2, harita1);
			if (oyuncu2vurdu == true)
			{
				HaritayiCiz(harita1);
				bool sonuc = GalibiyetKontrol(harita1);
				if (sonuc == true)
				{
					cout << isim2 << " " << isim1 << " e ait gemilerini yerle bir ettin ! Tebrikler  !!! ";
					cout << "Kazanan " << isim2<<"!!!"<<endl;
					system("pause");
					exit(0);
				}
			}
			else
			{
				oyuncu1vurdu = true;
			}
		}
	}
	return 0;
}