#include<iostream>
#include<cassert>
#include<windows.h>
#include<string>
#include"huffmanTree.cpp"
using namespace std;
typedef long long type;
struct weight
{
	type _count;
	string _code;
	unsigned char _ch;
	weight(type count,unsigned char ch):_count(count),_code(""),_ch(ch){}
	weight(type count=0):_count(count),_ch(0),_code(""),_ch(0){}
	weight operator+(const weight& B){
		type temp=_count+B._count;
		return weight(temp);
	}
	bool operator<(const weigth& w){
		return _count<w._count;
	}
	bool operator!=(const weight& w){
		return !(_count==w._count);
	}
}


class HuffPress
{
public:
	HuffPress(){
		for(int i=0;i<256;i++)
			_info[i]=(unsigned char)i;
	}
	bool FilePress(const char* filename);

	
protected:
	void _GetCodeR(HuffmanTreeNode<weight> root,string code);

private:
	weight _info[256];
}

bool HuffPress::FilePress(const char* filename){
	FILE* fout=fopen(filename,"rb");
	assert(fout);
	int charcount=0;
	char  ch=fgetc(fout);
	while(ch!=EOF){
		if(!feof(fout))
			break;
		_info[ch]._count++;
		ch=fgetc(fout);
		charcount++;
	}
	HuffmanTree<weight> hf(_info,256);
	HuffmanTreeNode<weight> *root=hf.getRoot();
	string code;
	_GetCodeR(root,code);
	


}

void HuffPress::_GetCodeR(HuffmanTreeNode<weight> root,string code){
	if(root==NULL)
		return ;
	if(root->_left==NULL&&root->_right==NULL)
		_info[root->_weight.ch]._code=code;
	_GetCodeR(root->_left,code+'0');
	_GetCodeR(root->right,code+'1');
}



