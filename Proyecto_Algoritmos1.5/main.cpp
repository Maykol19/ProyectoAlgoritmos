#include <cstdlib>
#include <list>
#include <ostream>
#include <iostream>
#include <string>
#include <bits/stl_tempbuf.h>
#include <cstring>
#include <stdlib.h>
#include "VentanaPrincipal.h"

using namespace std;

int main(int argc, char** argv) {


    Glib::RefPtr<Gtk::Application> app =
                Gtk::Application::create(argc, argv, "Viajes");
        VentanaPrincipal window;
        return app->run(window);

};

