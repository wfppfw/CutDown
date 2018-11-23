#ifndef HUFFMANCODE_NODE_H
#define HUFFMANCODE_NODE_H
#include<iostream>
#include<string>
#include <vector>
using namespace std;
class Huffmancode_node   //¥Ê¥¢◊÷∑˚µƒπ˛∑Ú¬¸±‡¬Î
{
public:
    unsigned char name;  //◊÷∑˚µƒ√˚≥∆
    vector<int> code;    //”√vector»›∆˜¥Ê¥¢π˛∑Ú¬¸±‡¬Î
    Huffmancode_node()
    {
        name = '\0';
    }
};
#endif // HUFFMANCODE_NODE_H
