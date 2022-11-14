// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;


class Input {
public:
    int hor;
    int vert;
    int key1;
    int len;
    int winX;
    int win0;
    int Input1() {
        key1 = 0;
        len = 0;
        vert = 0;
        while (key1 != 13) {
            system("cls");
            if (key1 == 8 and len != 0) {
                vert = vert / 10;
                len -= 1;
            }
            if (key1 >= 48 and key1 <= 57 and len < 2) {
                vert = vert * 10 + (key1 - 48);
                len += 1;
                printf("Столбцов = %d", vert);
            }
            else {
                printf("Столбцов = %d", vert);
            }
            key1 = _getch();
            system("cls");
        }
        return vert;
    }
    int Input2() {
        system("cls");
        key1 = 0;
        hor = 0;
        len = 0;
        while (key1 != 13) {
            if (key1 == 8 and len != 0) {
                hor = hor / 10;
                len -= 1;
            }
            if (key1 >= 48 and key1 <= 57 and len < 2) {
                hor = hor * 10 + (key1 - 48);
                len += 1;
                printf("Строк = %d", hor);
            }
            else {
                printf("Строк = %d", hor);
            }
            key1 = _getch();
            system("cls");
        }
        return hor;
    }
    int Input3() {
        system("cls");
        key1 = 0;
        len = 0;
        winX = 0;
        while (key1 != 13) {
            if (key1 == 8 and len != 0) {
                winX = winX / 10;
                len -= 1;
            }
            if (key1 >= 48 and key1 <= 57 and len < 2) {
                winX = winX * 10 + (key1 - 48);
                len += 1;
                printf("Крестикам для победы = %d", winX);
            }
            else {
                printf("Крестикам для победы = %d", winX);
            }
            key1 = _getch();
            system("cls");
        }
        return winX;
    }
    int Input4() {
        system("cls");
        key1 = 0;
        len = 0;
        win0 = 0;
        while (key1 != 13) {
            if (key1 == 8 and len != 0) {
                win0 = win0 / 10;
                len -= 1;
            }
            if (key1 >= 48 and key1 <= 57 and len < 2) {
                win0 = win0 * 10 + (key1 - 48);
                len += 1;
                printf("Ноликам для победы = %d", win0);
            }
            else {
                printf("Ноликам для победы = %d", win0);
            }
            key1 = _getch();
            system("cls");
        }
        return win0;
    }
};


