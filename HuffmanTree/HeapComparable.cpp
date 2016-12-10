#include<iostream>
using namespace std;
template<class T,class K>
class Heap
{
public:
	void show_heap();
	void Push(T value);
	T Top();
	T Pop();
	int getSize();
	Heap():_size(0),_capicity(10){}
	Heap(T* data ,int size);
	~Heap(){}
protected:
	void shift_up(int cursor);
	void shift_down(int start,int end);

private:
	
	T* heap;
	K comparator;
	int _capicity;
	int _size;
};

template<class T,class K>
Heap<T,K>::Heap(T* data ,int size)
{
	this->_size=size;
	heap=new T[size];
	for(int i=0;i<size;i++)
		heap[i]=data[i];
	for(int i=size/2-1;i>=0;i--){		//确保i指向父节点的一层
		shift_down(i,_size-1);			//建堆就是一个下滤的过程
	}
}

template<class T,class K>
void Heap<T,K>::Push(T values)
{
	if(_size>=_capicity)
		return ;
	heap[_size]=values;
	shift_up(_size);
	_size++;
}

template<class T,class K>
T Heap<T,K>::Pop()
{
	if(_size==0)
		return ;
	T result=heap[0];
	heap[0]=heap[_size-1];
	_size--;
	shift_down(0,_size-1);
}

template<class T,class K>
void Heap<T,K>::shift_down(int start,int end)		//下滤
{
	int i=start;
	int j=i*2+1;
	T temp=heap[i];
	while(j<=end){
		if(j+1<end&&comparator(heap[j+1],heap[j])==1)
			j++;
		if(comparator(temp,heap[j])==0){
			heap[i]=heap[j];	
		}else
			break;
		i=j;
		j=j*2+1;
	}
	heap[i]=temp;						//重要，因为i已经过度到后面的j了，所以i的位置一直是空档
}

template<class T,class K>
void Heap<T,K>::shift_up(int cursor)			//上滤
{
	int i=(cursor-1)/2;					//i初始化为上滤下界的一半的位置，确保可以得到父节点
	int j=cursor;
	T temp=heap[i];
	while(i>=0){
		if(j+1<_size&&comparator(heap[j+1],heap[j])==1)   //兄弟节点之间比较大小，选择较为小的那个
			j++;
		if(comparator(heap[i],heap[j]))
			break;
		else{
			heap[j]=heap[i];			
		}
		j=i;						//j获得i的位置
		i=(i-1)/2;					//i向上迭代
	}
	heap[j]=temp;					//同上面的思路一样，这次j是一个空档，只是保留了原i的数据
}

template<class T,class K>
void Heap<T,K>::show_heap()
{
	for(int i=0;i<_size;i++){
		cout<<heap[i]<<",";
	}
	cout<<endl;
}

template<class T,class K>
T Heap<T,K>::Top()
{
if(_size>0)
	return heap[0];
cout<<"empty heap!"<<endl;
return NULL;
}

template<class T,class K>
int Heap<T,K>::getSize()
{
return _size;
}

template<class G>
struct Less
{
	bool operator()(const G& A,const G& B){
		return A<B;
	}

};



int main(int *args[])
{
	int test[10]={7,5,82,56,66,71,1,6,25,14};
	Heap< int,Less<int> > h(test,(int)(sizeof(test)/sizeof(int)));
	h.show_heap();
}

