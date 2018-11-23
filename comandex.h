#ifndef COMANDEX_H
#define COMANDEX_H
#include<vector>
#include"Hnode.h"
#include"Huffmancode_node.h"
#include<iostream>
#include<fstream>
using namespace std;
class ComAndEx   //—πÀıΩ‚—π¿‡µƒÕ∑Œƒº˛
{
public:
    void Compress(string iname,string oname); //—πÀıŒƒº˛µƒ∫Ø ˝
    void Extract(string iname,string oname);  //Ω‚—πŒƒº˛µƒ∫Ø ˝
    void ScanCharacter(string iname);//…®√Ë‘¥Œƒº˛÷÷◊÷∑˚µƒ÷÷¿‡º∞∏ˆ ˝
    void CreateHuffmanTree();//Ω®¡¢π˛∑Ú¬¸ ˜
    void CreateHuffmanCode();//…˙≥…π˛∑Ú¬¸±‡¬Î
protected:
    vector<Hnode> HuffmanTree;  //¥Ê¥¢π˛∑Ú¬¸ ˜µƒ ˝◊È
    vector<Huffmancode_node>Huffmancode;  //¥Ê¥¢π˛∑Ú¬¸±‡¬Îµƒ ˝◊È
    int H_number; //◊÷∑˚µƒ÷÷¿‡ ˝
};

#endif // COMANDEX_H
