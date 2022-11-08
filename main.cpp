
#include <stdio.h>
#include <ctime>
#include <map>

using namespace std;

int UserID, UserBalance, UserPincode, UserChoice, TransferID;
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
     // заполнеие map
     for(int x = 0, y = 0, i = 0; i<=10; i++)
    {
         fscanf(UsersID, "%d", &x); 
         fscanf(UsersID, "%d", &y);
         Cards[x] = y;
    }
      for(int x = 0, y = 0, i = 0; i<=10; i++)
    {
         fscanf(UsersPincode, "%d", &x); 
         fscanf(UsersPincode, "%d", &y);
         PinCodes[x] = y;
    }
       
      for(int y = 0, x = 0, i = 0; i<=10; i++)
    {
         fscanf(UsersBalance, "%d", &x); 
         fscanf(UsersBalance, "%d", &y);
         Balances[x] = y;
    }
     //
     fclose(UsersID);
     fclose(UsersPincode);
     fclose(UsersBalance);
     UsersID = fopen("users_id.txt", "r");
     fscanf(UsersID, "%d", &UserID);
     fclose(UsersID);
     UserPincode = PinCodes[UserID];
     UserBalance = Balances[UserID];
} 

void BalanceUpdate()
{
     FILE *UsersBalance;
     UsersBalance = fopen("balances.txt", "w");
      
      for (int y = 0, i = 27836; i<=27845; i++)
    {
         y = Balances[i];
         fprintf(UsersBalance, "%d ", i);
         fprintf(UsersBalance, "%d\n", y);
    }
     UserBalance = Balances[UserID];
     fclose(UsersBalance);
}
void LogsWrite(int Function)
{
     string StrTime;
     FILE *UsersTransaction;
     UsersTransaction = fopen("logs.txt", "aw");
     time_t Time = time(nullptr);
     tm* TimeNow = localtime(&Time);
     char CTime[128];
     strftime(CTime, sizeof(CTime), "%d.%m.%Y %X", TimeNow);
     /**/ if (Function == 0)
     fprintf(UsersTransaction, "%s||%d руб снято с карты; ID карты:%d\n", CTime, UserChoice, UserID);
     else if (Function == 1)
     fprintf(UsersTransaction, "%s||%d руб зачиленно на карту; ID карты:%d\n", CTime, UserChoice, UserID);
     else if (Function == 2)
     fprintf(UsersTransaction, "%s||оплачена мобильная связь с карты; ID карты:%d\n", CTime, UserID);
     else if (Function == 3)
     fprintf(UsersTransaction, "%s||%d руб снято с карты и зачисленно на карту:%d; ID карты:%d\n", CTime, UserChoice, TransferID, UserID);
     else return;
     fclose(UsersTransaction);
}
void CardsUpdate(int q)
{
     FILE *UsersID;
     UsersID = fopen("users_id.txt","w");
     Cards[UserID] = q;
     for (int y = 0, i = 27836; i <= 27845; i++)
     {
         y = Cards[i];
         fprintf(UsersID, "%d ", i);
         fprintf(UsersID, "%d\n", y);
     }
     fclose(UsersID);
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
     } else 
     {
         IsValidEnter = true;
         printf("успешно.\n");
     }
     } while(!IsValidEnter);
     IsValidEnter = false;
     if (UserChoice <= UserBalance)
     {
         UserBalance = UserBalance - UserChoice;
         Balances[UserID] = UserBalance;
         BalanceUpdate();
         LogsWrite(0);
     }
}
void Replenishment()
{
     do{ printf("введие сумму, которую хотите внести (введие 0 для отменны)\n");
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
     } else 
     {
         IsValidEnter = true;
         printf("успешно.\n");
     }
     } while(!IsValidEnter);
     IsValidEnter = false;
     UserBalance = UserBalance + UserChoice;
     Balances[UserID] = UserBalance;
     BalanceUpdate();
     LogsWrite(1);
}
void PaymentOfMobileConection()
{
     do{ printf("введие ID провайдера (введие 0 для отменны)\n    1-МТС\n    2-ТЕЛЕ2\n    3-Билайн\n    4-Ростелеком\n");
     if (scanf("%d%c", &UserChoice, &NextSumbol) != 2 ||
     NextSumbol != '\n' || UserChoice<0 || UserChoice>4)
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
     IsValidEnter = false;
     /****/ if (UserChoice == 1) 
     { if (UserBalance >= 850)
        {          
             UserBalance -= 850;
             Balances[UserID] = UserBalance;
             BalanceUpdate();
             printf("успешно.\n");
        } else printf("недостаточно средств! тариф: 850 руб/мес\n");
     } else if (UserChoice == 2)
     {
         if(UserBalance >= 400)
         {
             UserBalance -= 400;
             Balances[UserID] = UserBalance;
             BalanceUpdate();
             printf("успешно.\n");
         } else printf("недостаточно средств! тариф: 400 руб/мес \n");
     } else if (UserChoice == 3)
     {
         if (UserBalance >= 550)
         {
             UserBalance -= 550;
             Balances[UserID] = UserBalance;
             BalanceUpdate();
             printf("успешно.\n");
         } else printf("недостаточно средств! тариф: 550 руб/мес\n");
     } else if (UserChoice == 4)
     {
         if (UserBalance >= 750)
         {
             UserBalance -= 750;
             Balances[UserID] = UserBalance;
             BalanceUpdate();
             printf("успешно.\n");
         } else printf("недостаточно средств! тариф: 750 руб/мес\n");
     }
     LogsWrite(2);
}
void Transfer()
{
      do{ printf("введие ID человека, котому хотите перевести деньги(0-отмена)\n");
     if (scanf("%d%c", &TransferID, &NextSumbol) != 2 ||
     NextSumbol != '\n' || TransferID > 27845 || TransferID < 27836)
     { 
         if (!TransferID == 0)
     {
         printf("неверное значение, попробйте снова!\n");
         scanf("%*[^\n]");
     } else 
     {
         printf("отмена...\n");
         return;
     }
     } else if (Cards[TransferID] == 0)
     {
         printf("карта пользователя заблокированна!\n");
         return;
     } else IsValidEnter = true;
     }while(!IsValidEnter);
     IsValidEnter = false;
     do{ printf("введие сумму, которую хотите перевести\n");
     if (scanf("%d%c", &UserChoice, &NextSumbol) != 2 ||
     NextSumbol != '\n' || UserChoice == 0)
     { 
         printf("неверное значение, попробйте снова!\n");
         scanf("%*[^\n]");
     } else IsValidEnter = true;
     } 
     while(!IsValidEnter);
     if (UserBalance >= UserChoice)
     {
         Balances[UserID] -= UserChoice;
         Balances[TransferID] += UserChoice;
         BalanceUpdate();
         LogsWrite(3);
     }
}
void VievBalance()
{
     printf("Ваш баланс:%d\n", UserBalance); 
}
int main()
{
     Files();
     if (Cards[UserID] != 1)
     {
         return 2;
     }
     int IsExit = false;
     int CountEnter = 0;
     printf("Здравствуйте! Введите ваш пин-код.\n");
     do{
     if (scanf("%d%c", &UserChoice, &NextSumbol) != 2 ||
     NextSumbol != '\n' || UserChoice != UserPincode|| CountEnter == 3)
     { 
     
         printf("неверное значение, попробйте снова!\n");
         printf("у вас осталось %d попыток\n", 2-CountEnter);
         scanf("%*[^\n]");
         CountEnter++;
         if (CountEnter == 3)
         {
             CardsUpdate(0);
             return 2;
         }
     } else IsValidEnter = true;
     } while(!IsValidEnter);
     IsValidEnter = false;
     do 
     {
     do 
     {
         printf("сделайте свойвыбор:\n    0-снятие денег\n    1-поплнеие сщёта\n    2-оплатить мобильную связь\n    3-перевод\n    4-посмотреть баланс\n    -1-выход\n");
         if (scanf("%d%c", &UserChoice, &NextSumbol) != 2 ||
         NextSumbol != '\n' || UserChoice < -1 || UserChoice > 4)
         {
             printf("неверное значение, попробйте снова!\n");
             scanf("%*[^\n]");
         } else IsValidEnter = true;
     } while(!IsValidEnter);
     /***/ if (UserChoice == -1)
     IsExit = true;
     else  if (UserChoice == 0)
     CashOut();
     else if (UserChoice == 1)
     Replenishment();
     else if (UserChoice == 2)
     PaymentOfMobileConection();
     else if (UserChoice == 3)
     Transfer();
     else if (UserChoice == 4)
     VievBalance();
     } while(!IsExit);
     return 0;
}
