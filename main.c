// Kniffel
//
// Frauenholz Joshua

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int block[13];
int wuerfel[5];

void startnewgame(void);
void spielregeln(void);
void kombinationen(void);
void spielblock(void);
void versuche(void);
void wuerfeln(void);
void wuerfel_ausgabe(void);
int punkte_eintragen(void);
int punkte_addieren(void);

void hauptmenue(){

    int auswahl;

    printf("#####################################################################################################\n");
    printf("# KNIFFEL - Hauptmenue                                                                              #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# (1) Neues Spiel Starten                                                                           #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# (2) Spielregeln                                                                                   #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# (3) Kombinationen                                                                                 #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# (4) Spielblock anzeigen                                                                           #\n");
    printf("#####################################################################################################\n");
    printf("#  Bitte Menuepunkt auswaehlen!                                                                     #\n");
    printf("#####################################################################################################\n");

    scanf("%d", &auswahl);

    switch(auswahl){
        case 1:
            system("cls");
            startnewgame();
            break;
        case 2:
            system("cls");
            spielregeln();
            break;
        case 3:
            system("cls");
            kombinationen();
            break;
        case 4:
            system("cls");
            spielblock();
            break;
        default:
            exit(0);
    }
}

void startnewgame(){

    for(int i = 0; i < 13; i++){
        block[i] = -1;
    }

    srand(time(NULL));

    int durchlauf = 1;
    char fortsetzen = 'j';

    while(fortsetzen == 'j') {

        printf("#####################################################################################################\n");
        printf("# %d. Durchlauf                                                                                      #\n", durchlauf++);
        spielblock();
        versuche();

        system("cls");
        printf("#####################################################################################################\n");
        printf("# Folgende Wuerfel wurden gewuerfelt:                                                               #\n");
        printf("#---------------------------------------------------------------------------------------------------#\n");
        wuerfel_ausgabe();
        punkte_eintragen();
        getchar();

        printf("#---------------------------------------------------------------------------------------------------#\n");
        printf("# Moechten Sie eine neue Runde wuerfeln? (j/n)                                                      #\n");
        printf("#---------------------------------------------------------------------------------------------------#\n");
        scanf(" %c", &fortsetzen);
        system("cls");

    }

    spielblock();

    printf("\n");

    int ergebnis = 0;

    ergebnis = punkte_addieren();

    printf("#####################################################################################################\n");
    printf("# KNIFFEL - Gesamtpunktzahl                                                                         #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# Herzlichen Glueckwunsch Sie haben %d Punkte erreicht!                                              #\n", ergebnis);
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("#####################################################################################################\n");

    exit(EXIT_SUCCESS);
}

void spielregeln(){

    char auswahl;

    printf("#####################################################################################################\n");
    printf("# KNIFFEL - Spielregeln                                                                             #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# Beim Kniffel werden 5 Wuerfel gewuerfelt. Der Spieler hat drei Wuerfe pro Runde.                  #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# In diesen drei Wuerfen versucht der Spieler eine Kombination zu erwuerfeln.                       #\n");
    printf("# Dabei kann der Spieler bei den ersten beiden Wuerfen entscheiden,                                 #\n");
    printf("# welchen Wuerfel er behalten und welchen Wuerfel er neu Wuerfeln moechte.                          #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# Nach dem dritten Wurf muss ein Feld auf dem Spielblock ausgefuellt werden.                        #\n");
    printf("# Idealerweise natuerlich das, das am meisten Punkte bringt.                                        #\n");
    printf("# Eingetragen muss immer etwas. Hat man beispielweise keine Strasse erreicht,                       #\n");
    printf("# kann man dafuer in einem anderen Feld 0 Punkte eintragen.                                         #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# Das Spiel ist zu Ende, wenn alle Felder auf dem Spielblock ausgefuellt wurden.                    #\n");
    printf("# Dann werden die Punkte zusammengezaehlt:                                                          #\n");
    printf("# Zuerste die Punkte mit den Einern bis zu den Sechsern.                                            #\n");
    printf("# Wen hier mindestens 63 Punkte erreicht wurden, bekommt man 35 Extrapunkte.                        #\n");
    printf("#####################################################################################################\n");
    printf("#  Um zum Hauptmenue zuerueck zukehren bitte die Taste (m) betaetigen!                              #\n");
    printf("#####################################################################################################\n");

    scanf(" %c", &auswahl);

    if(auswahl == 'm'){
        system("cls");
        hauptmenue();
    }
}