class Menu {
public:
    Input ip = Input();
    int key = 5;
    int row = 2;
    int col = 2;
    int num = 1;
    int c = 0;
    int x = 0;
    int y = 0;
    int a[15][15] = {{0}};
    int num1 = 1;
    int code = 0;
    int winX = 4;
    int win0 = 4;
    bool fl = false;
    bool fl2 = false;
    bool Check() {
        if (row > 14 or col > 14 or row < 2 or col < 2) {
            return false;
        }
        else {
            return true;
        }
    }
    void Approp1() {
        row = ip.Input2();
       
        if (Check() == true) {
            if (c == 0) {
                c = 1;
                Approp2();  
            }
            else {
                MenuOutput();
            } 
        }
        else {
            Approp1();
        }
    }
    void Approp2() {
        col = ip.Input1();
        if (Check() == true) {
            MenuOutput();
        }
        else {
            Approp2();
        }
    }
    void MenuOutput() {  
       
        do {
            system("cls");
           // printf("%d%d", x,y);
            if (key == 49) {
                num = 1;
            }
            if (key == 50) {
                num = 2;
            }
            if (key == 51) {
                num = 3;
            }
            if (key == 52) {
                num = 4;
            }
            if (key == 13 and fl == true and code!=5 and code!=6 and code!=7) {
                Count();
            }
            if (key == 53) {
                num = 5;
            }
            if (key == 54) {
                num = 6;
            }
            if (code == 1) {
                printf("Это поле уже занято\n");
                code = 0;
            }
            if (code == 2) {
                printf("Нельзя менять параметры во время игры\n");
                code = 0;
            }
            if (code == 6) {
                fl2 = true;
                printf("ПОБЕДИЛИ КРЕСТИКИ\n");
            }
            if (code == 5) {
                fl2 = true;
                printf("ПОБЕДИЛИ НОЛИКИ\n");
            }
            if (code == 7) {
                fl2 = true;
                printf("НИЧЬЯ\n");
            }
            //if (code)
            if ((key == 0 or key == 224) and code != 5 and code != 6 and code != 7)
            {
                switch (_getch())
                {
                case 72:
                    y -= 1;
                    if (y < 0) {
                        y = row - 1;
                    }
                    break;

                case 80:
                    y += 1;
                    if (y > row-1) {
                        y = 0;
                    }
                    break;
                case 75:
                    x -= 1;
                    if (x < 0) {
                        x = col - 1;
                    }
                    break;
                case 77:
                    x += 1;
                    if (x > col-1) {
                        x = 0;
                    }
                    break;
                }
                if (fl == false) {
                    x = 0;
                    y = 0;
                    fl = true;
             }
            }
            printf("Для начала игры нажмите любую стрелочку. Для потдверждения хода нажмите Enter  \n");
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (((i == y and j == x) or a[i][j] !=0) and fl == true) {
                        if (a[i][j] != 0) {
                            if (a[i][j] % 2 != 0) {
                                if (i == y and j == x) {
                                    if (num1 % 2 != 0) {
                                        printf("\033[31m%s\033[0m", "|_x_| ");
                                    }
                                    else {
                                        printf("\033[31m%s\033[0m", "|_0_| ");
                                    }
                                }
                                else {
                                    printf("|_x_| ");
                                } 
                            }
                            else {
                                if (i == y and j == x) {
                                    if (num1 % 2 != 0) {
                                        printf("\033[31m%s\033[0m","|_x_| ");
                                    }
                                    else {
                                        printf("\033[31m%s\033[0m", "|_0_| ");
                                    }
                                }
                                else {
                                    printf("|_0_| ");
                                }
                            }
                        }
                        else {
                            if (num1 % 2 != 0) {
                                printf("\033[32m%s\033[0m","|_x_| ");
                            }
                            else {
                                printf("\033[32m%s\033[0m", "|_0_| ");
                            }
                        }
                    }           
                    else {
                        printf("|___| ");
                    }
                }
                printf("\n");
            }
            printf("\n");
            printf("Для перемещения по меню используйте цыфры, для подтверждения выбора нажмите пробел\n");
            printf("\nДля перевыбора строк нажмите 1) Сейчас: %d ", row);
            if (num == 1) {
                printf("<-");
            }
            printf("\nДля перевыбора столбцов нажмите 2) Сейчас: %d ", col);
            if (num == 2) {
                printf("<-");
            }
            printf("\nДля перевыбора кол-ва победных крестиков нажмите 3) Сейчас: %d  ", winX);
            if (num == 3) {
                printf("<-");
            }
            printf("\nДля перевыбора кол-ва победных ноликов нажмите 4) Сейчас: %d  ", win0);
            if (num == 4) {
                printf("<-");
            }
            printf("\nЧтобы начать заново нажмите 5) ");
            if (num == 5) {
                printf("<-");
            }
            printf("\nДля выхода нажмите 6) ");
            if (num == 6) {
                printf("<-");
            }
            key = _getch();
        } while (key != 32);
        if (num == 1) {
            if (fl == false) {
                Approp1();
            }
            else if(fl2 == true) {
                zero();
                Approp1();
            }
            else {
                code = 2;
                MenuOutput();
            }
        }
        if (num == 2) {
            if (fl == false) {
                Approp2();
            }
            else if (fl2 == true) {
                zero();
                Approp2();
            }
            else {
                code = 2;
                MenuOutput();
            }
            
        }
        if (num == 3) {
            if (fl == false) {
                winX = ip.Input3();
                MenuOutput();
            }
            else if (fl2 == true) {
                zero();
                winX = ip.Input3();
                MenuOutput();
            }
            else {
                code = 2;
                MenuOutput();
            }
           
        }
        if (num == 4) {
            if (fl == false) {
                win0 = ip.Input4();
                MenuOutput();
            }
            else if (fl2 == true) {
                zero();
                win0 = ip.Input4();
                MenuOutput();
            }
            else {
                code = 2;
                MenuOutput();
            }
            
        }
        if (num == 5) {
            fl = false;
            fl2 = false;
            code = 0;
            for (int z = 0; z < 15; z++) {
                for (int k = 0; k < 15; k++) {
                    a[z][k] = 0;
                }
            }
            num1 = 1;
            MenuOutput();
        }
        if (num == 6) {
            exit(0);
        }
    }  
    void Count() {

        if (a[y][x] != 0) {
            code = 1;
           
        }
        else {
        a[y][x] = num1;
        checkforwin();
        checkfordraw();
       
        num1 += 1;
       // code = 0;
        }
        if (code != 5 and code != 6 and code != 7) {
            int k = 0;
            for (int z = 0; z < row; z++) {
                for (int m = 0; m < col; m++) {
                    if (a[z][m] == 0 and k == 0) {
                        y = z;
                        x = m;
                        k += 1;
                    }
                }
            }
       }
        else {
            x = -1;
            y = -1;
        }
    }
    void checkforwin() {
        int curX = x;
        int curY = y;
        int maxst = 1;
        int count = 1;
        for (int i = 1; i < row; i++) {
            if ((a[i][curX] % 2 == num1 % 2 && a[i - 1][curX] % 2 == num1 % 2) && a[i][curX] != 0 && a[i-1][curX] != 0) {
                count++;
                maxst = max(maxst, count);
               
            }
            else {
                maxst = max(maxst, count);
                count = 1;
            }

        }
       //printf("%d\n", maxst);
        for (int j = 1; j < col; j++) {
            if (a[curY][j] % 2 == num1 % 2 && a[curY][j-1] % 2 == num1 % 2 && a[curY][j] != 0 && a[curY][j-1] != 0) {
                count++;
                maxst = max(maxst, count);
            }
            else {
                maxst = max(maxst, count);
                count = 1;
            }

        }
        //printf("%d\n", maxst);
        int i = y;
        int j = x;
        count = 0;
        while (i!=0 and j!=0) {
            j--;
            i--;
           // printf("%d",j);
      
        }
        for (i, j; i < row && j < col; i++, j++) {
            if (a[i][j] % 2 == num1 % 2 && a[i][j] != 0) {
                count++;
                maxst = max(maxst, count);
            }
            else {
                maxst = max(maxst, count);
                count = 0;
            }
        }
       //printf("%d\n", maxst);
        i = y;
        j = x;
        count = 0;
        while (i != 0 and j < col - 1) {
            i--;
            j++;
        }
        //printf("j=%d\n ", j);
        for (i, j; i < row && j >= 0; i++, j--) {
            if (a[i][j] % 2 == num1 % 2 && a[i][j] != 0) {
                count++;
                maxst = max(maxst, count);
               //printf("aj=%d \n", j);
            }
            else {
                maxst = max(maxst, count);
                count = 0;
               //printf("%d aj=\n", a[30][30]);
            }
        }
      // printf("%d\n", maxst);
        if ((maxst >= win0 and num1 % 2 == 0) || (maxst >= winX and num1 % 2 != 0)) {
           
            if (num1 % 2 != 0) {
                code = 6;
            }
            else if (num1 % 2 == 0) {
                code = 5;
            }

        }
    }

    void checkfordraw() {
        int dr = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (a[i][j] == 0) {
                    dr = 0;
                    break;
                }
            }
        }
        if (dr) {
            code = 7;
        }
    }
    void zero() {
        fl = false;
        fl2 = false;
        code = 0;
        for (int z = 0; z < 15; z++) {
            for (int k = 0; k < 15; k++) {
                a[z][k] = 0;
            }
        }
        num1 = 1;
    }
};



int main(){
    setlocale(LC_ALL, "Russian");
    Menu mn = Menu();
    mn.Approp1();
    return 0;
}

