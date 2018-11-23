#include"ComAndEx.h"
#include<vector>
void ComAndEx::Compress(string iname,string oname)
{
    string outfilename = iname;
    ScanCharacter(iname); //…®√Ë‘¥Œƒº˛÷÷◊÷∑˚µƒ÷÷¿‡º∞∏ˆ ˝£¨∑µªÿ‘¥Œƒº˛µƒŒƒº˛√˚≤¢”√string¿‡–Õ±‰¡ø±£¥Ê
    if (outfilename == "NULL") return;
    CreateHuffmanTree(); //ππ‘Ïπ˛∑Ú¬¸ ˜
    CreateHuffmanCode(); //…˙≥…π˛∑Ú¬¸±‡¬Î

    string filename;
    filename = oname;
    ofstream out(filename, ios::binary);
    if (!out)
    {
        cout << "Œƒº˛¥Úø™ ß∞‹.." << endl;
        return;
    }
    out.write((char*)&H_number, sizeof(int));
    for (int i = 1; i <= H_number; ++i)//“¿¥Œ ‰»Î◊÷∑˚º∞◊÷∑˚µƒ∆µ∂»
    {
        out.write((char*)&(HuffmanTree[i].name), sizeof(char));
        out.write((char*)&(HuffmanTree[i].weight), sizeof(int));
    }
    ifstream in(outfilename, ios::binary);//µ⁄∂˛±È…®√Ë‘¥Œƒº˛
    if (!in)
    {
        cout << "¥Úø™‘¥Œƒº˛ ß∞‹" << endl<<endl;
        return;
    }
    unsigned char char_temp = '\0';//”√8ŒªµƒŒﬁ∑˚∫≈±‰¡ø◊˜Œ™∂¡–¥◊÷∑˚µƒµ•‘™
    string unit;//¥Ê¥¢π˛∑Ú¬¸±‡¬Î£¨±‡¬Îµƒ∏ˆ ˝¥Û”⁄µ»”⁄∞ÀŒªæÕ∫Õchar_tempΩ¯––|≤Ÿ◊˜
    while (true)
    {
        char_temp=in.get();//‘⁄‘≠Œƒº˛÷–∂¡»°“ª∏ˆ◊÷∑˚
        if (in.eof()) break;//≈–∂œ «∑ÒµΩ¥ÔŒƒº˛µƒƒ©Œ≤
        for (int i = 1; i <= H_number; ++i)//‘⁄¥Ê»°π˛∑Ú¬¸±‡¬Îµƒ ˝◊È÷–’“µΩ∏√◊÷∑˚∂‘”¶µƒ±‡¬Î≤¢Ω´±‡¬Î¥Ê¥¢µΩunit÷–
        {
            if (Huffmancode[i].name == char_temp)
            {
                for (auto elem : Huffmancode[i].code)//œÚunit÷– ‰»Î±‡¬Î
                {
                    if (elem == 1)
                        unit.push_back('1');
                    else
                        unit.push_back('0');
                }
                break;
            }
        }
        while (unit.length() >= 8)//»Áπ˚unit÷–¥Ê¥¢µƒπ˛∑Ú¬¸±‡¬ÎµƒŒª ˝¥Û”⁄µ»”⁄8£¨æÕΩ´«∞∞ÀŒªÕ®π˝Œª≤Ÿ◊˜–¥»Îchar_temp÷–
        {
            char_temp = '\0';
            for (int i = 0; i < 8; ++i)
            {
                char_temp =char_temp<< 1;
                if (unit[i] == '1')
                    char_temp = char_temp | 1;
            }
            auto p = unit.begin();
            unit.erase(p, p + 8);//«Âø’unit÷–µƒ«∞∞ÀŒª±‡¬Î
            out.write((char*)&char_temp, sizeof(unsigned char));//Ω´‘ÿ”–π˛∑Ú¬¸±‡¬Î–≈œ¢µƒ◊÷∑˚–¥»ÎµΩ—πÀıŒƒº˛÷–»•
        }
    }
    if (unit.length() > 0)//¥¶¿Ì◊Ó∫Û≤ª◊„∞ÀŒªµƒπ˛∑Ú¬¸±‡¬Î
    {
        char_temp = '\0';
        for (auto i = 0; i < unit.length(); ++i)
        {
            char_temp = char_temp << 1;
            if (unit[i] == '1')
                char_temp = char_temp | 1;
        }
        for (auto i = 0; i < (8 - unit.length()); ++i)//Ω´±‡¬Î“∆µΩµΩ∏ﬂŒª
            char_temp = char_temp << 1;
        out.write((char*)&char_temp, sizeof(unsigned char));
    }
    in.close();
    out.close();
    //—πÀıŒƒº˛ÕÍ≥…£¨Ω´π˛∑Ú¬¸ ˜µƒ ˝◊È∫Õ¥Ê¥¢π˛∑Ú¬¸±‡¬Îµƒ ˝◊Èµƒƒ⁄¥Ê Õ∑≈µÙ£¨≤¢Ω´◊÷∑˚µƒ÷÷¿‡ ˝÷√Œ™0
    HuffmanTree.resize(0);
    Huffmancode.resize(0);
    H_number = 0;
}

