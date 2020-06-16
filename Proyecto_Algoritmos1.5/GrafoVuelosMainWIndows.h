#ifndef GRAFOVUELOSMAINWINDOWS_H
#define GRAFOVUELOSMAINWINDOWS_H

#include "iostream"
#include "Drawing.h" 
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <bits/stl_tempbuf.h>
#include <gtkmm.h>

using namespace std;

class GrafoVuelosMainWindows : public Gtk::Window {
public:
    GrafoVuelosMainWindows() {
        this->set_title("Vista de vuelos");
        this->d.show_all();
        this->add(this->d);
        this->start();
    }//constructor
    
    void start() {
        pthread_create(&thread, 0, run, this);
    }//start

    void wait() {
        (void) pthread_join(thread, NULL);
    }//wait
    
    private:

    void updateWindows() {
        
        while (true){
            this->d.updateDrawingArea();
            usleep(100000);
        }
        
    }//updateWindows 

    static void* run(void* arg) {
        
        GrafoVuelosMainWindows* gV = reinterpret_cast<GrafoVuelosMainWindows*> (arg);
        gV->updateWindows();
        return 0;
    
    }//run
    
    //Atributos
    Drawing d;
    pthread_t thread;//Hilo
    
};


#endif /* GRAFOVUELOSMAINWINDOWS_H */

