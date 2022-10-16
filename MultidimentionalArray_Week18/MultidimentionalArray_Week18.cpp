
#include <Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;
//Задание 1. Написать программу, которая дает пользователю ввести 5 фамилий студентов, 
// а затем сортирует их по возрастанию.

void Task1_Sotring(char* arr[]);
void Task1_Print(char** arr);
void Task1_CreateAndEnter();

//Создание массива
void Task1_CreateAndEnter() {
    char** arr = new char*[5];
    for (int i = 0; i < 5; i++) {
        system("cls");
        cout << "Enter surname of " << i+1 <<  " student:\n";
        arr[i] = new char[100];
        gets_s(arr[i],100);
    }
    system("cls");
    //Для наглядности показ изначального массива
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
    cout << endl << endl;

    Task1_Sotring(arr);
}
//Сортировка
void Task1_Sotring(char* arr[]) {
    char* temp; 
    //Пузырькова сортировка
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (strlen(arr[j]) > strlen(arr[j + 1])) {  //метод strcmp() неадекватно работал (или я идиот)
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    Task1_Print(arr);
}
//Показ отсортированного массива
void Task1_Print(char** arr) {
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
}

//-----End of Task 1
//Задание 2. Есть 3 двумерных массива A, B, C. Количество строк и столбцов для них 
//вводит пользователь с клавиатуры для каждого из них. Реализуйте
//■■Создайте одномерный массив, который содержит общие значения для A, B, C;
//■■Создайте одномерный массив, который содержит уникальные значения для A, B, C;
//■■Создайте одномерный массив, который содержит общие значения для A и C;
//■■Создайте одномерный массив, который содержит отрицательные значения для A, B, C без повторений.

//Массивы будут int, лишь потому, что - да.


//Да да да, я создал структуру :)
struct Arrays {
    int m = 1;
    int n = 1;
    int** arr = new int* [m]; 
};

void Task2_FillArrays(int** arr, int m, int n);
void Task2_GlobalElements(Arrays* arra);
void Task2_UniqueElements(Arrays* arra);
void Task2_GlobalElementsArr1Arr3(Arrays* arra);
void Task2_NegativeElements(Arrays* arra);

//Создание массивов ручишками пользователя
void Task2_CreateArrays() {
    Arrays arra[3];

    cout << "Enter a size the arr1(M,N): \n";
    cin >> arra[0].m >> arra[0].n; //Вводим размеры массива
    arra[0].arr = new int* [arra[0].m]; // Заново инициализируем массив с новым размером
    for (int i = 0; i < arra[0].m; i++) {
        arra[0].arr[i] = new int[arra[0].n]; //Инициализация подмассивов массива
    }
    Task2_FillArrays(arra[0].arr, arra[0].m, arra[0].n); //Заполнение массива (каждый по отдельности)

    cout << "Enter a size the arr2(M,N): \n";
    cin >> arra[1].m >> arra[1].n;
    arra[1].arr = new int* [arra[1].m];
    for (int i = 0; i < arra[1].m; i++) {
        arra[1].arr[i] = new int[arra[1].n];
    }
    Task2_FillArrays(arra[1].arr, arra[1].m, arra[1].n);

    cout << "Enter a size the arr3(M,N): \n";
    cin >> arra[2].m >> arra[2].n;
    arra[2].arr = new int* [arra[2].m];
    for (int i = 0; i < arra[2].m; i++) {
        arra[2].arr[i] = new int[arra[2].n];
    }
    Task2_FillArrays(arra[2].arr, arra[2].m, arra[2].n); 
    Task2_GlobalElements(arra);
    Task2_UniqueElements(arra);
    Task2_GlobalElementsArr1Arr3(arra);
    Task2_NegativeElements(arra);
}
//Заполнение массивов
void Task2_FillArrays(int** arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            system("cls");
            cout << "Enter element " << i << " M, " << j << " N:\n";
            cin >> arr[i][j];
        }
    }
    system("cls");
}
//Общие элементы всех массивов
void Task2_GlobalElements(Arrays* arra) {
    int globalSize = arra[0].m * arra[0].n + arra[1].m * arra[1].n + arra[2].m * arra[2].n;
    int* generalArr = new int[globalSize];
    //Вносим всё в один массив для удобства
    cout << "All elements of arrs: \n";
    for (int t = 0, k = 0; t < 3; t++) {
        for (int i = 0; i < arra[t].m; i++) {
            for (int j = 0; j < arra[t].n; j++) {
                generalArr[k] = arra[t].arr[i][j];
                cout << generalArr[k] << " ";
                k++;
            }
        }
    }
    cout << endl << endl;
    int s = 0;
    int* generalElements = new int[globalSize/2]; //Подумал, что будет менее затратно, нежели идентичный
    for (int i = 0; i < globalSize; i++) {        //ниже цикл проверки размера временного массива
        for (int j = i+1; j < globalSize; j++) {
            if (generalArr[i] == generalArr[j]) {  //Проверка на тождественность
                for (int g = 0; g < s+1; g++) {              //Проверка на повторение
                    if (generalElements[g] == generalArr[i]) {                   
                        break;                                                   
                    }                                                            
                    else {
                        generalElements[s] = generalArr[i];
                        s++;
                        break;
                    }
                 break;
                }
                
            }
        }
    }
    cout << "Global Elements of all arrs: \n"; 
    for (int i = 0; i < s; i++) { 
        cout << generalElements[i] << " ";  //Вывод элементов
    }
    delete[] generalElements;
    delete[] generalArr;
    cout << "\n\n";
}
//Уникальные элементы всех массивов
void Task2_UniqueElements(Arrays* arra) {
    int globalSize = arra[0].m * arra[0].n + arra[1].m * arra[1].n + arra[2].m * arra[2].n;
    int* UniqueArr = new int[globalSize];
    //Вносим всё в один массив для удобства
    for (int t = 0, k = 0; t < 3; t++) {
        for (int i = 0; i < arra[t].m; i++) {
            for (int j = 0; j < arra[t].n; j++) {
                UniqueArr[k] = arra[t].arr[i][j];
                k++;
            }
        }
    }
    int s = 0;
    int* UniqueElements = new int[globalSize];
    for (int i = 0, temp = 0; i < globalSize; i++) {         //temp служит знаком, что число уникальное, т.е
        for (int j = 0; j < globalSize; j++) {               //ведёт подсчет повторений одного числа
            if (UniqueArr[i] == UniqueArr[j] and i != j)   //i != j, чтобы UniqueArr[i] не считало само себя, как за повтор
                temp++;         
            }
        if (temp == 0) {                   
            UniqueElements[s] = UniqueArr[i];
            s++;
        }
        temp = 0;
    }
    cout << "Unique Elements of all arrs: \n";
    for (int i = 0; i < s; i++) {
        cout << UniqueElements[i] << " ";
    }
    delete[] UniqueElements;
    delete[] UniqueArr;
    cout << "\n\n\n";
}
//Общие элементы массивов 1 и 2
void Task2_GlobalElementsArr1Arr3(Arrays* arra) {
    int globalSize = arra[0].m * arra[0].n + arra[2].m * arra[2].n;
    int* generalArr = new int[globalSize];
    //Вносим всё в один массив для удобства
    cout << "All elements of arr1 and arr3: \n";
    for (int t = 0, k = 0; t < 3; t+=2) {
        for (int i = 0; i < arra[t].m; i++) {
            for (int j = 0; j < arra[t].n; j++) {
                generalArr[k] = arra[t].arr[i][j];
                cout << generalArr[k] << " ";
                k++;
            }
        }
    }
    cout << endl << endl;
    int s = 0;
    int* generalElements = new int[globalSize / 2]; //Принцип абсолютно тождествен прошлому, но лишь на два массива.
    for (int i = 0; i < globalSize; i++) {          //см. "void Task2_UniqueElements(Arrays* arra)" (строка 122)
        for (int j = i + 1; j < globalSize; j++) {
            if (generalArr[i] == generalArr[j]) {
                for (int g = 0; g < s + 1; g++) {
                    if (generalElements[g] == generalArr[i]) {
                        break;
                    }
                    else {
                        generalElements[s] = generalArr[i];
                        s++;
                        break;
                    }
                    break;
                }

            }
        }
    }
    cout << "Global Elements of arr1 and arr2: \n";
    for (int i = 0; i < s; i++) {
        cout << generalElements[i] << " ";
    }
    delete[] generalElements;
    delete[] generalArr;
    cout << "\n\n";
}
//Отрицательные элементы всех массивов
void Task2_NegativeElements(Arrays* arra) {
    int globalSize = arra[0].m * arra[0].n + arra[1].m * arra[1].n + arra[2].m * arra[2].n;
    int* NegativeArr = new int[globalSize];
    //Вносим всё в один массив для удобства
    for (int t = 0, k = 0; t < 3; t++) {
        for (int i = 0; i < arra[t].m; i++) {
            for (int j = 0; j < arra[t].n; j++) {
                NegativeArr[k] = arra[t].arr[i][j];
                k++;
            }
        }
    }
    int s = 0;
    int* NegativeElements = new int[globalSize];
    for (int i = 0,temp = 0; i < globalSize; i++) {  //Вновь переменная temp,
        if (NegativeArr[i] < 0) {                    //но на сей раз для того же, что и прежде (см. строка 166):
            for (int j = 0; j < s; j++) {            //Есть ли уже тождественные значения в массиве NegativeElements
                if (NegativeElements[j] == NegativeArr[i]) {
                    temp++;
                    break;
                }
            }
            if (temp == 0) {
                NegativeElements[s] = NegativeArr[i];
                s++;
            }
            temp = 0;
        }
    }
    cout << "Negative Elements of all arrs: \n";
    for (int i = 0; i < s; i++) {
        cout << NegativeElements[i] << " ";
    }
    delete[] NegativeElements;
    delete[] NegativeArr;
}



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Task1
 
    //Task1_CreateAndEnter();

    //Task2
    //Task2_CreateArrays();
}


