

#include "Polinom.h"
#include<string.h>


// It was more practical to overload << and >> as friends
std::ostream& operator<<(std::ostream& os, const Polinom& x) {
	os << "Gradul polinomului este: " << x.length << "\n";
	unsigned n = x.length;
	for (; n > 0; n--)
		if (x.coef[n] > 0)
			os << "+" << x.coef[n-1] << "*x^" << n-1;
		else if (x.coef[n-1] < 0)
			os << x.coef[n-1] << "*x^" << n-1;
    //returnam o referinta catre originalul istream pentru a putea afisa cout<<a<<b<<etc
	return os;
}

std::istream& operator>>(std::istream& is, Polinom& x){
    std::cout<<"Introduceti gradul polinomului: ";
    is>>x.length;
    std::cout<<"Introduceti coeficientii polinomului separati printr-un spatiu, de la mare la mic \n";
    unsigned n=x.length;
    std::vector<double> coef;
    //alocare memorie pentru cele n pozitii 
    coef.resize(n);

    for(;n>0;n--){
        double item;
        is>>item;
        coef.push_back(item);
    }
    x.coef=coef;
    //is>>x[n-1]; nu merge din cauza nivelului de acces
    //returnam o referinta catre originalul istream pentru a putea citii cin>>a>>b>>etc
    return is;
}

int main()
{
	//numbers of polymons read by user
	int poly_len;

	std::cout<<"Introduceti numarul de polinoame pe care doriti sa le citi: ";
    std::cin>>poly_len;
    std::cout<<"\n cititi cele "<<poly_len<<" polinoame\n";

    Polinom poly_arr[poly_len];
    for(int i=0;i<poly_len;i++){
        std::cout<<"\n polinomul #"<<i<<"\n";
        Polinom x;
        std::cin>>x;
        poly_arr[i]=x;

    }
    std::cout<<"##### Indexarea se face de la 0 #####\n#### Dupa efectuarea unei operatii matematice va fi afisat rezultatul fara salvare\n";
    std::cout<<"Instructiuni de folosire:\n"<<"1. Pentru afisarea unui polinom spefic introduceti 'arata_specific' urmat pe linia urmatoare de index";
    std::cout<<"\n 2. Pentru afisarea tuturor polinoamelor citie introduceti 'arata'";
    std::cout<<"\n 3. Pentru operatiile matematice ridicare la putere ^ ,adunare +,scadere -,inmultire * , introduceti prima oara";
    std::cout<<"semnul specific operatiei matematice , urmat pe linia urmatoare de indexul celor doua polinoame";
    std::cout<<"\n 4. Pentru suma intr-un punct introduceti 'suma' ,urmat pe linia urmatoare de indexul polinomului si punctul in care sa fie calculat";
    std::cout<<"\n 5. Pentru a verifica daca doua polinoame sunt egale introduceti 'egal' ,urmat pe linia urmatoare de indexul celor 2 polinoame";
    std::cout<<"\n 6. Pentru a verifica daca doua polinoame sunt diferite introduceti 'diferit' ,urmat pe linia urmatoare de indexul celor 2 polinoame";
    std::cout<<"\n 7. Pentru a verifica daca un polinom este nenul introduceti 'nenul' ,urmat pe linia urmatoare de indexul polinomului respectiv";
    std::cout<<"\n 8. Pentru afisarea unui coeficient specific dintr-un polinom selectat introduceti 'arata_coef' , urmat pe linia urmatoare de indexul polinomului si gradul sau";
    std::cout<<"\n 9. Pentru a copia un polinom introduceti 'copiere', urmat pe linia urmatoare de indexul destinatie si indexul cu informatie";
    std::cout<<"\n 10. Pentru a iesi din program tastati 'stop' \n";
    std::string io_instruction;
    unsigned io_index1,io_index2;
    double point;
    int io_pow;
    //loop used for interactive menu
    // cin blocks the main thread until the user inputs something so it will not overflow
    while(true){
        std::cin>>io_instruction;
        if(io_instruction.length()==1){
            //math operation
            if(io_instruction=="+"){
                std::cout<<"cititi index1, index2, separate printr-un spatiu: ";
                std::cin>>io_index1>>io_index2;
                std::cout<<poly_arr[io_index1]+poly_arr[io_index2];

            }else if(io_instruction=="-"){
                std::cout<<"cititi index1, index2, separate printr-un spatiu: ";
                std::cin>>io_index1>>io_index2;
                std::cout<<poly_arr[io_index1]-poly_arr[io_index2];


            }else if(io_instruction=="*"){
                std::cout<<"cititi index1, index2, separate printr-un spatiu: ";
                std::cin>>io_index1>>io_index2;
                std::cout<<poly_arr[io_index1]*poly_arr[io_index2];


            }else if(io_instruction=="^"){
                std::cout<<"cititi index si puterea , separate printr-un spatiu: ";
                std::cin>>io_index1>>io_pow;
                const Polinom &x=poly_arr[io_index1]^io_pow;
                std::cout<<x;

            }else{
                std::cout<<"Instructiune incorecta";
            }
        }else if(io_instruction=="arata"){
            for(int i=0;i<poly_len;i++){
                std::cout<<"\n Polinomul #"<<i<<"\n";
                std::cout<<poly_arr[i];
            }
        }else if(io_instruction=="arata_specific"){
            std::cout<<"\n introduceti indexul:";
            std::cin>>io_index1;
            std::cout<<poly_arr[io_index1];
        }else if(io_instruction=="egal"){
            std::cout<<"\n introduceti indexul celor 2 polinoame, separate prin spatiu";
            std::cin>>io_index1>>io_index2;
            if(io_index1==io_index2)
                std::cout<<"sunt egale";
            else
                std::cout<<"nu sunt egale";
        }else if(io_instruction=="copiere"){
            std::cout<<"\n introduceti indexul celor 2 polinoame, separate prin spatiu";
            std::cin>>io_index1>>io_index2;
            poly_arr[io_index1]=poly_arr[io_index2];

        }else if(io_instruction=="diferit"){
            std::cout<<"\n introduceti indexul celor 2 polinoame, separate prin spatiu";
            std::cin>>io_index1>>io_index2;
            if(io_index1!=io_index2)
                std::cout<<"nu sunt egale";
            else
                std::cout<<"sunt egale";

        }else if(io_instruction=="arata_coef"){
            std::cout<<"\n introduceti coeficientul: ";
            std::cin>>io_index1>>io_index2;
            std::cout<<poly_arr[io_index1][io_index2];
        }else if(io_instruction=="suma"){
            std::cout<<"\n introduceti indexul si punctul, separate printr-un spatiu";
            std::cin>>io_index1>>point;
            std::cout<<"suma este: "<<poly_arr[io_index1].GetSum(point);
        }else if(io_instruction=="stop"){
            break;
        }else{
            std::cout<<"\n instructiune invalida";
        }
    }
	return 0;
}

