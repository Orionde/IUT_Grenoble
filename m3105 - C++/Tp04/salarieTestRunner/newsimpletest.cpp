/* 
 * File:   newsimpletest.cpp
 * Author: congiohj
 *
 * Created on 6 oct. 2015, 08:17:28
 */

#include <stdlib.h>
#include <iostream>
#include "Salarie.h"

/*
 * Simple C++ Test Suite
 */

void testSalarie() {
    std::string nom;
    std::string numSS;
    float salaire;
    Salarie salarie(nom, numSS, salaire);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSalarie (newsimpletest) message=error message sample" << std::endl;
    }
}

void testGetImpot() {
    Salarie salarie;
    float result = salarie.getImpot();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetImpot (newsimpletest) message=error message sample" << std::endl;
    }
}

void testGetNom() {
    Salarie salarie;
    std::string result = salarie.getNom();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetNom (newsimpletest) message=error message sample" << std::endl;
    }
}

void testGetNumeroSS() {
    Salarie salarie;
    std::string result = salarie.getNumeroSS();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetNumeroSS (newsimpletest) message=error message sample" << std::endl;
    }
}

void testGetSalaireMensuel() {
    Salarie salarie;
    float result = salarie.getSalaireMensuel();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGetSalaireMensuel (newsimpletest) message=error message sample" << std::endl;
    }
}

void testSetNom() {
    std::string nom;
    Salarie salarie;
    salarie.setNom(nom);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSetNom (newsimpletest) message=error message sample" << std::endl;
    }
}

void testSetNumeroSS() {
    std::string numeroSS;
    Salarie salarie;
    salarie.setNumeroSS(numeroSS);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSetNumeroSS (newsimpletest) message=error message sample" << std::endl;
    }
}

void testSetSalaireMensuel() {
    float salaireMensuel;
    Salarie salarie;
    salarie.setSalaireMensuel(salaireMensuel);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSetSalaireMensuel (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testSalarie (newsimpletest)" << std::endl;
    testSalarie();
    std::cout << "%TEST_FINISHED% time=0 testSalarie (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGetImpot (newsimpletest)" << std::endl;
    testGetImpot();
    std::cout << "%TEST_FINISHED% time=0 testGetImpot (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGetNom (newsimpletest)" << std::endl;
    testGetNom();
    std::cout << "%TEST_FINISHED% time=0 testGetNom (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGetNumeroSS (newsimpletest)" << std::endl;
    testGetNumeroSS();
    std::cout << "%TEST_FINISHED% time=0 testGetNumeroSS (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGetSalaireMensuel (newsimpletest)" << std::endl;
    testGetSalaireMensuel();
    std::cout << "%TEST_FINISHED% time=0 testGetSalaireMensuel (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testSetNom (newsimpletest)" << std::endl;
    testSetNom();
    std::cout << "%TEST_FINISHED% time=0 testSetNom (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testSetNumeroSS (newsimpletest)" << std::endl;
    testSetNumeroSS();
    std::cout << "%TEST_FINISHED% time=0 testSetNumeroSS (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testSetSalaireMensuel (newsimpletest)" << std::endl;
    testSetSalaireMensuel();
    std::cout << "%TEST_FINISHED% time=0 testSetSalaireMensuel (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

