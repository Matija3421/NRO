#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // Definiramo sezname v katere bo program zapisal vrednosti x, vrednosti funkcije pri x in odvode v točki x
    std::vector<double> seznamx;
    std::vector<double> seznamf;
    std::vector<double> seznamodvodov;
    double odvod;
    
    // Sepcificiramo ime datoteke iz katere beremo podatke
    std::string filename = "poly.txt";

    // Odpremo specificirano datoteko
    std::ifstream file(filename);

    // Program preveri, če mu je uspelo odpreti datoteko, če mu ni vrne error
    if (!file.is_open()) {
        std::cerr << "ERROR pri odpiranju datoteke: " << filename << std::endl;
        return 1;
    }
    
    
    
    // Program prebere vsako vrstico in izloči podatke desno od dvopičja
    std::string line1;
    while (std::getline(file, line1)) {
        // Poišče položaj dvopičja
        size_t colonPos1 = line1.find(':');

        
            // Program ekstrahira vse desno od dvopičja
        std::string contentAfterColon1 = line1.substr(colonPos1 + 1);


        // Definiramo premenljivki v kateri bo program shranil vrednosti x in f(x) 
        std::istringstream iss1(contentAfterColon1);
        double x1, f1;

        // Program izloči podatek iz prvega stolpca, torej x in podatek iz drugega stolpca torej f(x)
        if (iss1 >> x1 >> f1) {
            // Program podatek iz prvega stolpca zapiše v seznam xov in podatek iz drugega stolpca v seznam vrednosti funkcije
        seznamx.push_back(x1);
        seznamf.push_back(f1);
        }

    }
    

    // Program zapre datoteko iz katere beremo podatke
    file.close();
    
    // Program iterira po seznamih vrednosti x in f(x)
    for (size_t i = 0; i < seznamx.size(); ++i) {
        // Če računamo odvod prvega elementa seznama, računamo odvod naprej in ga pripnemo v seznam odvodov
        if (i==0){
            odvod=(-3*seznamf[i]+4*seznamf[i+1]-seznamf[i+2])/(seznamx[i+2]-seznamx[i]);
            seznamodvodov.push_back(odvod);
            
        }
        // Če računamo odvod zadnjega elementa seznama, računamo odvod nazaj in ga pripnemo v seznam odvodov
        else if(i==seznamx.size()-1){
            odvod=(3*seznamf[i]-4*seznamf[i-1]+seznamf[i-2])/(seznamx[i]-seznamx[i-2]);
            seznamodvodov.push_back(odvod);
            
        }
        // Sicer računamo odvode po klasični centralni shemi in ga pripnemo v seznam odvodov
        else{
            odvod=(seznamf[i+1]-seznamf[i-1])/(seznamx[i+1]-seznamx[i-1]);
            seznamodvodov.push_back(odvod);
            
        }
        
    }
    
    // Program nam izpiše izračunane odvode iz seznama odvodov
    std::cout << "Izračunani odvodi so: " << std::endl;
    for (size_t i = 0; i < seznamodvodov.size(); ++i) {
        std::cout << seznamodvodov[i] << std::endl;
    }
    
    
    // Ustvarimo datoteko diff_poly.txt, v katero bo program zapisal vrednosti odvodov
    std::string filepath = "diff_poly.txt";
     
    std::ofstream outputFile(filepath);
    
    if (!outputFile.is_open()) {
        std::cerr << "Težava pri ustvarjanju datoteke: " << filepath << std::endl;
        return 1; 
    }

    // Program vsak element seznama odvodv zapiše v novo vrstico datoteke diff_poly.txt
    for (const double& value : seznamodvodov) {
        outputFile << value << std::endl;
    }

    // Zapremo datoteko diff_poly.txt
    outputFile.close();

    
    return 0;
}
