#include <iostream>

typedef int Data;
class FIFO_1
{
	int maxsize;                                    //максимальное кол-во размеров очереди
	Data* Array;                                    // одномерный массив где всё хранится
	int item;                                       //текущий
public:


	FIFO_1(Data s) {                                //конструктор с заданием колличества элементов в циклической очереди
		maxsize = s;
		Array = new Data[maxsize]{ NULL };
		item = 0;
	};
	~FIFO_1() {
		delete[]Array;
	};
private:
	void _insert(Data d) {                           //вставка элемента
		if (item == maxsize)
			item = 0;
		Array[item] = d;
		item++;
	}
	void _Show() {                                  //показ текущего элемента
		if (item == maxsize) {
			item = 0;
		}
		std::cout << Array[item] << std::endl;
		item++;
	}
	void _Remove() {                                  //удаление текущего элемента(замена на 0)
		if (item == maxsize)
			item = 0;
		Array[item] = NULL;
		item++;
	}
	void _next(int n = 1) {
		item += n;
		if (item >= maxsize)
			item - maxsize;
	}

	void _expansion() {                                 //расширение круга на 1
		maxsize++;                                    //на 1 увеличим размер круга
		int* Array_new = new int[maxsize];             //новый массив на замену старому
		for (int i = 0; i < maxsize - 1; i++)          //по-элементное копирование
			Array_new[i] = Array[i];
		Array_new[maxsize - 1] = 0;                    //последний элемент - новый равен 0
		delete[]Array;                                 //отчистка памяти
		Array = Array_new;                             //переназначение адреса массива
	}

	void _narrowing() {                                //сужение круга на 1
		maxsize--;
		int* Array_new = new int[maxsize];
		for (int i = 0; i < maxsize; i++)
			Array_new[i] = Array[i];
		delete[]Array;
		Array = Array_new;
	}
public:                                                      //интерфейс
	void Insert(Data d) {
		_insert(d);
	}
	void Show() {
		_Show();
	}
	void Remove() {
		_Remove();
	}
	void Expansion() {
		_expansion();
	}
	void Narrowing() {
		_narrowing();
	}
	void Next(int n = 1) {
		_next(n = 1);
	}
};
