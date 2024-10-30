﻿#include <iostream>
#include "Node.h" // Предполагается, что ваш класс List объявлен в этом заголовочном файле

int main() {
    setlocale(LC_ALL, "ru");
    // Создание пустого списка
    List myList;

    // Ввод элементов в список
    int n;
    std::cout << "Введите количество элементов для добавления в список: ";
    std::cin >> n;
    myList.Scan(n); // Метод для ввода n элементов в список

    // Печать списка
    std::cout << "Содержимое списка: ";
    myList.Print(); // Метод для печати списка

    // Добавление элементов в список
    myList.AddToHead(10); // Добавляем элемент в голову
    myList.AddToTail(20); // Добавляем элемент в хвост

    // Печать списка после добавления
    std::cout << "После добавления элементов: ";
    myList.Print();

    // Поиск максимального и минимального элемента
    Node* maxNode = myList.Max();
    Node* minNode = myList.Min();
    if (maxNode) {
        std::cout << "Максимальный элемент: " << maxNode->Key() << std::endl;
    }
    else {
        std::cout << "Список пуст, максимальный элемент не найден." << std::endl;
    }
    if (minNode) {
        std::cout << "Минимальный элемент: " << minNode->Key() << std::endl;
    }
    else {
        std::cout << "Список пуст, минимальный элемент не найден." << std::endl;
    }

    // Удаление элемента с головы и хвоста
    myList.DelHead();
    myList.DelTail();

    // Печать списка после удаления
    std::cout << "После удаления головы и хвоста: ";
    myList.Print();

    // Проверка на равенство двух списков
    List anotherList;
    std::cout << "Введите количество элементов для второго списка: ";
    std::cin >> n;
    anotherList.Scan(n); // Ввод второго списка

    if (myList == anotherList) {
        std::cout << "Списки равны." << std::endl;
    }
    else {
        std::cout << "Списки не равны." << std::endl;
    }

    // Очистка списка
    myList.Clear();
    std::cout << "После очистки списка: ";
    myList.Print();

    return 0;
}