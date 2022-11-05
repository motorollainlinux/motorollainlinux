/*Реализовать программу, моделирующую работу банкомата.
Предусмотреть операции по снятию, внесению наличных и оплате мобильной
связи (это на оценку 3), каждая последующая, придуманная вами самими
операция увеличивает оценку на балл (при условии правильности ее
выполнения). Id пользователей хранится в файле users_id.txt по форме id
пользователя – статус карты (1 – если карта активна, 0 – если карта
заблокирована), пин-коды от карт хранятся в файле pin-codes.txt по форме id
пользователя – пин-код (4 цифры). Балансы карт хранятся в файле balances.txt
по форме id пользователя – баланс карты. Логи всех операций сохранять в
файле logs.txt по форме: дата и время (библиотеку и функции работы с датой
и временем найдете сами) -тип операции (снятие, оплата, внесение) - сумма
операции. Предусмотреть возможность 2 раза ввести неправильный пин-код
от карты владельцем. При вводе 3 неправильного пин-кода карта блокируется.*/

//#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <locale.h>
//#include <map>

using namespace std;

int UserID, UserBalance, UserPincode, UserChoice;
char NextSumbol; 
bool IsValidEnter = false;
void Files()
{
     FILE *UsersID, *UsersPincode, *UsersBalance, *UsersTransaction;
     UsersID = fopen("users_id.txt", "r");
     UsersPincode = fopen("pin-codes.txt", "r");
     UsersBalance = fopen("balances.txt", "wr");
     UsersTransaction = fopen("logs.txt", "w");
}
void CashOut()
{
     do{ printf("введие сумму, которую хотите вывети\n");
     if (scanf("%d%c", &UserChoice, &NextSumbol) != 2 ||
     NextSumbol != '\n')
     {
         printf("неверное значение, попробйте снова!\n");
         scanf("%*[^\n]");
     } else IsValidEnter = true;
     } while(!IsValidEnter);
     
}
void Replenishment()
{
     printf("inWorck\n"); 
}
void PaymentOfMobileConection()
{
     printf("inWorck\n");  
}
void Transfer()
{
     printf("inWorck\n");  
}
void VievBalance()
{
     printf("inWorck\n"); 
}
int main()
{

     setlocale(LC_ALL, "Russian");
     CashOut();  
}
