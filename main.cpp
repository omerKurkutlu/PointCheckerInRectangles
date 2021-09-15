/*
Writer: Omer KURKUTLU
08/09/2021

Luften asagidaki note kisinlarini okumadan coda bakmayiniz.

NOTE!

Farkli algoritmalar:
1-  X ve Y eksenine paralel olan dikdortgenler icin algoritma
2-  Sadece Concave poligonlar icin bir algoritma
3-  Concave ve convex  poligonlar icin daha komplex bir algoritma

Bizim sorumuzu icin ilk algoritma yeterli!!!
(verimlilik ve code anlasilirlik acisindan en kolay algoritma)


NOTE!
Girdi ve cikti formatlari txt vb. bir dosyadan alinabilir/kaydedilebilir
Bu islem dosyadan satir satir okuma yazma ile halledilebilir, buna
projenin gereksinimleri karar verecektir.


NOTE!
Codu'umuzun daha hizli calismasini saglamak icin verilen her bir dikdortgenin
noktayi kapsadigini PARALLEL COMPUTING veya MULTI-THREATING yaparak (her bir dikdortgen 
birbirinden bagimsiz sekilde isleme konulabilir "INDEPENDENCY") 
CPU(openMP) veya GPU (cuda programming) ile halledebiliriz!!!


NOTE!
Yazdigim algoritma verilen sorunun en basit cozum halidir.
Algoritma kontrol edilirken ne tur bir machine(mac / windows /intel / amd vs) kulanilacagini bilmedigim icin
OpenMP veya Cuda ile yazmadim.Aksi taktirde code tarafinizdan compile edilemecekti.


*/



#include<iostream>
using namespace std;

class rectangule{
	private:
	int x1,y1,x2,y2;
	public:
	void setCoordinates(int x1,int y1,int x2,int y2);
	bool includePoint();
};


void rectangule::setCoordinates(int x1,int y1,int x2,int y2)
{	
	this->x1=x1;
	this->y1=y1;
	this->x2=x2;
	this->y2=y2;
}

bool rectangule::includePoint()
{
	int point_x=25,point_y=25;         //point to find
	if(point_x > x1 and point_x < x2 and point_y > y1 and point_y < y2) return 1;
	else return 0;
}

int main()
{
	int count=0;
	rectangule r[3];
	r[0].setCoordinates(20, 30, 60, 70);
	r[1].setCoordinates(50, 80, 90, 85);
	r[2].setCoordinates(0, 10, 40, 65);
	
	for(int i=0;i<3;i++)
	{
		if(r[i].includePoint()==1)
		{
			cout<<"Yes include"<<endl;
		    count++;
		}
		else cout<<"Point is out of boundary!!!"<<endl;		
	}	
	cout<<count<<" rectangle include the point"<<endl;
	return 0;
}



