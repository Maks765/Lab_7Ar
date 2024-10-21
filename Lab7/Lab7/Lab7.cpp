#include <iostream>
using namespace std;

int main()
{
    long X = 0;    // Змінна для аргументу (початкове значення X = 0)
    long Y = 0;    // Змінна для результату обчислення функції y = 15x^2 + 11x - 16

    __asm {
    start_loop:; Початок циклу
    inc X; Збільшення X на 1
    mov EAX, X; EAX = X
    mov EBX, X; EBX = X(для збереження X)

    ; Обчислення чисельника : 15 * x ^ 2
    imul EAX, EAX; EAX = X ^ 2
    mov ECX, 15; ECX = 15
    imul EAX, ECX; EAX = 15 * X ^ 2

    ; Додаємо 11 * X
    mov ECX, 11; ECX = 11
    imul EBX, ECX; EBX = 11 * X
    add EAX, EBX; EAX = 15 * X ^ 2 + 11 * X

    ; Віднімаємо 16
    sub EAX, 16; EAX = 15 * X ^ 2 + 11 * X - 16

    ; Перевірка, чи більше результат за 2000
    mov Y, EAX; Пересилання результату в Y
    cmp EAX, 2000; Порівняння з 2000
    jle start_loop; Якщо результат <= 2000, продовжити цикл

    }

    cout << "Значення X, при якому функція y = 15x^2 + 11x - 16 стає більше 2000: " << X << endl;
    cout << "Значення функції Y = " << Y << endl;

    return 0;
}
