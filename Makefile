bin/programa : src/main.cpp include/Foco.hpp include/
c++ src/main.cpp -o bin/programa -I include

run : bin/ pr bin/ pograma
./bin/programa

bin/memoria : src/memoria.cpp
   c++ src/memoria.cpp -o bin/memoria

   runMemoria : bin/memoria
   ./bin/memoria

   bin/ejemplo : src/ejemplo.cpp
       c++ src/ejemplo.cpp -o bin/ejemplo -lftxui-screen -lftxui-dom -lftxui

       runEjemplo : bin/ejemplo
           ./bin/ejemplo