void kombinationen(){

    char auswahl;

    printf("#####################################################################################################\n");
    printf("# KNIFFEL - Kombinationen                                                                           #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# 1er - hier werden alle gewuerfelten Einser werden addiert.                                        #\n");
    printf("# 2er - hier werden alle gewuerfelten Zweier werden addiert.                                        #\n");
    printf("# 3er - hier werden alle gewuerfelten Dreier werden addiert.                                        #\n");
    printf("# 4er - hier werden alle gewuerfelten Vierer werden addiert.                                        #\n");
    printf("# 5er - hier werden alle gewuerfelten Fuenfer werden addiert.                                       #\n");
    printf("# 6er - hier werden alle gewuerfelten Sechser werden addiert.                                       #\n");
    printf("# Dreierpasch - mindestens dreimal dieselbe Zahl - alle Augen werden zusammengezaehlt.              #\n");
    printf("# Viererpasch - mindestens viermal dieselbe Zahl - alle Augen werden zusammengezaehlt.              #\n");
    printf("# Full-House - je dreimal und zweimal gleiche Zahlen, 25 Punkte werden in das Feld eintragen.       #\n");
    printf("# Kleine Strasse - Wuerfelkombination von 1-4, 2-5 oder 3-6, 30 Punkte werden in das Feld eintragen.#\n");
    printf("# Grosse Strasse - Wuerfelkombination von 1-5 oder 2-6, 40 Punkte werden in das Feld eintragen.     #\n");
    printf("# Kniffel - fuenfmal die gleiche Zahl, 50 Punkte werden in das Feld eingetragen.                    #\n");
    printf("# Chance - hier muss nichts zusammenpassen. Alle Augen werden zusammengezaehlt.                     #\n");
    printf("#####################################################################################################\n");
    printf("# Um zum Hauptmenue zuerueck zukehren bitte die Taste (m) betaetigen!                               #\n");
    printf("#####################################################################################################\n");

    scanf(" %c", &auswahl);

    if(auswahl == 'm'){
        system("cls");
        hauptmenue();
    }
}

void spielblock(){

    printf("#####################################################################################################\n");
    printf("# KNIFFEL - Spielblock                                                                              #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");

    if(block[0] == -1){
        printf("# 1.)  Einser:                leer                                                                  #\n");
    } else {
        printf("# 1.)  Einser:                %2d Punkte                                                             #\n", block[0]);
    }
    if(block[1] == -1){
        printf("# 2.)  Zweier:                leer                                                                  #\n");
    } else {
        printf("# 2.)  Zweier:                %2d Punkte                                                             #\n", block[1]);
    }
    if(block[2] == -1){
        printf("# 3.)  Dreier:                leer                                                                  #\n");
    } else {
        printf("# 3.)  Dreier:                %2d Punkte                                                             #\n", block[2]);
    }
    if(block[3] == -1){
        printf("# 4.)  Vierer:                leer                                                                  #\n");
    } else {
        printf("# 4.)  Vierer:                %2d Punkte                                                             #\n", block[3]);
    }
    if(block[4] == -1){
        printf("# 5.)  Fuenfer:               leer                                                                  #\n");
    } else {
        printf("# 5.)  Fuenfer:               %2d Punkte                                                             #\n", block[4]);
    }
    if(block[5] == -1){
        printf("# 6.)  Sechser:               leer                                                                  #\n");
    } else {
        printf("# 6.)  Sechser:               %2d Punkte                                                             #\n", block[5]);
    }

    printf("#---------------------------------------------------------------------------------------------------#\n");

    if(block[6] == -1){
        printf("# 7.)  Dreierpasch:           leer                                                                  #\n");
    } else {
        printf("# 7.)  Dreierpasch:           %2d Punkte                                                             #\n", block[6]);
    }
    if(block[7] == -1){
        printf("# 8.)  Viererpasch:           leer                                                                  #\n");
    } else {
        printf("# 8.)  Viererpasch:           %2d Punkte                                                             #\n", block[7]);
    }

    if(block[8] == -1){
        printf("# 9.)  FullHouse:             leer                                                                  #\n");
    } else {
        printf("# 9.)  FullHouse:             %2d Punkte                                                             #\n", block[8]);
    }

    if(block[9] == -1){
        printf("# 10.) kleine Strasse:        leer                                                                  #\n");
    } else {
        printf("# 10.) kleine Strasse:        %2d Punkte                                                             #\n", block[9]);
    }

    if(block[10] == -1){
        printf("# 11.) grosse Strasse::       leer                                                                  #\n");
    } else {
        printf("# 11.) grosse Strasse:        %2d Punkte                                                             #\n", block[10]);
    }

    if(block[11] == -1){
        printf("# 12.) Kniffel:               leer                                                                  #\n");
    } else {
        printf("# 12.) Kniffel:               %2d Punkte                                                             #\n", block[11]);
    }

    if(block[12] == -1){
        printf("# 13.) Chance:                leer                                                                  #\n");
    } else {
        printf("# 13.) Chance:                %2d Punkte                                                             #\n", block[12]);
    }
    printf("#####################################################################################################\n");
}