//…˙≥…π˛∑Ú¬¸±‡¬Îµƒ∫Ø ˝
void ComAndEx::CreateHuffmanCode()
{
    Huffmancode_node elem;
    Huffmancode.push_back(elem);
    if (H_number == 1)
    {
        Huffmancode.push_back(elem);
        Huffmancode[1].name =HuffmanTree[1].name;
        Huffmancode[1].code.push_back(1);
    }
    for (int i = 1; i <= H_number; ++i)
    {
        Huffmancode.push_back(elem);
        Huffmancode[i].name = HuffmanTree[i].name;
        int temp_p = HuffmanTree[i].p;
        int temp_nodeindex = HuffmanTree[i].Hnodeindex;
        auto p = Huffmancode[i].code.end();
        while (temp_p != 0)
        {
            if (HuffmanTree[temp_p].lchild == temp_nodeindex)
            {
                p=Huffmancode[i].code.insert(p, 0);
            }
            else
            {
                p=Huffmancode[i].code.insert(p, 1);
            }
            temp_nodeindex = HuffmanTree[temp_p].Hnodeindex;
            temp_p = HuffmanTree[temp_p].p;
        }
    }
}

//ππ‘Ïπ˛∑Ú¬¸ ˜µƒ∫Ø ˝
void ComAndEx::CreateHuffmanTree()
{
    if (H_number == 1)
    {
        HuffmanTree[1].lchild = HuffmanTree[1].rchild = 1;
    }
    int mark = H_number + 1;
    int x = 0, y = 0;
    int min = 999999999, secmin = 0;
    while (mark < 2 * H_number)
    {
        for (int j = 1; j < mark; ++j)
        {
            if (HuffmanTree[j].p == 0 && HuffmanTree[j].weight<min)
            {
                y = x;
                secmin = min;
                min = HuffmanTree[j].weight;
                x = HuffmanTree[j].Hnodeindex;
            }
            else if (HuffmanTree[j].p == 0 && HuffmanTree[j].weight < secmin)
            {
                secmin = HuffmanTree[j].weight;
                y = HuffmanTree[j].Hnodeindex;
            }
            else;
        }
        HuffmanTree[mark].weight = HuffmanTree[x].weight + HuffmanTree[y].weight;
        HuffmanTree[mark].lchild = x;
        HuffmanTree[mark].rchild = y;
        HuffmanTree[x].p = mark;
        HuffmanTree[y].p = mark;
        mark++;
        x = y = 0;
        min = 99999999999, secmin = 0;
    }
    HuffmanTree[2 * H_number - 1].p = 0;
}

