#include <iostream>
using namespace std;
 
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;

int main(int argc, char const *argv[])
{
    auto pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10)
    );

    int x = 0;
    int y = 0;

    auto pixel = pantalla.PixelAt(1,1);
    pixel.blink = true;
    pixel.background_color = Color::Blue;
    pixel.foreground_color = Color::red;
    pixel.character = "A";

    pantalla.Print();

    return 0;
}

