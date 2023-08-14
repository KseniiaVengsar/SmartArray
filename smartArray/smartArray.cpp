// smartArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

class smart_array {
public:
	//��������� ����������� ����������� � �������� ������������ ����� ���:
	//�������� ��� delete ��������, ��� ���������� ����� ������ �� ����� ���� ����������� ��� ���������
	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;

		//�����������, ���������� ���������� ���������, ������� ����� ������� ������.
		//����� ������ ����������� ��������� ������
	smart_array(int size) : size(size), very_smart_arr(new int[size]) {
			std::cout << "�������� ����������� " << this << std::endl;
		}

	~smart_array() {
//������������� ������
		delete[] very_smart_arr;
		std::cout << "Array destroyed" << std::endl;
	}
	void add_element(int new_element);
	int get_element(int index);

private:
	int size;
	//����� ������
	int* very_smart_arr;
	
};

void smart_array::add_element(int new_element) {
	//������� ���������� ������ �������� � ������. �� �������� ���������� ������, ����� ���������� ��������� ������ ���������� ���������, �� ������� �������� ������.
	//���� ������� �� ����� arr
	//����� ����������� ��������� ���������� ��� ��������� ������
	int newSize = size + 1;
	//���� ����� ������ newArr � ����������� ��������.
	int* newArr = new int[newSize];

	// ����������� ��������� �� ��������� ������� � ����� ������
	for (int i = 0; i < size; i++) {
		newArr[i] = very_smart_arr[i];
	}

	// ���������� ������ �������� � ����� ������ �������
	newArr[newSize - 1] = new_element;

	// ������������ ������, ���������� �������� ��������
	delete[] very_smart_arr;

	// ��������� very_smart_arr ����������� �� ����� ������ newArr
	very_smart_arr = newArr;
	//������ size ����������� �� newSize
	size = newSize;

 }
int smart_array::get_element(int index) {
	//������� ��������� �������� �� �������. �� �������� �������� �� ������������ �������.
	if (index >= 0 && index < size) {
		// ������ ���������, ���������� � �������� �������
		int element = very_smart_arr[index];
		// ���������� �������� � ��������� �������
		return very_smart_arr[index];
		std::cout << "�����: "<<very_smart_arr[index] << std::endl;
	}
	else {
		// ������ �����������, ����������� ����������
		throw std::out_of_range("������������ ������!");
	}

}

int main()
{
	setlocale(LC_ALL, "RU");
	//������ ������ ������ ����� �����, ������� ��������
	//�������� ����� ��� 5-�� ��������
	int ind;
	std::cout << "������� ������ ������ ������� ��� ��������: ";
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

/*����� ���� �������� �� ������� ����������� ������, �� ������ ��������� ����������� ����������� � �������� ������������.
� ��������� ������, ������������ ������ ����� �������� ����������� ��������� �� ���������� ������, 
� ����� ��� ����������� ����� �������� ���������� ������� ������������ ������, � ��������� ������
//��������� ����������� ����������� � �������� ������������ ����� ���:

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
