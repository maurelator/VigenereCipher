/*
* Kouekam Maurel A00223808
*/
// VigenereCipher.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//algorithme du chiffrement polyalphabetique de Vigenere
void vigenereCipherToFile(string texte_clair, string cle) {
    //Chiffrement

    string texte_chiffre = "";
    int cle_index = 0;//variable qui contiendra les indices de la cle secrete de chiffrement
    for (int i = 0; i < texte_clair.length(); i++) {
        //A chaque fois on recupere le caractere du texte en clair a chiffre en fonction du caractere de la cle secrete 
        char c = texte_clair[i];
        //On teste si le caractere est une lettre alphabetique ou pas
        if (isalpha(c)) {
            // Convertir le caractère en minuscule pour les calculs
            c = tolower(c);
            char decalage = cle[cle_index];
            decalage = tolower(decalage) - 'a';//On calcule la valeur du nombre de positions de decalage
            // Calculer le nouveau caractère chiffré
            c = 'a' + (c - 'a' + decalage) % 26;
            // Ajouter le caractère chiffré au texte chiffré
            texte_chiffre += c;
            // Avancer l'index de la clé, en bouclant si nécessaire
            cle_index = (cle_index + 1) % cle.length();
        }
        else {
            // Ajouter les caractères non alphabétiques tels quels
            texte_chiffre += c;
        }
    }

    //Ecriture dans le fichier texte

    ofstream myfile("text-chiffre.txt");
    if (myfile) {
        myfile << texte_chiffre;
        myfile.close();
        cout << "Le texte a ete chiffre dans le fichier text-chiffre.txt" << endl;
    }
    else {
        cout << "Erreur: impossible d'ouvrir le fichier text-chiffre.txt" << endl;
    }
}

//algorithme du Dechiffrement polyalphabetique de Vigenere
void vigenereDecipherToFile(string texte_chiffre, string cle) {
    //Déchiffrement

    string texte_clair = "";
    int cle_index = 0;//variable qui contiendra les indices de la cle secrete de chiffrement
    for (int i = 0; i < texte_chiffre.length(); i++) {
        //A chaque fois on recupere le caractere du texte chiffre a dechiffrer en fonction du caractere de la cle secrete 
        char c = texte_chiffre[i];
        //On teste si le caractere est une lettre alphabetique ou pas
        if (isalpha(c)) {
            // Convertir le caractère en minuscule pour les calculs
            c = tolower(c);
            char decalage = cle[cle_index];
            decalage = tolower(decalage) - 'a';//On calcule la valeur du nombre de positions de decalage
            // Calculer le nouveau caractère déchiffré
            c = 'a' + (c - 'a' - decalage + 26) % 26;
            // Ajouter le caractère déchiffré au texte déchiffré
            texte_clair += c;
            // Avancer l'index de la clé, en bouclant si nécessaire
            cle_index = (cle_index + 1) % cle.length();
        }
        else {
            // Ajouter les caractères non alphabétiques tels quels
            texte_clair += c;
        }
    }

    //Ecriture dans le fichier texte

    ofstream myfile("text-clair.txt");
    if (myfile) {
        myfile << texte_clair;
        myfile.close();
        cout << "Le texte a ete dechiffre dans le fichier text-clair.txt" << endl;
    }
    else {
        cout << "Erreur: impossible d'ouvrir le fichier text-clair.txt" << endl;
    }
}


int main() {
    
    string texte = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum eget neque vitae nisl convallis mollis. Fusce varius felis justo, sit amet placerat dui congue vel. Integer dapibus sapien id ipsum pharetra, non congue lacus interdum. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Cras eget lacus ut massa vestibulum bibendum in sed mauris.";
    string cle = "vigenere";
    vigenereCipherToFile(texte, cle);

    //Maintenant on dechiffre avec le texte chiffre du lorem de tout a l'heure 

    texte = "gwxiz mgwpu jsysi wdb gqrx, tsiakggikym ijmcmjgdvm iymk. zzazmoycyh mmig rvupm bmgev rdar gbrmegtow zscpda. lyfgv zvzoyf jvpda pyfxf, wdb gqrx gpvkkvnx uyd kurtyv zzt. orgixim lgtvflw nivmrr zh dxyyz tyemmzvn, rfr xwtkhi cexcy maxvvycs. trpciibkwdyv lvjoxnrk qjzhm gvzwoqwyr wvrzkzyf ik rzbaw rx degmyynhr jvukw ng kymxow rkvwoiy. geej ibmz pnglw pb sefwr zzazmoycyh jofrruyh qt wrh depzow.";
    cle = "vigenere";
    vigenereDecipherToFile(texte, cle);
  
}

