// STL.cpp: определяет точку входа для консольного приложения.
//


using namespace std;

#include <list>
#include <vector>
#include <iostream>

//предикат для сравнения символов (используется функцией сортировки символов в списке)
bool compare_chars(char c1, char c2)
{
	int coord1, coord2;

	if ('a' <= c1 && c1 <= 'z')
		coord1 = c1 - 'a';
	else
		coord1 = c1 - 'A';

	if ('a' <= c2 && c2 <= 'z')
		coord2 = c2 - 'a';
	else
		coord2 = c2 - 'A';

	return coord1 < coord2;
}

//бинарный поиск в массиве/векторе
template<class T>
int IndexOf_R(vector<T> arr, T elem_to_find, int left, int right)
{
	//неадекватные параметры
	if (left > right)
		return -1;

	//Находим "середину массива"

	//конец поиска - "размер массива" стал равен 0
	if (left == right)
	{
		if (arr[left] == elem_to_find)
			return left;
		return -1;
	}

	//ищем середину "массива"
	int middle = (left + right) / 2;

	//прекращение рекурсии - база рекурсии
	if (arr[middle] == elem_to_find)
		return middle;

	//продолжение рекурсии - вызов той же функции, но с другими параметрами
	if (elem_to_find > arr[middle])
		return IndexOf_R(arr, elem_to_find, middle + 1, right);
	if (elem_to_find < arr[middle])
		return IndexOf_R(arr, elem_to_find, left, middle - 1);
}


bool condition(char c) {
    return c >= 'A' && c <= 'K';
}

template<class T>
void filter(list<T> source, list<T>& result, bool (*cmp)(T)) {
    list<char>::iterator it;
    for (it = source.begin(); it != source.end(); *it++) {
        if (cmp(*it)) result.push_back(*it);
    }
}

int main()
{
    // class work
    list<char> lst;
    for (int i = 0; i < 10; ++i) {
        lst.push_back('E' + 2 * i);
    }
    for (int i = 0; i < 10; ++i) {
        lst.push_back('a' + 2 * i);
    }
    list<char>::iterator it = lst.begin();
    while (it != lst.end()) {
        cout << *it++ << "  ";
    }
    cout << endl;

    list<char> res;
    bool(*fp)(char) = condition;
    filter(lst, res, condition);
    for (it = res.begin(); it != res.end(); ++it) {
        cout << *it << "  ";
    }

    // class work
	//использование вектора и бинарный поиск в нем (он должен быть отсортирован)
	/* vector<int> v;
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		v.push_back(i + 1);
	}
	int res = IndexOf_R(v, 10, 0, v.size());
	cout << "\nResult of IndexOf: " << res << "\n";
	//vector - произвольный доступ
	//list - доступ только с начала или конца: двунаправленный линейный список
	list<char> lst;
	for (i = 0; i < 10; i++)
		lst.push_back('A' + i);

	//итератор - аналог указателя для перемещения по контейнеру
	list<char>::iterator p;
	p = lst.begin();
	while (p != lst.end())
	{
		//перемещение по контейнеру с помощью итератора, нет операции [i]
		cout << *p << "";
		p++;
	}
	cout << "\n";
	lst.clear();
	for (i = 0; i < 10; i++)
		lst.push_front('a' + i);
	for (i = 0; i < 10; i++)
		lst.push_back('Z' - i);
	p = lst.begin();
	while (p != lst.end())
	{
		cout << *p << "";
		p++;
	}
	cout << "\n";
	//передаем функции сортировки адрес функции для сравнения двух элементов (вместо введения operator< между элементами)
	lst.sort(compare_chars);
	//обратите внимание на то, как изменится результат, если её не передавать. Почему так происходит?
	//lst.sort();
	p = lst.begin();
	while (p != lst.end())
	{
		cout << *p << "";
		p++;
	}
	cout << "\n";


	char c; cin >> c;
	return 0; */
}

