#if 0

#include <iostream>
using namespace std;
#include <vector>

void TestVector1()
{
	vector<int> v1;//vector();
	               //Constructs an empty container, with no elements.构造没有元素的空容器
	vector<int> v2(10, 2);//vector(size_t n, const T& x = T());
				     //【用户传递】【未传递：使用缺省值T():T是内嵌类型(默认填充0)，T是不是内嵌类型(默认填充自定义类型)】
					 //Constructs a container with n elements. Each element is a copy of val.构造具有n个元素的容器。每个元素都是Val的副本。
	vector<int> v3(v2);//vector(vector<T>& v);
					   //拷贝构造

	/*int array[] = { 1, 2, 3, 4 };
	vector<int> v4(array, array + sizeof(array)/sizeof(array[0]));*/
	//构造一个容器，其元素数量与范围[第一，最后)相同，每个元素以相同的顺序从该范围内的相应元素中构造。
					 
	vector<int> v4(v2.begin(), v2.end());//vector(iterator first, iterator last);迭代器：原生态指针【T*】				 
}

void TestVector2()
{
	vector<int> v1(5, 1);
	cout << v1.size() << endl;//size_t size()const;
	cout << v1.capacity() << endl;//size_t capacity()const;
	cout << v1.empty() << endl;//bool empty()const;
	v1.resize(10, 2);//void resize(size_t n, const T& x = T());
	v1.reserve(20);//void reserve(size_t n);
}

void TestVector3()
{
	vector<int> v1(5, 1);
	const vector<int> v2(5, 5);
	cout << (v1[0] = 2) << endl;//T& operator[](size_t index);返回访问元素的引用
	cout << v2[0] << endl;//const T& operator[](size_t index)const;
	cout << (v1.front() = 3) << endl;//T& front();返回首元素
	cout << v2.front() << endl;//const T& front()const;
	cout << (v1.back() = 10) << endl;//T& back();返回尾元素
	cout << v2.back() << endl;//const T& back()const;
}

void TestVector4()
{
	//1 迭代器的概念：原生态指针 T*
	//2 在vector类中，内嵌typedef T* iterator;   typedef const T* const_iterator;
	//3 迭代器类型  vector<T>::iterator 
	//4 迭代器接口：begin()/end()【正向迭代器】  rbegin()/rend()【反向迭代器】

	//迭代器失效？怎么解决？【后续详细解说】
}

void TestVector5()
{
	vector<int> v1(5, 3);
	vector<int> v2(3,6);
	v1.reserve(10);
	v1.push_back(1);//void push_back(const T& x)-------O(1)
					//插入元素期间，会自动增容：1 申请新空间 2 拷贝数据 3 释放旧空间
					//建议：最好先reserve预留一段空间

	v1.pop_back();//void pop_back()-------O(1) 
	
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	vector<int>::iterator it = v1.begin();
	it = v1.insert(pos, 2);//iterator insert(iterator pos, const T& x);-------O(N)
					       //返回值：返回新插入的元素在vector中的位置

	v1.erase(pos);//iterator erase(iterator pos);-------O(N)

	v1.clear();//void clear();
	v1.swap(v2);//void swap(vector<T>& v);【vector里面自己实现了一个交换，原理是把三个指针交换一下，比库里实现的交换效率高】
}

void test1()//迭代器初始化
{
	int array[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v1(array, array + sizeof(array)/sizeof(array[0]));

	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
		cout << " " << *it;
	}
	cout << "\n";
}

#if 0
int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	//TestVector5();
	//test1();
	return 0;
}
#endif

//使用const迭代器遍历打印
void PrintVector(const vector<int>& v)
{
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

#if 0
int main()
{
	vector<int> v1;
	//使用push_back插入四个数据
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//使用迭代器进行遍历打印
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//使用迭代器进行修改
	it = v1.begin();
	while (it != v1.end()){
		*it *= 2;
		++it;
	}
	PrintVector(v1);

	//使用反向迭代器反向打印
	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend()){
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	return 0;
}
#endif

void test()
{
	vector<int> v1;
	size_t sz = v1.capacity();
	for (size_t i = 0; i < 100; ++i){
		v1.push_back(i);
		if (sz != v1.capacity()){
			sz = v1.capacity();
			cout << "v1.capacity()" << sz << endl;
		}
	}
}

#if 0
int main()
{
	test();
	return 0;
}
#endif

int main()
{
	// find / insert / erase
	//vector<int> v1{ 1, 2, 3, 4 };c++11支持
	int a[] = { 1, 2, 3, 4 };
	vector<int> v1(a, a + sizeof(a)/sizeof(a[0]));

	//使用find查找3所在位置的iterator
	//vector<int>::iterator pos = find(v1.begin(), v1.end(), 1);
	
	// 在pos位置之前插入30
	//v1.insert(pos, 30);

	//pos = find(v1.begin(), v1.end(), 1);//pos前插入30后，pos值就不是原来的值，不能直接删除pos位置的值
	//v1.erase(pos);

	// operator[]+index 和 C++11中vector的新式for+auto的遍历
	// vector使用这两种遍历方式是比较便捷的。
	// 通过[i]的方式遍历vector
	for (size_t i = 0; i < v1.size(); ++i){
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int> v2{ 5, 6, 7, 8 };
	v2.swap(v1);

	cout << "v1: ";
	for (size_t i = 0; i < v1.size(); ++i){
		cout << v1[i] << " ";
	}
	cout << endl;

	cout << "v2: ";
	for (size_t i = 0; i < v2.size(); ++i){
		cout << v2[i] << " ";
	}
	cout << endl;
	
	// C++11支持的新式遍历
	for (auto x : v2){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

#endif