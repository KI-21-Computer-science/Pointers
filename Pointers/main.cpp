#include <iostream>

int Sum(int* array, int size)
{
    int result = 0;

    for (int i = 0; i < size; i++)
    {
        result += array[i];
    }

    return result;
}

int* Modify(int* array, int size)
{
    int* newArray = new int[size];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i] * 2;
    }

    return newArray;
}

int main()
{
    int* p = new int { 10 }; // создание объекта типа int в куче через оператор new

    std::cout << "Address of p: " << p << std::endl; // выводим адрес указателя
    std::cout << "Value of p: " << *p << std::endl; // выводим значение, которое лежит по адресу указателя в памяти через разименовывание (*p)

    int* array = nullptr;
    int n;

    std::cout << "Input count of elements: ";
    std::cin >> n;

    array = new int[n]; // создание динамического массива

    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
    }

    // получение указателя на новый массив из функции 
    int* newArray = Modify(array, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << newArray[i] << " ";
    }

    // очистка памяти для объекта НЕ массива и зануление указателя
    delete p;
    p = nullptr;

    // очистка памяти для объекта массива и зануление указателя
    delete[] newArray;
    newArray = nullptr;

    // создание массива символов, инициализация его строковым литералом
    // можно с таким массивом работать как с обычной строкой (string)
    char* char_array = new char[13] { "Hello world!" };
    // в динамической памяти можно инициализировать объекты любого типа

    return 0;
}