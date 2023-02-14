#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define NUMBER_ONE 1
#define NUMBER_TWO 2
#define NUMBER_THREE 3
#define NUMBER_FOUR 4
#define NUMBER_FIVE 5
#define NUMBER_SIX 6
#define NUMBER_SEVEN 7
#define NUMBER_EIGHT 8
#define NUMBER_NINE 9
#define NUMBER_ZERO 0

#define ADD 11
#define SUB 12
#define MUL 13
#define DIV 14
#define EQUAL 15
#define CLEAR 16
#define SQRT 17

int firstDec = true;
int firstPro = true;
int decimal = 0;
int task = 0;
int mind[20] = {0};
double first = 0;
char display[20];
char charInput[3];

int *pFirstDec = &firstDec;
int *pFirstPro = &firstDec;
int *pDecimal = &decimal;
double *pFirst = &first;
char *pDisplay = display;



LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddControls(HWND);
double NumberOut(int[], int);
void ButtonEdit(int *pFirstDec, int *pDecimal, char *pDisplay, char charInput[]);
void OperationEdit(int *pFirstPro, int *pDecimal, double *pFirst, int mind[], int decimal);


HWND hEdit;

int WINAPI WinMain(HINSTANCE hInst , HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {

    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_DESKTOP;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"myWindowClass", L"Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100,100,500,600,
                    NULL,NULL,NULL,NULL);

    MSG msg ={0};

    
    while( GetMessage(&msg, NULL, NULL, NULL) ) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
 
            switch(wp) {
                case NUMBER_ONE: 
                    strcpy(charInput, "1");
                    mind[decimal] = 1;

                    ButtonEdit(&firstDec, &decimal, display,charInput);

                    break;
                case NUMBER_TWO:
                    strcpy(charInput, "2");
                    mind[decimal] = 2;

                    ButtonEdit(&firstDec, &decimal, display,charInput);
                        
                    break;
                case NUMBER_THREE:
                    strcpy(charInput, "3");
                    mind[decimal] = 3;

                    ButtonEdit(&firstDec, &decimal, display,charInput);
                    
                    break;
                case NUMBER_FOUR:
                    strcpy(charInput, "4");
                    mind[decimal] = 4;

                    ButtonEdit(&firstDec, &decimal, display,charInput);
                    
                    break;
                case NUMBER_FIVE:
                    strcpy(charInput, "5");
                    mind[decimal] = 5;

                    ButtonEdit(&firstDec, &decimal, display,charInput);
                    
                    break;
                case NUMBER_SIX:
                    strcpy(charInput, "6");
                    mind[decimal] = 6;

                    ButtonEdit(&firstDec, &decimal, display,charInput);
                    
                    break;
                case NUMBER_SEVEN:
                    strcpy(charInput, "7");
                    mind[decimal] = 7;

                    ButtonEdit(&firstDec, &decimal, display,charInput);
                    
                    break;
                case NUMBER_EIGHT:
                    strcpy(charInput, "8");
                    mind[decimal] = 8;

                    ButtonEdit(&firstDec, &decimal, display,charInput);
                    
                    break;
                case NUMBER_NINE:
                    strcpy(charInput, "9");
                    mind[decimal] = 9;

                    ButtonEdit(&firstDec, &decimal, display,charInput);
                    
                    break;
                case NUMBER_ZERO:
                if (firstDec == false) {
                        strcat(display, "0");
                        mind[decimal] = 0;

                        firstDec = false;
                        decimal++;
                    }
                    

                    SetWindowText(hEdit, display);                    
                    break;

                case ADD:
                    if(task == 0 & firstDec == false){
                        strcat(display, "+");
                        task = 1;
                        OperationEdit(&firstPro, &decimal, &first, mind, decimal);
                    }
                    
                    SetWindowText(hEdit, display);
                    break;

                case SUB:
                    if(task == 0 & firstDec == false){
                        strcat(display, "-");
                        task = 2;
                        OperationEdit(&firstPro, &decimal, &first, mind, decimal);
                    }

                    SetWindowText(hEdit, display);
                    break;

                case MUL:
                    if(task == 0 & firstDec == false){
                        strcat(display, "*");
                        task = 3;
                        OperationEdit(&firstPro, &decimal, &first, mind, decimal);
                    }
                    
                    SetWindowText(hEdit, display);
                    break;

                case DIV:
                    if (task == 0 & firstDec == false){
                        strcat(display, "/");
                        task = 4;
                        OperationEdit(&firstPro, &decimal, &first, mind, decimal);
                    }
                    
                    SetWindowText(hEdit, display);
                    break;

                case EQUAL:
                    if(task != 0){
                       switch(task) {
                        case 1:
                        first += NumberOut(mind ,decimal);
                        break;

                        case 2:
                        first -= NumberOut(mind,decimal);
                        break;

                        case 3:
                        first *= NumberOut(mind ,decimal);
                        break;

                        case 4:
                        first /= NumberOut(mind,decimal);
                        break;
                       }
                        sprintf(display,"%lf", first);
                        
                        decimal = 0;
                        task= 0;
                        
                    }

                    SetWindowText(hEdit, display);
                    
                    break;
                case CLEAR:
                    firstDec = true;
                    decimal = 0;
                    firstPro = true;
                    task = 0;
                    first = 0;
                    char clear[20]= "";
                    strcpy(display, clear);
                    int mind[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

                    SetWindowText(hEdit, display);
                break;
                case SQRT:
                    first = sqrt(NumberOut(mind ,decimal));
                    sprintf(display,"%lf", first);
                    decimal = 0;
                    SetWindowText(hEdit, display);

                break;
            }

            break;

        case WM_CREATE:
            
            AddControls(hWnd);
            break;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }
}



