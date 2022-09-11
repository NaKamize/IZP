#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


//funkcia ma 3 paramtetre  a to ukazovatele na charakter meno,argument,cislo
//switch porovnava poziciu znaku na indekse i s jednotlivimi znakmi, ktore su konvertovane na male znake pomocou funkcie tolower
//switch prepina argument na indexe j
//ak najde zhodu inkrementuje pocket, zresetuje cyklus, a najde zhodu

int najdiMena(char *meno, char *argument, char *cislo) {
    int pocet = 0;
    int dlzka = (int) strlen(meno);     //dlzka pole mien
    int dlzka1 = (int) strlen(argument); //dlzka argumentu
    bool kontrolaResetu = false;

    for (int i = 0; i < dlzka; i++) {
        bool zhoda = false;
        for (int j = pocet; j < dlzka1; j++) {
            if (zhoda) {        //ak nastane zhoda resetuje cyklus
                break;
            }
            switch (argument[j]) {
                case '0':
                    if (tolower(meno[i]) == '+' || meno[i] == '0') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '1':
                    if (tolower(meno[i] == '1')) {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '2':
                    if (tolower(meno[i]) == 'a' || tolower(meno[i]) == 'b' || tolower(meno[i]) == 'c' || meno[i] == '2') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '3':
                    if (tolower(meno[i]) == 'd' || tolower(meno[i]) == 'e' || tolower(meno[i]) == 'f' || meno[i] == '3') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '4':
                    if (tolower(meno[i]) == 'g' || tolower(meno[i]) == 'h' || tolower(meno[i]) == 'i' || meno[i] == '4') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '5':
                    if (tolower(meno[i]) == 'j' || tolower(meno[i]) == 'k' || tolower(meno[i]) == 'l' || meno[i] == '5') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '6':
                    if (tolower(meno[i]) == 'm' || tolower(meno[i]) == 'n' || tolower(meno[i]) == 'o' || meno[i] == '6') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '7':
                    if (tolower(meno[i]) == 'p' || tolower(meno[i]) == 'q' || tolower(meno[i]) == 'r' ||
                        tolower(meno[i]) == 's' || meno[i] == '7') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '8':
                    if (tolower(meno[i]) == 't' || tolower(meno[i]) == 'u' || tolower(meno[i]) == 'v' || meno[i] == '8') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
                case '9':
                    if (tolower(meno[i]) == 'w' || tolower(meno[i]) == 'x' || tolower(meno[i]) == 'y' ||
                        tolower(meno[i]) == 'z' || meno[i] == '9') {
                        pocet++;
                        kontrolaResetu = true;
                        zhoda = true;
                    }
                    else {
                        if (kontrolaResetu) {
                            j = 0;
                            pocet = 0;
                            zhoda = false;
                            kontrolaResetu = false;
                        }
                    }
                    break;
            }

        }

    }

    if (dlzka1 == pocet) {      //ak sa dlzka argumentu zhoduje s poctom vypisuje meno, inak vracia 0
        printf("%.*s, %s", (int) strlen(meno) - 1, meno, cislo);
        return 1;
    } else {
        return 0;
    }


}

//ak najde cislo, ktore sa zhoduje s argumentov vypise prislusne kontakty
//inak vola funkciu, ktora hlada podla mien
int najdiCisla(char *cislo, char *argument, char *meno) {
    char *nasielCislo = strstr(cislo, argument);        // do nasielCislo sa uklada najdene cislo
    if (nasielCislo) {
        printf("%.*s, %s", (int) strlen(meno) - 1, meno, cislo);
        return 1;
    } else {
        return najdiMena(meno, argument, cislo);        //hlada argument medzi menami
    }
}


int main(int argc, char *argv[]) {
    char meno[1000];    //premena pre pole mien
    char cislo[1000];   //premenna pre pole cisiel
    char *premena = argv[1];        //ulozenie si argumentu do premennej
    int najdenychKontaktov = 0;     //inicializacia premennej, hovori o tom ci bol nejaky kontakt najdeny alebo nie

    if (argc > 2)    //ak sa prekroci pocet argumentov tak vypise chybove hlasenie a vrati 1
    {
        fputs("Zadal si privela argumentov!\n", stderr);
        return 1;
    }

    while (fgets(meno, 999, stdin) != NULL)         //nacistanie miem pomocou funkcie fgets
    {
        if (fgets(cislo, 999, stdin) != NULL)   //nacitanie cisiel do pola cisiel
        {
            if (argc == 2)                  //ak ma program pocet argumentov 2 tak na vstupe hlada podla postupnosti cisiel, alebo mien
            {
                if (najdiCisla(cislo, premena, meno) == 1) {    //volanie funkcie pre vypis
                    najdenychKontaktov++;
                }

            } else                            //ak program ma ako argument textovy dokument, vypiseho
            {
                printf("%.*s, %s", (int) strlen(meno) - 1, meno, cislo);
                najdenychKontaktov = -1; //preto -1, aby spravne vypisal cisto txt dokument
            }
        }
    }
    if (najdenychKontaktov == 0) {  // podmienka pre vypis Not found
        printf("Not found\n");
    }
    return 0;
}

