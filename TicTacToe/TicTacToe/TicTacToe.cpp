// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>


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
        while (key1 != 32) {
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
        key1 = 0;
        hor = 0;
        len = 0;
        while (key1 != 32) {
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
        key1 = 0;
        len = 0;
        winX = 0;
        while (key1 != 32) {
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
        key1 = 0;
        len = 0;
        win0 = 0;
        while (key1 != 32) {
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
    int a[15][15];
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
            if (key == 13) {
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
            }
            if (code == 2) {
                printf("Нельзя менять параметры во время игры\n");
            }
            if (key == 0 or key == 224)
            {
                switch (_getch())
                {
                case 72:
                    y -= 1;
                    if (y < 0) {
                        y = col - 1;
                    }
                    break;

                case 80:
                    y += 1;
                    if (y > col-1) {
                        y = 0;
                    }
                    break;
                case 75:
                    x -= 1;
                    if (x < 0) {
                        x = row - 1;
                    }
                    break;
                case 77:
                    x += 1;
                    if (x > row-1) {
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
            printf("Для начала игры нажмите любую стрелочку\n");
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    fl2 = false;
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
            printf("\nДля перевыбора строк нажмите 1) Сейчас: %d ", row);
            if (num == 1) {
                printf("<-\n");
            }
            printf("\nДля перевыбора столбцов нажмите 2) Сейчас: %d ", col);
            if (num == 2) {
                printf("<-\n");
            }
            printf("\nДля перевыбора кол-ва победных крестиков нажмите 3) Сейчас: %d  ", winX);
            if (num == 3) {
                printf("<-\n");
            }
            printf("\nДля перевыбора кол-ва победных ноликов нажмите 4) Сейчас: %d  ", win0);
            if (num == 4) {
                printf("<-\n");
            }
            printf("\nЧтобы начать заново нажмите 5) ");
            if (num == 5) {
                printf("<-\n");
            }
            printf("\nДля выхода нажмите 6) ");
            if (num == 6) {
                printf("<-\n");
            }
            key = _getch();
        } while (key != 32);
        if (num == 1) {
            if (fl == false) {
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
            else {
                code = 2;
                MenuOutput();
            }
            
        }
        if (num == 5) {
            fl = false;
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
            y = 0;
            x = 0;
        }
        else {
        a[y][x] = num1;
        y = 0;
        x = 0;
        num1 += 1;
        code = 0;
        }
        
    }
};



int main(){
    setlocale(LC_ALL, "Russian");
    Menu mn = Menu();
    mn.Approp1();
    return 0;
}

