#include <iostream>
#include <ctime>
#include <cstdlib>
    double* mem(double *ptr, int len){
        ptr = new double[len];
        return ptr;
}
 
    void fill2(double *ptr, int len){
        for(int i=0;i<len;i++){
            std::cin >> ptr[i];
        }
}
 
    void show2(double *ptr, int len){
        for(int i=0;i<len;i++){
            std::cout << ptr[i] << " " << "\n";
        }
}
 
    void del2(double *ptr){
        delete[] ptr;
        ptr = nullptr;
}

void fill3(int* array3, int len3) {
    std::cout << "Введите 12 чисел: " << std::endl;
    for (int i = 0; i < len3; i++) {
        std::cin >> array3[i];
    }
}
void change3(int* array3, int len3)
{
    int t3;
    for (int i = 0; i < len3; i+=2) {
        t3 = array3[i];
        array3[i] = array3[i+1];
        array3[i + 1] = t3;
    }
}
void show3(int* array3, int len3) {
    for (int i = 0; i < len3; i++) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;
}

// Функция для заполнения двумерного динамического массива случайными числами от min до max
void fillArray(int** array, int rows, int cols, int min, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % (max - min + 1) + min;
        }
    }
}
// Функция для показа двумерного динамического массива на экран
void displayArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция выполнения операции сложения
int add(int a, int b) {
    return a + b;
}
 
// Функция выполнения операции вычитания
int subtract(int a, int b) {
    return a - b;
}
 
// Функция выполнения операции умножения
int multiply(int a, int b) {
    return a * b;
}
 
// Функция выполнения операции деления
int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    else {
        std::cout << "Нельзя делить на ноль!" << std::endl;
        return 0;
    }
}

        
int main() {
            
/* Task1 */
std::cout << "Task1" << std::endl;
const float* const ptrf1 = nullptr; //Объявить константный указатель на константу типа float.
typedef long int* ptrl; //Объявить тип указателя на long int.
double* ptrd1; //Объявить указатель на double.
const short int* ptrs; //Объявить указатель на константу типа short int.
typedef const float* const ptrf2; //Объявить тип константного указателя на константу типа float.
typedef const char* ptrc; //Объявить тип указателя на константу типа char.
double* const ptrd2 = nullptr; //Объявить константный указатель на double.
typedef unsigned int* const ptrui; //Объявить тип константного указателя на unsigned int.
            
/* Task2 */
std::cout << "Task2" << std::endl;
            
int len2;
std::cout << "Введите длину: ";
std::cin >> len2;
double *ptrnumbers = nullptr;
ptrnumbers = mem(ptrnumbers,len2);
fill2(ptrnumbers,len2);
show2(ptrnumbers,len2);
del2(ptrnumbers);
            
/* Task3 */
std::cout << "Task3" << std::endl;
            
int len3 = 12;
int* array3 = new int[len3];
fill3(array3, len3);
change3(array3, len3);
show3(array3, len3);
            
/*Task 4*/
std::cout << "Task 4" << std::endl;
     
int rows, cols;
std::cout << "Введите количество строк: ";
std::cin >> rows;
std::cout << "Введите количество столбцов: ";
std::cin >> cols;
     
// Выделение памяти под двумерный массив
int** array = new int* [rows];
for (int i = 0; i < rows; i++) {
    array[i] = new int[cols];
}
     
// Заполнение массива случайными числами
srand(time(0)); // инициализация генератора случайных чисел
fillArray(array, rows, cols, 10, 50);
     
// Показ массива на экран
displayArray(array, rows, cols);
     
// Освобождение памяти
for (int i = 0; i < rows; i++) {
    delete[] array[i];
}
delete[] array;
std::cout << std::endl;

/*Task 5*/
std::cout << "Task 5" << std::endl;
     
int operand1, operand2;
char operation;
bool tf = true;
     
// Указатель на функцию
int (*operationFunc)(int, int) = nullptr;
     
while (tf) {
    std::cout << "Введите два целых числа и операцию (+, -, *, /) через пробел, либо введите пробел для завершения: ";
    if (!(std::cin >> operand1 >> operand2 >> operation) || operation == ' ') {
        tf= false;
            }
     
// Выбор соответствующей функции в зависимости от операции
    switch (operation) {
        case '+':
            operationFunc = &add;
            break;
        case '-':
            operationFunc = &subtract;
            break;
        case '*':
            operationFunc = &multiply;
            break;
        case '/':
            operationFunc = &divide;
            break;
        default:
            std::cout << "Неверная операция." << std::endl;
            continue; // Продолжаем ввод, если операция некорректна
        }
     
        // Вызов выбранной функции и вывод результата
        std::cout << "Результат: " << operationFunc(operand1, operand2) << std::endl;
        }
    std::cout << "Процесс завершен" << std::endl;


return 0;
}
