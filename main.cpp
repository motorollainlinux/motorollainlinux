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

#include <stdio.h>
#include <ctime>
//#include <locale.h>
#include <map>

using namespace std;

int UserID, UserBalance, UserPincode, UserChoice, TransferID, Function;
char NextSumbol; 
bool IsValidEnter = false;
map <int, int> Cards;
map <int, int> PinCodes;
map <int, int> Balances;
// технические функции
void Files()
{
    // открытие файлов
     FILE *UsersID, *UsersPincode, *UsersBalance;
     UsersID = fopen("users_id.txt", "r");
     UsersPincode = fopen("pin-codes.txt", "r");
     UsersBalance = fopen("balances.txt", "r");
     // UsersTransaction = fopen("logs.txt", "w");
     fscanf(UsersID, "%d", &UserID);
     fscanf(UsersID, "%*[^/n]");
     
     // заполнеие массивов
     for(int x = 0, y = 0, i = 0; i<=10; i++)
    {
         fscanf(UsersID, "%d",&x); 
         fscanf(UsersID, "%d", &y);
         Cards[x] = y;
    }
      for(int x = 0, y = 0, i = 0; i<=10; i++)
    {
         fscanf(UsersPincode, "%d",&x); 
         fscanf(UsersPincode, "%d", &y);
         PinCodes[x] = y;
    }
       
      for(int y = 0, x = 0, i = 0; i<=10; i++)
    {
         fscanf(UsersBalance, "%d", &x); 
         fscanf(UsersBalance, "%d", &y);
         Balances[x] = y;
    }
     UserPincode = PinCodes[UserID];
} 

void BalanceUpdate()
{
     FILE *UsersBalance;
     UsersBalance = fopen("balances.txt", "w");
      
      for (int y = 0, x = 0, i = 0; i<=10; i++)
    {
         x = Balances[i];
         y = Balances[i];
         fprintf(UsersBalance, "%d ", x);
         fprintf(UsersBalance, "%d\n", y);
    }
     UserBalance = Balances[UserID];
}
void LogsWrite()
{
     string StrTime;
     FILE *UsersTransaction;
     UsersTransaction = fopen("logs.txt", "w");
     time_t Time = time(nullptr);
     char CTime[128];
     strftime(CTime, sizeof(CTime), "%d.%m.%Y %X", localtime(&tm));
     if (Function == 0)
     fprintf(UsersTransaction, "%s||снято %dрублей с карты;ID карты:%d", CTime,UserChoice,UserID);
}
//функции банкомата
void CashOut()
{
      
     do{ printf("введие сумму, которую хотите вывети (введие 0 для отменны)\n");
     if (scanf("%d%c", &UserChoice, &NextSumbol) != 2 ||
     NextSumbol != '\n')
     { 
         if (!UserChoice == 0)
     {
         printf("неверное значение, попробйте снова!\n");
         scanf("%*[^\n]");
     } else 
     {
         printf("отмена...\n");
         return;
     }
     } else IsValidEnter = true;
     } while(!IsValidEnter);
     if (UserChoice >= UserBalance)
     {
         UserBalance -= UserChoice;
         Balances[UserID] = UserBalance;
         BalanceUpdate();
     }
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
     Files();
     /**/ printf("%d\n",Balances[UserID]); /**/
     int CountEnter = 0;
     do{ printf("Здравствуйте! Введите ваш пин-код.\n");
     if (scanf("%d%c", &UserChoice, &NextSumbol) != 2 ||
     NextSumbol != '\n' || UserChoice != UserPincode)
     { if (CountEnter != 3)
     {
         printf("неверное значение, попробйте снова!\n");
         scanf("%*[^\n]");
         CountEnter++;
     } else return 0;
     } else IsValidEnter = true;
     } while(!IsValidEnter);
     IsValidEnter = false;
     do 
     {
         printf("сделайте свойвыбор:\n    0-снятие денег\n    1-поплнеие сщёта\n    2-перевод\n    3-оплатить мобильную связь\n    4-посмотреть баланс\n");
         if (scanf("%d%c", &UserChoice, &NextSumbol) != 2 ||
         NextSumbol != '\n' || UserChoice < 0 || UserChoice > 4)
         {
             printf("неверное значение, попробйте снова!\n");
             scanf("%*[^\n]");
         } else IsValidEnter = true;
     } while(!IsValidEnter);
          if (UserChoice == 0)
     CashOut();
     else if (UserChoice == 1)
     Replenishment();
     else if (UserChoice == 2)
     PaymentOfMobileConection();
     else if (UserChoice == 3)
     Transfer();
     else if (UserChoice == 4)
     VievBalance();
}