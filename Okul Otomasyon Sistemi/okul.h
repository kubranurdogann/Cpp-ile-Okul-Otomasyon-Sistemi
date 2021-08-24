#ifndef OKUL_H
#define OKUL_H


class Ogrenci{
	public:
	string ad,soyad;
	int numara,vize,final;
	double ort;
	
	Ogrenci(){}
	
	void yeni_kayit(string,string,int);	
	
}ogrenciler[MAX],ogrenciler1[MAX3];

void Ogrenci::yeni_kayit(string ad,string soyad,int num){
this->ad=ad;
this->soyad=soyad;
this->numara=num;
}


class Ogretmen{
	public:
		string ogretmen_ad,ogretmen_soyad,sifre,ders;
		int ogretmen_no;
		void yeni_kayit(int,string,string,string,string);
		void ogretmen_menu();
}ogretmenler[MAX2];


void gorevli_menu();
void ana_menu();

#endif

