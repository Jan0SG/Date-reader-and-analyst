#include<iostream>
#include<string>
#include<math.h>
using namespace std;

const int diasMeses[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
const int diasBi[12] = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};


class fecha{
	
	private:
		int day;
		int month;
		int year;
		int date[3] = {getDay(), getMonth(), getYear()};
		int datebase[3] = {1, 1, 1900};
		
		void valida(){
			/*day=getDay();
			cout<<getDay();
			cout<<getMonth();
			cout<<getYear();*/
			if(day<1 or day>31){
				cout<<"\nThe day you provided is not valid. It will be established as 1.\n\n";
				setDay(1);
			}
		
			if(month<1 or month>12){//condiciones por mes, algunos meses no tienen 30 dias
				cout<<"\nThe month you provided is not valid. It will be established as 1.\n\n";
				setMonth(1);
			}
			
			if(year<1900 or year>2050){
				cout<<"\nThe month you provided is not valid. It will be established as 1900.\n\n";
				setYear(1900);
			}
			if(day>30 and month==4){
				cout<<"\nThis month cannot have more than 30 days. It will be established as 1.";
				setMonth(1);
			}
			if(day>30 and month==6){
				cout<<"\nThis month cannot have more than 30 days. It will be established as 1.";
				setMonth(1);
			}
			if(day>30 and month==9){
				cout<<"\nThis month cannot have more than 30 days. It will be established as 1.";
				setMonth(1);
			}
			if(day>30 and month==11){
				cout<<"\nThis month cannot have more than 30 days. It will be established as 1.";
				setMonth(1);
			}
			if(month==2 and day>29 and year%4==0){
				cout<<"\nThis month cannot have more than 29 days when it is a leap year. It will be established as 1.";
				setMonth(1);
			}else if(month==2 and day>28 and year%4!=0){
				cout<<"\nThis month cannot have more than 28 days when it is not a leap year. It will be established as 1.";
				setMonth(1);
			}
	}
	public:
		fecha(){
			setDay(1);
			cout<<getDay()<<"-";
			setMonth(1);
			cout<<getMonth()<<"-";
			setYear(1900);
			cout<<getYear();
			valida();
		}
		
		fecha(int d, int m, int y){
			d=1;
			m=1;
			y=1900;
			setDay(d);
			setMonth(m);
			setYear(y);
			valida();
		}
	
	void leer(){

			cout<<"\nEnter the day (1 al 31): "; cin>>day;

	
			cout<<"Enter the month (1 al 12): "; cin>>month;
		
	
			cout<<"Enter the year (1900 al 2050): "; cin>>year;
			valida();

	}
	
	void mostrar(){
		cout<<"\n\nUp next is the date: \n";
		cout<<getDay()<<" - "<<getMonth()<<" - "<<getYear();
	}
	
	void bisiesto(){
		if(year%4 == 0){
			cout<<"\n\nIt is a leap year!";
			
		}else{
			cout<<"\n\nIt is not a leap year :c";
		}
	}
	
	int diasMes(int e){
		
		switch(e){
			case 1:
				cout<<"\nThe number of days in the month of January is: 31.";	break;
			case 2:
				if(year%4==0){
				
					cout<<"\nThe number of days in the month of February is: 29.";
				}else{
					cout<<"\nThe number of days in the month of February is: 28.";
				}
				break;
			case 3:
				cout<<"\nThe number of days in the month of March is: 31.";	break;
			case 4:
				cout<<"\nThe number of days in the month of April is: 30.";	break;
			case 5:
				cout<<"\nThe number of days in the month of May is: 31.";		break;
			case 6:
				cout<<"\nThe number of days in the month of June is: 30.";	break;
			case 7:
				cout<<"\nThe number of days in the month of July is: 31.";	break;
			case 8:
				cout<<"\nThe number of days in the month of August is: 31.";	break;
			case 9:
				cout<<"\nThe number of days in the month of September is: 30.";	break;
			case 10:
				cout<<"\nThe number of days in the month of October is: 31.";	break;
			case 11:
				cout<<"\nThe number of days in the month of November is: 30.";	break;
			case 12:
				cout<<"\nThe number of days in the month of December is: 31.";	break;
		}
	}
	
	void formatoCorto(){
		cout<<"\n\nUp next is the date: \n";
		cout<<getDay()<<" - "<<getMonth()<<" - "<<getYear();
	}
	
	int conteoloopdiadate(){
		int date[3] = {getDay(), getMonth(), getYear()};
		//int datebase[3] = {1, 1, 1900};
		int dias;
  		int anios = date[2];
   		if (date[1] <= 2){	
      	anios--;
		}
		
   		dias =  ( (anios / 4) - (anios / 100) + (anios / 400) );
   		return dias;
	}
	
	int conteoloopdiadatebase(){

		int datebase[3] = {1, 1, 1900};
		int dias;
  		int anios = datebase[2];
   		if (datebase[1] <= 2){	
      	anios--;
		}
		
   		dias = ( (anios / 4) - (anios / 100) + (anios / 400) );
   		return dias;
	}
	