void versuche(){

    char auswahl;

    printf("# Sie haben pro Runde 3 Versuche:                                                                   #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    wuerfeln();
    printf("# Folgende Wuerfel wurden gewuerfelt:                                                               #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    wuerfel_ausgabe();
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# Sie haben diese Runde noch 2 Versuche um neu zu wuerfeln!                                         #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    printf("# Moechten Sie nochmal wuerfeln? (j/n)                                                              #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    scanf(" %c", &auswahl);

    char tausch[5];
    for(int i = 0; i < 5; i++){
        tausch[i] = '0';
    }

    if(auswahl == 'j'){
        printf("#---------------------------------------------------------------------------------------------------#\n");
        printf("# Welche Wuerfel moechten Sie neu wuerfeln? (Wuerfel 1 bis 5 eintragen, ohne Leerzeichen!)          #\n");
        printf("#---------------------------------------------------------------------------------------------------#\n");
        getchar();

        fgets(tausch, 6, stdin);
        int stelle = 0;

        for(int i = 0; i < strlen(tausch)-1; i++){
            stelle = tausch[i]-48;
            wuerfel[stelle-1] = (rand() % 6) + 1;
        }

        printf("#---------------------------------------------------------------------------------------------------#\n");
        wuerfel_ausgabe();
        printf("#---------------------------------------------------------------------------------------------------#\n");
        printf("# Sie haben diese Runde noch 1 Versuch um neu zu wuerfeln!                                          #\n");
        printf("#---------------------------------------------------------------------------------------------------#\n");
        printf("# Moechten Sie nochmal wuerfeln? (j/n)                                                              #\n");
        printf("#---------------------------------------------------------------------------------------------------#\n");
        scanf(" %c", &auswahl);


        if(auswahl ==  'j'){
            printf("#---------------------------------------------------------------------------------------------------#\n");
            printf("# Welche Wuerfel moechten Sie neu wuerfeln? (Wuerfel 1 bis 5 eintragen, ohne Leerzeichen!)          #\n");
            printf("#---------------------------------------------------------------------------------------------------#\n");
            scanf(" %c", &auswahl);
            fgets(tausch, 10, stdin);

            for(int i = 0; i < strlen(tausch)-1; i++){
                stelle = tausch[i]-48;
                wuerfel[stelle-1] = (rand() % 6) + 1;
            }
        }
    }
}

void wuerfeln(){
    for(int i = 0; i < 5; i++){
        wuerfel[i]= (rand() % 6) + 1;
    }
}

void auswerten(){
    int diceCounts[5] = { 0, 0, 0, 0, 0, 0 };
    int sumOfAllDice = 0;
    int straight = 0;
    int maxStraight = 0;
    bool full = false;
    bool house = false;
    bool kniffel = false;

    for(int i = 0; i < 5; i++){
        if(wuerfel[i] == 1){
            diceCounts[0] += 1;
        }

        if(wuerfel[i] == 2){
            diceCounts[1] += 1;
        }

        if(wuerfel[i] == 3){
            diceCounts[2] += 1;
        }

        if(wuerfel[i] == 4){
            diceCounts[3] += 1;
        }

        if(wuerfel[i] == 5){
            diceCounts[4] += 1;
        }

        if(wuerfel[i] == 6){
            diceCounts[5] += 1;
        }
    }

    for (int i = 0; i < 6; i++) {
        if(diceCounts[i] == 2){
            full = true;
        } else if(diceCounts[i] >= 3){
            house = true;
        } else if(diceCounts[i] >= 4){

        } else if(diceCounts[i] >= 5){
            kniffel = true;
        }
    }
}

void wuerfel_ausgabe(){
    printf("# ");
    for(int i = 0; i < 5; i++){
        printf("| %i ", wuerfel[i]);
    }
    printf("|");
    printf("                                                                             #\n");
}

int punkte_eintragen(){

    int auswahl;
    int augen = 0;
    char benutzt = 'n';

    spielblock();

    printf("# Waehlen Sie nun aus in welches Feld Sie Punkte eintragen moechten:                                #\n");
    printf("#---------------------------------------------------------------------------------------------------#\n");
    scanf("%d", &auswahl);

    do {
        if(block[auswahl-1] == -1){
            benutzt = 'n';
            switch(auswahl){
                case 1: //gewürfelte Einser addieren
                    for(int i = 0; i < 5; i++){
                        if(wuerfel[i] == 1)
                            augen += 1;
                    }
                    block[0] = augen;
                    break;
                case 2: //gewürfelte Zweier addieren
                    for(int i = 0; i < 5; i++){
                        if(wuerfel[i] == 2)
                            augen += 2;
                    }
                    block[1] = augen;
                    break;
                case 3: //gewürfelte Dreier addieren
                    for(int i = 0; i < 5; i++){
                        if(wuerfel[i] == 3)
                            augen += 3;
                    }
                    block[2] = augen;
                    break;
                case 4: //gewürfelte Vierer addieren
                    for(int i = 0; i < 5; i++){
                        if(wuerfel[i] == 4)
                            augen += 4;
                    }
                    block[3] = augen;
                    break;
                case 5: //gewürfelte Fünfer addieren
                    for(int i = 0; i < 5; i++){
                        if(wuerfel[i] == 5)
                            augen += 5;
                    }
                    block[4] = augen;
                    break;
                case 6: //gewürfelte Sechser addieren
                    for(int i = 0; i < 5; i++){
                        if(wuerfel[i] == 6)
                            augen += 6;
                    }
                    block[5] = augen;
                    break;
                case 7: //Dreierpasch drei gleiche + andere zusammenzählen
                    //for(int i = 0; i < 5; i++){
                    //    augen += wuerfel[i];
                    //}
                    block[6] = augen;
                    break;
                case 8: // Viererpasch vier gleiche + anderen zusammenzählen
                    //for(int i = 0; i < 5; i++){
                    //    augen += wuerfel[i];
                    //}
                    block[7] = augen;
                    break;
                case 9: //Fullhouse
                    if(full && house){
                        block[8] = 25;
                    }
                    break;
                case 10:// kleine Strasse
                    block[9] = 30;
                    break;
                case 11:// grosse Strasse
                    if()
                    block[10] = 40;
                    break;
                case 12:// Kniffel : fünf gleiche Zahlen
                    if(kniffel = true){
                        block[11] = 50;
                    }
                    break;
                case 13:// Einfach alle zusammenzählen
                    for(int i = 0; i < 5; i++){
                        augen += wuerfel[i];
                    }
                    block[12] = augen;
                    break;
                default: return 0;
             }   // Ende Switch
        } else {  // Feld schon benutzt
            printf("#---------------------------------------------------------------------------------------------------#\n");
            printf("#Dieses Feld wurde schon benutzt waehlen Sie ein anderes!                                           #\n");
            printf("#---------------------------------------------------------------------------------------------------#\n");
            scanf("%d", &auswahl);
            benutzt = 'j';
        }
}

int punkte_addieren(){
    int punkte = 0;
    int summebonus = 0;
    int bonus = 35;

    for (int i = 0; i < 6; i++){
        if(block[i] != -1){
            summebonus += block[i];
        }
    }

    for(int i = 0; i < 13; i++){
        if(block[i] != -1){
                punkte += block[i];
        }
    }

    if (summebonus >= 63){
        punkte += bonus;
    }

    return punkte;
}

int main(void){

    hauptmenue();

    exit(EXIT_SUCCESS);
}
