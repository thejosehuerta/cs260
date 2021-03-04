#include <stdio.h>
#include <iostream>
#include <string>
#include "Hash.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;
using std::isdigit;

int main(int argc, char **argv) {
    Hash *Hashbrown = new Hash();

    Hashbrown->Insert("Popo");
    Hashbrown->Insert("Poop");
    Hashbrown->Insert("ooPp");
    Hashbrown->Insert("Jose");
    Hashbrown->Insert("Jose1");
 
    Hashbrown->PrintTable();

    Hashbrown->Delete("oPopfdfd");

    Hashbrown->PrintTable();




    return 0;
}