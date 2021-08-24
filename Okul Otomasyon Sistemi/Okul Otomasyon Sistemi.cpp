#include <iostream>
#include <string>
#define MAX 150
#define MAX2 15
#define MAX3 10
using namespace std;

#include "okul.h"

void Ogretmen::yeni_kayit(int ogretmen_no,string ogretmen_ad,string ogretmen_soyad, string sifre,string ders){
	this->ogretmen_no=ogretmen_no;
	this->ogretmen_ad=ogretmen_ad;
	this->ogretmen_soyad=ogretmen_soyad;
	this->sifre=sifre;
	this->ders=ders;
}



void Ogretmen::ogretmen_menu(){
	int secim,n;
	static double toplam;
	static int d=-1;         //statik deðiþkenler bellekte kalýcý olurlar.ogretmen_menu() fonksiyonu iþlevi bitse bile
                          //statik degiþkenler bellekte kayýtlý olarak kalýr.(normal degiþkenler silinir.)

system("cls");

cout<<"Ogretmen Not Sistemi"<<endl;
cout<<"--------------------"<<endl;
cout<<"1.Not girisi"<<endl;
cout<<"2.Sinif Not Ortalamasi"<<endl;
cout<<"3.Ogrenci Listesi"<<endl;
cout<<"4.Ana Menu"<<endl;

cout<<endl<<">"; cin>>secim;

switch(secim){
	
	case 1:
		system("cls");
	     	cout<<"Notunu gireceginiz ogrencinin numarasini giriniz: "<<endl;
	     	cin>>n;
	     	
	     	for(int c=0;c<150;c++){
	     		
	     		if(ogrenciler[c].numara==n){
	     			system("cls");
	     			cout<<"Vize notu giriniz.\n>"; cin>>ogrenciler[c].vize;
	     			cout<<"Final notu giriniz.\n>"; cin>>ogrenciler[c].final;
	     			
					 cout<<"Islem basaili."<<endl;
					 d++;
					 ogrenciler[c].ort=double(ogrenciler[c].vize*0.3+ogrenciler[c].final*0.7);
					 ogrenciler1[d]=ogrenciler[c];   //Secili ogretmenin dersini alananlar ayri bir nesne dizisine aliniyor.
					 
					 system("pause");
				     ogretmen_menu();
				 }
			 }
			 
	case 2:
		system("cls");
		   cout<<"Sinifin Not Ortalamasi"<<endl;
		   
		   if(d<0){
		    	cout<<"Bu dersi alan ogrenci yok!"<<endl;
		   	    system("pause");
		   	    ogretmen_menu();
		   
		   }else{
		   	    
		   	    for(int x=0;x<=d;x++)
		   	    	toplam+=ogrenciler1[x].ort;
		   	    	
					cout<<toplam/(d+1)<<endl;
					system("pause");
		   	    	ogretmen_menu();
				   
		   }
		   
	case 3:
	    
		system("cls");
		   for(int x=0;x<=d;x++){
		   	  for(int y=0;y<=d;y++){
		   	  	 
					  if(ogrenciler1[x].numara==ogrenciler[y].numara)
		   	  		    cout<<"Ad: "<<ogrenciler1[x].ad<<"\t Soyad: "<<ogrenciler1[x].soyad<<"\t Numara: "<<ogrenciler1[x].numara<<"\t Ortalama: "<<ogrenciler1[x].ort<<endl;
					  
				 }
			}
			system("pause");
			ogretmen_menu();		 
 
    case 4: 
        
        system("cls");
        ana_menu();

}
}

int main(){
	ana_menu();
	system("pause");
	
	return 0;
}


void ana_menu(){
	
	system("cls");
	int secim,b,num;
	string sifre;
	string k_id,k_sifre;
	
	cout<<"---OKUL OTOMASYOMU---"<<endl;
	cout<<"---------------------"<<endl;
	cout<<"1-Gorevli Girisi"<<endl;
	cout<<"2-Ogretmen Girisi"<<endl;
	cout<<"3-cikis"<<"\n\n>"; cin>>secim;
	
	switch(secim){
		
		case 1:
			system("cls");
			there:
			cout<<"Kullanici adi: \n>"; cin>>k_id;
			
			if(k_id == "1"){
				there0:
				cout<<"Sifre: \n>"; cin>>k_sifre;
				
				if(k_sifre == "1"){
					gorevli_menu();
				}else{
					cout<<"Hatali sifre!\nTekrar deneyin.."<<endl;
					goto there0;
				}
				
			}else{
				cout<<"Hatali giris!\nTekrar deneyin..";
				goto there;
			}
			
			
		case 2:
		     
		     there2:
		     system("cls");
			 cout<<"Numara Girin: \n>"; cin>>num;
			 
			 for(int b=0;b<15;b++){
			 	
			 	if(ogretmenler[b].ogretmen_no==num){
			 		
			 		there1:
					 cout<<"Sifre Girin:\n>"; cin>>sifre;
			 		 
					 if(ogretmenler[b].sifre==sifre){
			 		    cout<<"Basarili giris.";
						 system("pause");
						 ogretmenler[b].ogretmen_menu();	
					 }else{
					 	cout<<"sifre yanlis!!\ntekrar deneyin.."<<endl;
					 	system("pause");
						goto there1;
					 }
				}
				 }
				 	cout<<"Numara Yanlis!!\ntekrar deneyin.."<<endl;
				 	goto there2;
				 
			 
			 
		
			 
		case 3:  exit(0);
		
		
		default:  ana_menu();
			 
	}
	
}



