#include<iostream>
using namespace std;

template<class T>
struct HuffmanTreeNode
{
 typedef HuffmanTreeNode<T> Node;
 T _weight;
 Node *_left;
 Node *_right;
 Node *_parent;left
 HuffmanTreeNode(const T& _w):_weigth(w),_right(NULL),_left(NULL),_parent(NULL) {};
};


template<class T>
class HuffmanTree
{
typedef HuffmanTreeNode<T> Node; 
public:
	HuffmanTree():_root(NULL){}
	~HuffmanTree(){
		_destroy(_root);
	}

	template<class T>
	
	


protected:
		_destroy(Node *root){
		if(root==NULL)
			return ;
		_destroy(root->left);
		_destroy(root->right);
		delete root;		
	}

private:
	Node *_root;
	
}
