#include <iostream>
#include <cmath>

// Функция для извлечения центральных цифр из числа
int extractMiddleDigits(int number, int digits)
{
    // Находим количество цифр в числе
    int numDigits = log10(number) + 1;
    // Находим позицию начала центральных цифр
    int startPosition = (numDigits - digits) / 2;
    // Извлекаем центральные цифры
    int result = number / pow(10, startPosition);
    result %= (int)pow(10, digits);
    return result;
}

// Генератор серединных произведений
int middleSquare(int seed, int digits, int count)
{
    int result = seed;
    for (int i = 0; i < count; i++)
    {
        // Возводим число в квадрат
        int square = result * result;
        // Извлекаем центральные цифры
        result = extractMiddleDigits(square, digits);
        // Выводим сгенерированное число
        std::cout << result << " ";
    }
    std::cout << std::endl;
    return result;
}

int main()
{
    int seed = 2468; // начальное число
    int digits = 4; // количество цифр для извлечения
    int count = 10; // количество сгенерированных чисел
    middleSquare(seed, digits, count);
    return 0;
}