	int diasTranscurridos(){
		int date[3] = {getDay(), getMonth(), getYear()};
		int datebase[3] = {1, 1, 1900};
		int conteofinal = 0;
   		int conteodias1 = (date[2] * 365);
   		if(getYear()%4==0 and getMonth()>2){
   			conteodias1 += diasMeses[date[1]];
   			conteodias1 -= 2;
		}else{
			conteodias1 += diasMeses[date[1]];
			conteodias1 -= 2;
		}
 		conteodias1 += date[0];
 		conteodias1 += conteoloopdiadate();
 		
   		int conteodias2 = (datebase[2] * 365);
   		conteodias2 += diasMeses[datebase[1]];
   		conteodias2 += datebase[0];
   		conteodias2 += conteoloopdiadatebase();
   		if(datebase[0]==date[0]){
   			if(datebase[1]==date[1]){
   				if(datebase[2]==date[2]){
   					cout<<"\n\nThe total number of days that have passed between the dates is: "<<0;
				}
			}
		}else{			
	   		conteofinal = ( abs(conteodias1 - conteodias2) );
   			cout<<"\n\nThe total number of days that have passed between the dates is: "<<conteofinal;
		}
	}
	
	int conteoloopdiahoy(int hoy[]){
		//int date[3] = {getDay(), getMonth(), getYear()};
		//int datebase[3] = {1, 1, 1900};
		int dias;
  		int anios = hoy[2];
   		if (hoy[1] <= 2){	
      	anios--;
		}
		
   		dias =  ( (anios / 4) - (anios / 100) + (anios / 400) );
   		return dias;
	}
	
	int diasEntre(int hoy[]){
		
		int date[3] = {getDay(), getMonth(), getYear()};
		//int datebase[3] = {1, 1, 1900};
		int conteofinal = 0;
   		int conteodias1 = (date[2] * 365);
   		if(getYear()%4==0 and getMonth()>2){
   			conteodias1 += diasMeses[date[1]];
   			conteodias1 -= 0;
		}else{
			conteodias1 += diasMeses[date[1]];
			conteodias1 -= 2;
		}
 		conteodias1 += date[0];
 		conteodias1 += conteoloopdiadate();
 		
   		int conteodias2 = (hoy[2] * 365);
   		if(hoy[2]%4==0 and hoy[1]>2){
   			conteodias2 += diasMeses[hoy[1]];
   			conteodias2 += 0;
		}else{
			conteodias2 += diasMeses[hoy[1]];
			conteodias2 -= 2;
		}
   		/*conteodias2 += diasMeses[hoy[1]];
   		conteodias2 -= 3;*/
   		conteodias2 += hoy[0];
   		conteodias2 += conteoloopdiahoy(hoy);
   		conteofinal = ( abs(conteodias1 - conteodias2) );
   		
   		cout<<"\n\nThe total number of days that have passed between the dates is: "<<conteofinal;
   		
	}
	
	int diaSemana(){
		int semana=0;
		int date[3] = {getDay(), getMonth(), getYear()};
		int datebase[3] = {1, 1, 1900};
		int conteofinal = 0;
   		int conteodias1 = (date[2] * 365);
   		if(getYear()%4==0 and getMonth()>2){
   			conteodias1 += diasMeses[date[1]];
   			conteodias1 -= 2;
		}else{
			conteodias1 += diasMeses[date[1]];
			conteodias1 -= 2;
		}
 		conteodias1 += date[0];
 		conteodias1 += conteoloopdiadate();
 		
   		int conteodias2 = (datebase[2] * 365);
   		conteodias2 += diasMeses[datebase[1]];
   		conteodias2 += datebase[0];
   		conteodias2 += conteoloopdiadatebase();
   		conteofinal = ( abs(conteodias1 - conteodias2) );
   		
		if(conteofinal-1==1){
			semana = 0;
		}else
		   for(int i=-1; i<conteofinal-1; i++){
		   		if(semana==6){
		   			semana = 0;
				}
				
				semana++;
			
		   }
		   switch(semana){
		   		case 0: cout<<"\nThe day of the week is Saturday.";	break;
		   		case 1: cout<<"\nThe day of the week is Monday.";	break;
		   		case 2: cout<<"\nThe day of the week is Tuesday.";	break;
		   		case 3: cout<<"\nThe day of the week is Wednesday.";	break;
				case 4: cout<<"\nThe day of the week is Thursday.";	break;
				case 5: cout<<"\nThe day of the week is Friday.";	break;
				case 6: cout<<"\nThe day of the week is Saturday.";	break;
		   }	
	}
	
