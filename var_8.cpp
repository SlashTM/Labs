#include <iostream>

using namespace std;

int GetNum(int num)
{
    _asm
    {
        mov eax, num
        mov ebx, 10
        mov edi, 2
        mov ecx, 0
        Loop1:
        cdq
            div ebx
            push eax
            mov eax, edx
            cdq
            div edi
            test edx, edx; флаги pf - чётность zf - ноль sf - знак результата
            jz Even; если остаток равен нулю то прыжок
            Back :
        pop eax
            test eax, eax
            jnz Loop1; если число не ноль то прыгаем в начало, иначе выходим
            jmp Exit
            Even :
        inc ecx; прибавляем 1 к счётчику чётных цифр
            jmp Back; продолжаем идти 
            Exit :
        mov eax, ecx
    }
}

int main()
{
    cout << "Enter number: ";
    int num;
    cin >> num;
    int evencount = GetNum(num);
    cout << "This number has " << evencount << " even digits";
}
