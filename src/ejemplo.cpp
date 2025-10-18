#include <iostream>
#include <string>
#include<sstream>
#include <thread>
#include <chrono>
using namespace std;
 
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;

string nave=
string("     ___    \n" )+    
string(" ___/   \___ \n")+
string("/   '---'   \ \n")+ 
string("'--_______--' \n")+
string("     / \      \n")+  
string("    /   \      \n")+ 
string("    /\O/\      \n")+ 
string("    / | \      \n")+  
string("    // \\     \n")+ 

int main(int argc, char const *argv[])
{
    auto pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10)
    );

    int x = 0;
    int y = 0;

    stringstream ss(nave);

    while (true)
{
    X++;

    stringstream ss(nave);
    string linea;
    int nolinea = 0;
    while (getline(ss, linea))
    {
    int columna = 0;
    for (auto &&letra : linea)
    {
        //obtener referencia al pixely modificarlo
        auto &pixel = pantalla.PixelAt(x + columna,y + nolinea);
        pixel.character= letra;
        columna++;


}
      nolinea++;
}
// Imprimir la pantalla
    pantalla.ResetPosition();
    pantalla.Print();
    pantalla.Clear();
    this_thread::sleep_for(chrono::miliseconds(100));
    cout<<pantalla.ResetPosition();

    return 0;
}

