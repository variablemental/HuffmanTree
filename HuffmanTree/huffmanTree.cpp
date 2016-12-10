#include<iostream>
#include"HeapComparable.cpp"
using namespace std;

template<class T>
struct HuffmanTreeNode
{
 typedef HuffmanTreeNode<T> Node;
 T _weight;
 Node *_left;
 Node *_right;
 Node *_parent;
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
	struct Less
	{
		bool operator()(const T& A,const T& B)
		{ return A->_weight<B->_weight;}
	
	}
	template<class T>
	HuffmanTree(T *a,int size,T invalid)	{
		HeapComparable<T,Less<Node*>>	h(a,size);
		while(h.getSize()>1){
			Node *left=h.Top();
			h.Pop();
			Node *right=h.Top();
			h.Pop();
			Node *parent=new Node(left->_weight+right->_weight);
			parent->_left=left;
			parent->_right=right;
			left->_parent=parent;
			right->parent=parent;
			h.Push(parent);
		}
		_root=h.Top();							//只剩下一个元素的话，那个就是最大的和
	}
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
