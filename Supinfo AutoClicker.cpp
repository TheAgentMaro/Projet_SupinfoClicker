#include<iostream>
#include<windows.h>
#include"SupinfoAutoclicker.hpp"


using namespace std;


//Function
int keypressed(int key){
    return(GetAsyncKeyState(key) & 0x8000 != 0);
}

void CursorPosi(){
    click.indexv = 0;
    click.condition = TRUE;
    POINT cursor;
    while(click.condition){
        if(keypressed(VK_LBUTTON)||keypressed(VK_MBUTTON)){
            GetCursorPos(&cursor);
            lxinput[click.indexv] = cursor.x;
            lyinput[click.indexv] = cursor.y;
            rxinput[click.indexv] =  ryinput[click.indexv] = -1;          
            cout<<"Clique:"<<++click.k<<endl;
            cout<<"Mouse X = "<<lxinput[click.indexv]<<endl;
            cout<<"Mouse Y = "<<lyinput[click.indexv]<<endl;
            ++click.indexv;
            ++click.instance;
        }
        else if(keypressed(VK_RBUTTON)){
            GetCursorPos(&cursor);
            lxinput[click.indexv] = lyinput[click.indexv] = -1;          
            rxinput[click.indexv] = cursor.x;
            ryinput[click.indexv] = cursor.y;
            cout<<"Clique:"<<++click.k<<endl;
            cout<<"Mouse X = "<<rxinput[click.indexv]<<endl;
            cout<<"Mouse Y = "<<ryinput[click.indexv]<<endl;
            ++click.indexv;
            ++click.instance;
        }
        else if(keypressed(VK_NUMPAD2)){
            cout<<"L'enregistrement du curseur est arrete !"<<endl;
            click.condition = FALSE;
        }
    }
}
void RightClick(int a[], int b[])
{
    //POINT mouseCoords;
    //GetCursorPos(&mouseCoords);
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    input.mi.dwExtraInfo = 0;
    input.mi.mouseData = 0;
    input.mi.dx =a[click.c]*(65535.0f/ GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy =b[click.c]*(65535.0f/ GetSystemMetrics(SM_CYSCREEN));
    input.mi.time = 0;
    ++click.c;
    cout<<input.mi.dx<<input.mi.dy<<endl;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));

}

void LeftClick(int d[], int e[])
{
    //POINT mouseCoords;
    //GetCursorPos(&mouseCoords);
    
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    input.mi.dwExtraInfo = 0;
    input.mi.mouseData = 0;
    input.mi.dx =d[click.c]*(65535.0f/ GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy =e[click.c]*(65535.0f/ GetSystemMetrics(SM_CYSCREEN));
    input.mi.time = 0;
    ++click.c;
    cout<<input.mi.dx<<input.mi.dy<<endl;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));

}

void ClickCursor(int m[],int n[], int o[], int p[], int samay){
    cout<<"|----------- Simulation de clics -------------| ~"<<endl;
    for(int i = 0;i<click.instance;++i){
        Sleep(samay);
        if(m[click.num] != -1){
            RightClick(lxinput,lyinput);
            cout<<"CLIQUE DROITE:"<<click.num<<endl;
            }
        else if(o[click.num] != -1){
            LeftClick(rxinput,ryinput);
            cout<<"CLIQUE GAUCHE:"<<click.num<<endl;
        }
        ++click.num;
    }
    click.num = click.c = 0;   
}

void CursorRec(){
    while(click.condition){
        if(keypressed(VK_MBUTTON)){
            CursorPosi();
        }
        else if(keypressed(VK_F5)){
            click.condition=FALSE;
        }
    }
}