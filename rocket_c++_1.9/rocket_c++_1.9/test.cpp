#if 0

#include <iostream>
using namespace std;
#include <vector>

void TestVector1()
{
	vector<int> v1;//vector();
	               //Constructs an empty container, with no elements.����û��Ԫ�صĿ�����
	vector<int> v2(10, 2);//vector(size_t n, const T& x = T());
				     //���û����ݡ���δ���ݣ�ʹ��ȱʡֵT():T����Ƕ����(Ĭ�����0)��T�ǲ�����Ƕ����(Ĭ������Զ�������)��
					 //Constructs a container with n elements. Each element is a copy of val.�������n��Ԫ�ص�������ÿ��Ԫ�ض���Val�ĸ�����
	vector<int> v3(v2);//vector(vector<T>& v);
					   //��������

	/*int array[] = { 1, 2, 3, 4 };
	vector<int> v4(array, array + sizeof(array)/sizeof(array[0]));*/
	//����һ����������Ԫ�������뷶Χ[��һ�����)��ͬ��ÿ��Ԫ������ͬ��˳��Ӹ÷�Χ�ڵ���ӦԪ���й��졣
					 
	vector<int> v4(v2.begin(), v2.end());//vector(iterator first, iterator last);��������ԭ��ָ̬�롾T*��				 
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
	cout << (v1[0] = 2) << endl;//T& operator[](size_t index);���ط���Ԫ�ص�����
	cout << v2[0] << endl;//const T& operator[](size_t index)const;
	cout << (v1.front() = 3) << endl;//T& front();������Ԫ��
	cout << v2.front() << endl;//const T& front()const;
	cout << (v1.back() = 10) << endl;//T& back();����βԪ��
	cout << v2.back() << endl;//const T& back()const;
}

void TestVector4()
{
	//1 �������ĸ��ԭ��ָ̬�� T*
	//2 ��vector���У���Ƕtypedef T* iterator;   typedef const T* const_iterator;
	//3 ����������  vector<T>::iterator 
	//4 �������ӿڣ�begin()/end()�������������  rbegin()/rend()�������������

	//������ʧЧ����ô�������������ϸ��˵��
}

void TestVector5()
{
	vector<int> v1(5, 3);
	vector<int> v2(3,6);
	v1.reserve(10);
	v1.push_back(1);//void push_back(const T& x)-------O(1)
					//����Ԫ���ڼ䣬���Զ����ݣ�1 �����¿ռ� 2 �������� 3 �ͷžɿռ�
					//���飺�����reserveԤ��һ�οռ�

	v1.pop_back();//void pop_back()-------O(1) 
	
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	vector<int>::iterator it = v1.begin();
	it = v1.insert(pos, 2);//iterator insert(iterator pos, const T& x);-------O(N)
					       //����ֵ�������²����Ԫ����vector�е�λ��

	v1.erase(pos);//iterator erase(iterator pos);-------O(N)

	v1.clear();//void clear();
	v1.swap(v2);//void swap(vector<T>& v);��vector�����Լ�ʵ����һ��������ԭ���ǰ�����ָ�뽻��һ�£��ȿ���ʵ�ֵĽ���Ч�ʸߡ�
}

void test1()//��������ʼ��
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

//ʹ��const������������ӡ
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
	//ʹ��push_back�����ĸ�����
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//ʹ�õ��������б�����ӡ
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//ʹ�õ����������޸�
	it = v1.begin();
	while (it != v1.end()){
		*it *= 2;
		++it;
	}
	PrintVector(v1);

	//ʹ�÷�������������ӡ
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
	//vector<int> v1{ 1, 2, 3, 4 };c++11֧��
	int a[] = { 1, 2, 3, 4 };
	vector<int> v1(a, a + sizeof(a)/sizeof(a[0]));

	//ʹ��find����3����λ�õ�iterator
	//vector<int>::iterator pos = find(v1.begin(), v1.end(), 1);
	
	// ��posλ��֮ǰ����30
	//v1.insert(pos, 30);

	//pos = find(v1.begin(), v1.end(), 1);//posǰ����30��posֵ�Ͳ���ԭ����ֵ������ֱ��ɾ��posλ�õ�ֵ
	//v1.erase(pos);

	// operator[]+index �� C++11��vector����ʽfor+auto�ı���
	// vectorʹ�������ֱ�����ʽ�ǱȽϱ�ݵġ�
	// ͨ��[i]�ķ�ʽ����vector
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
	
	// C++11֧�ֵ���ʽ����
	for (auto x : v2){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

#endif