//…®√Ë‘≠Œƒº˛÷–◊÷∑˚µƒ÷÷¿‡º∞∆µ∂»µƒ∫Ø ˝
void ComAndEx::ScanCharacter(string iname)
{
    string filename = iname;

    ifstream in(filename,ios::binary);//“‘∂˛Ω¯÷∆µƒ∏Ò Ω¥Úø™‘¥Œƒº˛
    if (!in)                          //ºÏ≤È÷∏∂®µƒ‘¥Œƒº˛ «∑Ò¥Ê‘⁄
    {
        cout << "√ª”–∑¢œ÷∏√Œƒº˛.." << endl<<endl;
        return ;
    }
    unsigned char temp = '\0';  //”√“ª∏ˆ8ŒªµƒŒﬁ∑˚∫≈±‰¡ø¿¥“¿¥Œ∂¡»°‘¥Œƒº˛µƒ–≈œ¢
    Hnode *temparry = new Hnode[256];  //¥¥Ω®“ª∏ˆ¡Ÿ ± ˝◊È£¨”√”⁄Õ≥º∆◊÷∑˚µƒ÷÷¿‡º∞∆µ∂»
    while (true)           //≈–∂œ «∑ÒµΩ¥ÔŒƒº˛µƒƒ©Œ≤
    {
        temp = in.get();
        if (in.eof())break;
        temparry[temp].name = temp;
        temparry[temp].weight++;
    }
    in.close();  //πÿ±’in”Î‘¥Œƒº˛µƒπÿ¡™
    Hnode elem;
    HuffmanTree.push_back(elem);// πµ√π˛∑Ú¬¸”––ßµƒ¥Ê¥¢ «¥”HuffmanTree[1]ø™ º
    H_number = 0;
    for (int i = 0; i < 256; i++)//—°‘Ò≥ˆ∆µ∂»¥Û”⁄0µƒ◊÷∑˚¥Ê¥¢µΩπ˛∑Ú¬¸ ˝◊È÷–
    {
        if (temparry[i].weight != 0)
        {
            H_number++;//Õ≥º∆◊÷∑˚µƒ÷÷¿‡ ˝
            HuffmanTree.push_back(elem);
            *(HuffmanTree.end()-1) = temparry[i];
        }
    }
    if (HuffmanTree.size()== 1)
    {
        cout << "ƒ˙ ‰»ÎµƒŒƒ±æŒ™ø’Œƒ±æ.." << endl << endl;
        return ;
    }
    delete[]temparry;//Õ≥º∆ÕÍ±œ“‘∫Û Õ∑≈¡Ÿ ± ˝◊Èµƒƒ⁄¥Ê
    for (int i = 1; i <= (H_number - 1); i++)//Œ™“∂Ω⁄µ„µƒÀ´«◊Ω⁄µ„ø™±Ÿƒ⁄¥Ê
    {
        HuffmanTree.push_back(elem);
    }
    for (int i = 0; i < 2 * H_number; i++)//Œ™π˛∑Ú¬¸ ˝◊ÈµƒÀ˘”–‘™ÀÿΩ®¡¢À˜“˝
    {
        HuffmanTree[i].Hnodeindex = i;
    }

}
void ComAndEx::Extract(string iname,string oname)
{

    string filename = iname;

    ifstream in(filename, ios::binary);
    if (!in)
    {
        cout << "Œƒº˛¥Úø™ ß∞‹.." << endl;
        return;
    }
    in.read((char*)&H_number,sizeof(int));//∂¡»°◊÷∑˚÷÷¿‡ ˝
    Hnode elem;
    HuffmanTree.push_back(elem);
    for (int i = 1; i <= H_number; ++i)//∂¡»°◊÷∑˚µƒ÷÷¿‡º∞∆µ∂»
    {
        HuffmanTree.push_back(elem);
        in.read((char*)&(HuffmanTree[i].name), sizeof(char));
        in.read((char*)&(HuffmanTree[i].weight), sizeof(int));
    }
    for(int i=1;i<=H_number-1;++i)//Ω®¡¢ÕÍ’˚µƒπ˛∑Ú¬¸ ˝◊È
        HuffmanTree.push_back(elem);
    for (int i = 0; i < 2 * H_number; i++)//Œ™π˛∑Ú¬¸ ˝◊È‘™ÀÿΩ®¡¢À˜“˝
    {
        HuffmanTree[i].Hnodeindex = i;
    }
    CreateHuffmanTree();//…˙≥…π˛∑Ú¬¸ ˜
    unsigned  char temp_char = '\0';//”√¿¥∂¡»°π˛∑Ú¬¸±‡¬Îµƒµ•Œª
    unsigned long long length = 0;
    for (int i = 1; i <= H_number; ++i)//º∆À„‘≠Œƒº˛µƒ◊÷∑˚µƒ∏ˆ ˝
        length = length + HuffmanTree[i].weight;
    int top = HuffmanTree[2 * H_number - 1].Hnodeindex;//top¥Ê¥¢µƒ «Ω·µ„µƒÀ˜“˝£¨≥ı ºªØ ±∏˘Ω⁄µ„µƒÀ˜“˝

    string extractedname = oname;

    ofstream out(extractedname,ios::binary);
    if (!out)
    {
        cout << "∏√Œƒº˛¥Úø™ ß∞‹.." << endl<<endl;
        return;
    }
    while(length)
    {
        temp_char = in.get();//
        for (int i = 0; i<8;++i)
        {
            if (temp_char & 128)//»Áπ˚◊Ó∏ﬂŒªŒ™1
                top = HuffmanTree[top].rchild;//top¥Ê¥¢Ω·µ„µƒ”“∫¢◊”µƒÀ˜“˝
            else
                top = HuffmanTree[top].lchild;//»Áπ˚◊Ó∏ﬂŒªŒ™0£¨top¥Ê¥¢Ω·µ„µƒ◊Û∫¢◊”µƒÀ˜“˝
            if (top <=H_number)//»Áπ˚¥”∏˘Ω⁄µ„µΩ¥Ô“∂Ω⁄µ„
            {
                out <<HuffmanTree[top].name;// ‰≥ˆ◊÷∑˚
                length--;//∏¸–¬‘≠Œƒº˛÷–Œ¥ ‰≥ˆµƒ◊÷∑˚µƒ∏ˆ ˝
                if (length ==0 )break;//»Áπ˚‘≠Œƒº˛÷–Œ¥ ‰≥ˆµƒ∏ˆ ˝Œ™0£¨±Ì√˜‘≠Œƒº˛µƒ◊÷∑˚“—æ≠»´≤ø ‰≥ˆ£¨—≠ª∑≤ª–Ë“™‘ŸºÃ–¯
                top = HuffmanTree[2 * H_number - 1].Hnodeindex;//∑Ò‘Útop∏¥ŒªŒ™∏˘Ω⁄µ„µƒÀ˜“˝
            }
            temp_char = temp_char << 1;//»Áπ˚√ªµΩ¥Ô“∂Ω⁄µ„£¨ƒ«√¥temp_char◊Û“∆“ªŒª£¨ºÃ–¯—≠ª∑
        }
    }
    in.close();
    out.close();
    //—πÀıŒƒº˛ÕÍ≥…£¨Ω´π˛∑Ú¬¸ ˜µƒ ˝◊È∫Õ¥Ê¥¢π˛∑Ú¬¸±‡¬Îµƒ ˝◊Èµƒƒ⁄¥Ê Õ∑≈µÙ£¨≤¢Ω´◊÷∑˚µƒ÷÷¿‡ ˝÷√Œ™0
    HuffmanTree.resize(0);
    Huffmancode.resize(0);
    H_number = 0;
}