void AddControls(HWND hWnd) {
    

    hEdit = CreateWindowW(L"edit", L"0", WS_VISIBLE | WS_CHILD | WS_BORDER , 50, 50, 400, 50, hWnd, 
    NULL, NULL, NULL);
    
    CreateWindowW(L"Button", L"Sqrt", WS_VISIBLE | WS_CHILD, 50, 150, 60, 60, hWnd, (HMENU)SQRT, NULL, NULL);
    
    CreateWindowW(L"Button", L"7", WS_VISIBLE | WS_CHILD, 135, 150, 60, 60, hWnd, (HMENU)NUMBER_SEVEN, NULL, NULL);
    CreateWindowW(L"Button", L"4", WS_VISIBLE | WS_CHILD, 135, 235, 60, 60, hWnd, (HMENU)NUMBER_FOUR, NULL, NULL);
    CreateWindowW(L"Button", L"1", WS_VISIBLE | WS_CHILD, 135, 320, 60, 60, hWnd, (HMENU)NUMBER_ONE, NULL, NULL);
    CreateWindowW(L"Button", L"C", WS_VISIBLE | WS_CHILD, 135, 405, 60, 60, hWnd, (HMENU)CLEAR, NULL, NULL);

    CreateWindowW(L"Button", L"8", WS_VISIBLE | WS_CHILD, 220, 150, 60, 60, hWnd, (HMENU)NUMBER_EIGHT, NULL, NULL);
    CreateWindowW(L"Button", L"5", WS_VISIBLE | WS_CHILD, 220, 235, 60, 60, hWnd, (HMENU)NUMBER_FIVE, NULL, NULL);
    CreateWindowW(L"Button", L"2", WS_VISIBLE | WS_CHILD, 220, 320, 60, 60, hWnd, (HMENU)NUMBER_TWO, NULL, NULL);
    CreateWindowW(L"Button", L"0", WS_VISIBLE | WS_CHILD, 220, 405, 60, 60, hWnd, (HMENU)NUMBER_ZERO, NULL, NULL);

    CreateWindowW(L"Button", L"9", WS_VISIBLE | WS_CHILD, 305, 150, 60, 60, hWnd, (HMENU)NUMBER_NINE, NULL, NULL);
    CreateWindowW(L"Button", L"6", WS_VISIBLE | WS_CHILD, 305, 235, 60, 60, hWnd, (HMENU)NUMBER_SIX, NULL, NULL);
    CreateWindowW(L"Button", L"3", WS_VISIBLE | WS_CHILD, 305, 320, 60, 60, hWnd, (HMENU)NUMBER_THREE, NULL, NULL);
    CreateWindowW(L"Button", L"=", WS_VISIBLE | WS_CHILD, 305, 405, 60, 60, hWnd, (HMENU)EQUAL, NULL, NULL);

    CreateWindowW(L"Button", L"+", WS_VISIBLE | WS_CHILD, 390, 150, 60, 60, hWnd, (HMENU)ADD, NULL, NULL);
    CreateWindowW(L"Button", L"-", WS_VISIBLE | WS_CHILD, 390, 235, 60, 60, hWnd, (HMENU)SUB, NULL, NULL);
    CreateWindowW(L"Button", L"*", WS_VISIBLE | WS_CHILD, 390, 320, 60, 60, hWnd, (HMENU)MUL, NULL, NULL);
    CreateWindowW(L"Button", L"/", WS_VISIBLE | WS_CHILD, 390, 405, 60, 60, hWnd, (HMENU)DIV, NULL, NULL);

}

double NumberOut(int mind[], int decimal) {
    double result = 0;
    int a = 0;
    int power = decimal-1;
    
    while(a!=decimal){
        result+= mind[a]*pow(10,power);
        power--;
        a++;
    }
    
    return result;
}

void ButtonEdit(int *pFirstDec, int *pDecimal, char *pDisplay, char charInput[]) {
    if (firstDec == true) {
        strcpy(display, charInput);
    }
    else {
        strcat(display, charInput);
    }

    *pFirstDec = false;
    *pDecimal = decimal + 1;

    SetWindowText(hEdit, display);
}

void OperationEdit(int *pFirstPro, int *pDecimal, double *pFirst, int mind[], int decimal) {
if(firstPro == true){
    *pFirst = NumberOut(mind,decimal);
    *pFirstPro=false;
}
*pDecimal = 0;
}