#include <iostream>
using namespace std;

int main()
{
    long X = 0;    // ����� ��� ��������� (��������� �������� X = 0)
    long Y = 0;    // ����� ��� ���������� ���������� ������� y = 15x^2 + 11x - 16

    __asm {
    start_loop:; ������� �����
    inc X; ��������� X �� 1
    mov EAX, X; EAX = X
    mov EBX, X; EBX = X(��� ���������� X)

    ; ���������� ���������� : 15 * x ^ 2
    imul EAX, EAX; EAX = X ^ 2
    mov ECX, 15; ECX = 15
    imul EAX, ECX; EAX = 15 * X ^ 2

    ; ������ 11 * X
    mov ECX, 11; ECX = 11
    imul EBX, ECX; EBX = 11 * X
    add EAX, EBX; EAX = 15 * X ^ 2 + 11 * X

    ; ³������ 16
    sub EAX, 16; EAX = 15 * X ^ 2 + 11 * X - 16

    ; ��������, �� ����� ��������� �� 2000
    mov Y, EAX; ����������� ���������� � Y
    cmp EAX, 2000; ��������� � 2000
    jle start_loop; ���� ��������� <= 2000, ���������� ����

    }

    cout << "�������� X, ��� ����� ������� y = 15x^2 + 11x - 16 ��� ����� 2000: " << X << endl;
    cout << "�������� ������� Y = " << Y << endl;

    return 0;
}
