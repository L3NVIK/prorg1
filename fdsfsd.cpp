/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib; // our graphics facilities are in Graph_lib

	Point tl {100,100}; // to become top left corner of window

	Simple_window win {tl,600,400,"CanvAss"}; // make a simple window
	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	
	Function sine {sin,0, 100, Point{20,150}, 1000, 50, 50};
	
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::green);
	poly.set_style(Line_style(Line_style::dash,3));
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	poly_rect.set_style(Line_style(Line_style::dash,20));
	poly_rect.set_fill_color(Color::blue);
	
	Rectangle r {Point{200,200},100,50};
	r.set_fill_color(Color::yellow);
	
	Text t {Point{150,150},"Akdmsafedfmkff!"};
	t.set_font(Font::times_bold);
	t.set_font_size(50);
	
	Image ii {Point{100,50}, "gnasda.jpg"};
	
	
	win.attach(ii);
	win.attach(r);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(poly_rect);
	win.attach(t);
	
	win.wait_for_button(); // give control to the display engine
}