	void formatoLargo(){
		string dia, mes;
		cout<<"\n\nUp next is the date: \n";
		
		if(getMonth()==1){mes = "January";}
		
		if(getMonth()==2){mes = "February";}
		
		if(getMonth()==3){mes = "March";}
		
		if(getMonth()==4){mes = "April";}
		
		if(getMonth()==5){mes = "May";}
		
		if(getMonth()==6){mes = "June";}
		
		if(getMonth()==7){mes = "July";}
		
		if(getMonth()==8){mes = "August";}
		
		if(getMonth()==9){mes = "September";}
		
		if(getMonth()==10){mes = "October";}
		
		if(getMonth()==11){mes = "November";}
		
		if(getMonth()==12){mes = "December";
		}
		cout<<getDay()<<" of "<<mes<<" of "<<getYear();
	}

	
	void siguiente(){
		int a = 0, b = 0, c = 0;
		
		a = getDay() + 1;
		b = getMonth();
		c = getYear();
		//condiciones por mes, no todos los meses tienen 31 dias
		if(a>28 and b==2 and c%4!=0){
			a = 1;
			b += 1;
		}else if(a>29 and b==2 and c%4==0){
			a = 1;
			b += 1;
		}else if(a>30 and b==4){
			a = 1;
			b += 1;
		}else if(a>30 and b==6){
			a = 1;
			b += 1;
		}else if(a>30 and b==9){
			a = 1;
			b += 1;
		}else if(a>30 and b==11){
			a = 1;
			b += 1;
		}else if(a>31){
			a = 1;
			b += 1;
			if(b>12){
				b = 1;
				c += 1;
				if(c>2050){
					cout<<"\nThe next day cannot be shown since it exceeds the limit in the dates of this program.";
				}
			}
		}
		if(c<=2050){			
			cout<<endl;
			cout<<a<<" - "<<b<<" - "<<c;
		} 
	}
	
	void anterior(){
		int a = 0, b = 0, c = 0;
		
		a = getDay() - 1;
		b = getMonth();
		c = getYear();
		//condiciones por mes, no todos los meses tienen 31 dias
		if(a<1 and b==3 and c%4!=0){
			a = 28;
			b -= 1;
		}else if(a<1 and b==3 and c%4==0){
			a = 29;
			b -= 1;
		}else if(a<1 and b==5){
			a = 30;
			b -= 1;
		}else if(a<1 and b==7){
			a = 30;
			b -= 1;
		}else if(a<1 and b==9){
			a = 30;
			b -= 1;
		}else if(a<1 and b==12){
			a = 30;
			b -= 1;
		}else if(a<1){
			a = 31;
			b -= 1;
			if(b<1){
				b = 12;
				c -= 1;
				if(c<1900){
					cout<<"\nThe previous day cannot be shown since it exceeds the limit in the dates of this program.";
				}
			}
		}
		if(c>=1900){			
			cout<<endl;
			cout<<a<<" - "<<b<<" - "<<c;
		} 
	}
	
	int igualQue(int hoy[]){
		int date[3] = {getDay(), getMonth(), getYear()};
		
		if(date[0]==hoy[0]){
			if(date[1]==hoy[1]){
				if(date[2]==hoy[2]){
					 cout<<"\nThe date of the object and the provided date are the same.";
				}
			}
		}
	}
	
	int menorQue(int hoy[]){
		int date[3] = {getDay(), getMonth(), getYear()};
		
		if(hoy[0]>date[0]){
			if(hoy[1]>=date[1]){
				if(hoy[2]>=date[2]){
					 cout<<"\nThe date of the object is previous to the provided date.";
				}
			}
		}
	}		
		
	
	
	void mayorQue(int hoy[]){
		int date[3] = {getDay(), getMonth(), getYear()};
		
		if(date[0]>hoy[0]){
			if(date[1]>=hoy[1]){
				if(date[2]>=hoy[2]){
					 cout<<"\nThe date of the object is later than the provided date.";
				}
			}
		}
	}

	
	void setDay(int d){day = d;}
	int getDay(){return day;}
	
	void setMonth(int m){month = m;}
	int getMonth(){return month;}
	
	void setYear(int y){year = y;}
	int getYear(){return year;}
};


int main(){
	int d, m, y;
	int a, b, c;
	
	int eleccion;
	fecha manana(d, m, y);
	cout<<"Welcome, this program will ask you for a date between 1-1-1900 y 31-12-2050.";
	cout<<"\nAt the same time";
	manana.leer();
	manana.mostrar();
	manana.bisiesto();
	do{
	cout<<"\n\nChoose the month you would like to know its number of days based in the provided year: ";
	cin>>eleccion;
		if(eleccion<1 or eleccion>12){
			cout<<"\nThe month you provided is not valid, please choose one of the 12 months available.";
		}
	}while(eleccion<1 or eleccion>12);
	manana.diasMes(eleccion);
	manana.formatoLargo();
	manana.siguiente();
	manana.anterior();
	manana.diasTranscurridos();
	cout<<"\nPlease provide the date to be compared to the date of the object.";
	cout<<"\nDay: "; cin>>a;
	cout<<"\nMonth: "; cin>>b;
	cout<<"\nYear: "; cin>>c;
	int hoy[3] = {a, b, c};
	manana.diasEntre(hoy);
	manana.igualQue(hoy);
	manana.mayorQue(hoy);
	manana.menorQue(hoy);
	manana.diaSemana();
	//manana.diasTranscurridos();
	//manana.arreglo();
	
	return 0;
}