void gorevli_menu(){
	int secim,no,aranan;
	static int numara=0,i=-1,a=-1;
	string ad,soyad,ders,s;
	system("cls");
	
	cout<<"Okul Otomasyonu"<<endl;
	cout<<"---------------------"<<endl;
	cout<<"1-Yeni Ogrenci Kayit"<<endl;
	cout<<"2-Ogrenci Kayit Sil"<<endl;
	cout<<"3-Ogrenci Kayit Listele"<<endl;
	cout<<"4-Yeni Ogretmen Kayit"<<endl;
	cout<<"5-Ogretmen Kayit Sil"<<endl;
	cout<<"6-Ogretmen Kayit Listele"<<endl;
	cout<<"7-Ana Menu \n\n>";
	
	cin>>secim;
	
	switch(secim){
		
		case 1:
			system("cls");
			cout<<"Ad girin:\n>"; cin>>ad;
			cout<<"Soyad girin:\n>"; cin>>soyad;
			cout<<"Numara girin:\n>"; cin>>no;
			i++;
			ogrenciler[i].yeni_kayit(ad,soyad,no);
			cout<<"\nKayit islemi basarili!"<<endl;
			gorevli_menu();
			
		case 2:
		    system("cls");
			cout<<"Kaydini sileceginiz ogrencinin numarasini giriniz:\n>"; cin>>aranan;
			
			for(int j=0; j<=i; j++){
				
				if(ogrenciler[j].numara==aranan){
					for(int k=j; k<i; k++){
						ogrenciler[k]=ogrenciler[k+1];
						cout<<"Kayit Silindi!"<<endl;
						i--;
						system("pause");
						gorevli_menu();
					}
				}else{
					cout<<"Kayit Bulunamadi!!!"<<endl;
					system("pause");
					gorevli_menu();
				}
				
			}
				
				
		case 3:		
		    system("cls");
		    
		    for(int j=0; j<=i; j++){
		    	cout<<"Ad: "<<ogrenciler[j].ad<<"\tSoyad: "<<ogrenciler[j].soyad<<"\tNumara: "<<ogrenciler[j].numara<<endl;
			}
			system("pause");
			gorevli_menu();
			
			
		case 4:
		   system("cls");
		   cout<<"Ad girin:\n>"; cin>>ad;
		   cout<<"Soyad girin:\n>"; cin>>soyad;
		   cout<<"Verecegi ders:\n>"; cin>>ders;
		   cout<<"Ogretmen girisinde kullanilacak sifre:\n>"; cin>>s;
		   a++;
		   numara++;
		   cout<<"\nKayit basarili!"<<endl;
		   ogretmenler[a].yeni_kayit(numara,ad,soyad,s,ders);
		   gorevli_menu();
		
		   
		case 5:  
		    system("cls");
		    cout<<"Kaydini sileceginiz ogretmenin numarasini giriniz:\n>"; cin>>aranan;
			
			for(int j=0; j<=a; j++){
				
				if(ogretmenler[j].ogretmen_no==aranan){
					for(int k=j; k<a; k++)
						ogretmenler[k]=ogretmenler[k+1];
						
						cout<<"Kayit Silindi!"<<endl;
						a--;
						system("pause");
						gorevli_menu();
					
				}
				
			}
				cout<<"Kayit Bulunamadi!!!"<<endl;
				system("pause");
				gorevli_menu();
				
		
		    
		case 6:
		    system("cls");
			
			for(int j=0; j<=a; j++){	
				cout<<"Ad: "<<ogretmenler[j].ogretmen_ad<<"\tSoyad: "<<ogretmenler[j].ogretmen_soyad<<"\t No: "<<ogretmenler[j].ogretmen_no<<"\t Verdigi ders: "<<ogretmenler[j].ders<<endl;
			
			}   
			system("pause");
			gorevli_menu();
		
		 
		case 7: ana_menu();
		
		default: 
		    cout<<"Hata!!!"<<endl;
			gorevli_menu(); 	   
		   
	}
	
}













