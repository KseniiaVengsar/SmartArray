// smartArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

class smart_array {
public:
	//Запретить конструктор копирования и оператор присваивания можно так:
	//помечены как delete означает, что экземпляры этого класса не могут быть скопированы или присвоены
	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;

		//Конструктор, принмающий количество элементов, которое будет хранить массив.
		//здесь должно происходить выделение памяти
	smart_array(int size) : size(size), very_smart_arr(new int[size]) {
			std::cout << "Вызвался конструктор " << this << std::endl;
		}

	~smart_array() {
//высвобождение памяти
		delete[] very_smart_arr;
		std::cout << "Array destroyed" << std::endl;
	}
	void add_element(int new_element);
	int get_element(int index);

private:
	int size;
	//умный массив
	int* very_smart_arr;
	
};

void smart_array::add_element(int new_element) {
	//Функция добавления нового элемента в массив. Не забудьте обработать случай, когда количество элементов больше количества элементов, на которую выделена память.
	//если выходим за рамки arr
	//можно попробовать выбросить исключение или увеличить массив
	int newSize = size + 1;
	//Созд новый массив newArr с увеличенным размером.
	int* newArr = new int[newSize];

	// Копирование элементов из исходного массива в новый массив
	for (int i = 0; i < size; i++) {
		newArr[i] = very_smart_arr[i];
	}

	// Добавление нового элемента в конец нового массива
	newArr[newSize - 1] = new_element;

	// Освобождение памяти, занимаемой исходным массивом
	delete[] very_smart_arr;

	// Указатель very_smart_arr назначается на новый массив newArr
	very_smart_arr = newArr;
	//Размер size обновляется на newSize
	size = newSize;

 }
int smart_array::get_element(int index) {
	//Функция получения элемента по индексу. Не забудьте проверку на корректность индекса.
	if (index >= 0 && index < size) {
		// Индекс корректен, обращаемся к элементу массива
		int element = very_smart_arr[index];
		// Дальнейшие действия с элементом массива
		return very_smart_arr[index];
		std::cout << "Ответ: "<<very_smart_arr[index] << std::endl;
	}
	else {
		// Индекс некорректен, выбрасываем исключение
		throw std::out_of_range("Некорректный индекс!");
	}

}

int main()
{
	setlocale(LC_ALL, "RU");
	//создаём объект класса смарт эррей, передаём параметр
	//содержит место для 5-ти элеменов
	int ind;
	std::cout << "Введите индекс умного массива для проверки: ";
	std::cin >> ind;
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(ind) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}

/*Чтобы даже случайно не удалось скопировать массив, вы можете запретить конструктор копирования и оператор присваивания.
В противном случае, пользователь класса может случайно скопировать указатель на выделенную память, 
и тогда при уничтожении обоих объектов произойдет двойное освобождение памяти, и программа упадет
//Запретить конструктор копирования и оператор присваивания можно так:

	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
