#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
using namespace ftxui;

int main() {
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

    // Figuras ASCII
    const std::vector<std::u32string> barco = {
        U"      |    |    |",
        U"     )_)  )_)  )_)",
        U"    )___))___))___)",
        U"   )____)____)_____) ",
        U" _____|____|____|_____",
        U" \\                   /",
        U"  \\_________________/"
    };

    const std::vector<std::u32string> ola = {
        U"~~~~      ~~~~      ~~~~"
    };

    const std::vector<std::u32string> gaviota = {
        U"  __",
        U"<(o )___",
        U" ( ._> /",
        U"  `---'"
    };

    GestorDibujos gestor;
    gestor.Agregar(Dibujo(10, 15, barco, ftxui::Color::BlueLight));
    gestor.Agregar(Dibujo(5, 20, ola, ftxui::Color::Blue));
    gestor.Agregar(Dibujo(40, 20, ola, ftxui::Color::Blue));
    gestor.Agregar(Dibujo(60, 20, ola, ftxui::Color::Blue));
    gestor.Agregar(Dibujo(20, 3, gaviota, ftxui::Color::White));

    int frames = 200;
    for (int frame = 0; frame < frames; ++frame) {
        screen.Clear();

        // Animación: mover el barco y las olas
        gestor.dibujos[0].x = 10 + (frame % 30);
        gestor.dibujos[1].x = 5 + (frame % 40);
        gestor.dibujos[2].x = 40 + ((frame + 20) % 40);
        gestor.dibujos[3].x = 60 + ((frame + 10) % 40);
        gestor.dibujos[4].x = 20 + ((frame * 2) % 60); // gaviota

        gestor.DibujarTodos(screen);

        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }

    return 0;
}
