#ifndef HNODE_H
#define HNODE_H
class Hnode  //π˛∑Ú¬¸ ˜µƒ¥Ê¥¢¥Ê¥¢Ω·ππ
{
public:
    unsigned char name;    //8Œªµƒ¥Ê¥¢µ•‘™¿¥¥Ê¥¢◊÷∑˚£®256÷÷£©
    unsigned  weight;  //¥Ê¥¢◊÷∑˚µƒ∆µ∂»
    int p; //À´«◊Ω⁄µ„
    int lchild; //◊Û∫¢◊”
    int rchild; //”“∫¢◊”
    int Hnodeindex;  //Ω⁄µ„À˜“˝
    Hnode() //≥ı ºªØ ˝æ›≥…‘±
    {
        name = '\0';
        weight = 0;
        p = 0;
        Hnodeindex = 0;
        lchild = rchild = 0;
    }
};
#endif // HNODE_H
