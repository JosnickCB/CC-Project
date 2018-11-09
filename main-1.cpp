#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Player.h"

using namespace std;

const int ancho=640, altura=480, velocidad=3;
const float FPS = 60;
float x1 = 0, y1 = 0, x2 = 0, y2 = 0, r = 25; //velocidad del objeto plus radio	
Player P1(r,altura-6*r,r);
Player P2(ancho-r,altura-6*r,r);
bool done = false;
////////////////ALLEGRO UTILITIES//////////
ALLEGRO_EVENT_QUEUE* event_queue;
ALLEGRO_TIMER* timer;
ALLEGRO_DISPLAY* display;
ALLEGRO_FONT* font;

void iniciar(bool lo_que_se_inicia, const char *descripcion){
	if(lo_que_se_inicia) return;

	printf("No se pudo iniciar %s\n", descripcion);
	exit(1);
}

void inicializar_allegro_stuff(void){
	iniciar(al_init(),"allegro");

	iniciar(al_install_keyboard(),"teclado");
	
	timer = al_create_timer(1.0/FPS);
	iniciar(timer, "timer");

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(ancho, altura);
	iniciar(display, "display");
	
	event_queue = al_create_event_queue();
	iniciar(event_queue,"cola de eventos");

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	font = al_create_builtin_font();
	iniciar(font,"font");
	
	iniciar(al_init_primitives_addon(),"primitives");

	al_start_timer(timer);
}
void destruir_allegro_stuff(void){
	if (timer){
		al_destroy_timer(timer);
		cout << "timer destruido"<<endl;
	}
	if (display){
		al_destroy_display(display);
		cout << "display destruido"<<endl;
	}
	if (event_queue){
		al_destroy_event_queue(event_queue);
		cout << "evento_queue destruido"<<endl;
	}
	if (font){
		al_destroy_font(font);
		cout << "font destruido"<<endl;
	}
}
/*void print_rayo(int x, int y){
	for(int i=0;i<ancho-x;i++){
	al_draw_text(font, al_map_rgb(255,255,255),x+=2,y,0,"a");
	al_flip_display();
	}
}*/

void game_loop(void){
	
	while(!done){
		bool redraw = false;

		while(!al_is_event_queue_empty(event_queue)){
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		
		switch(event.type){
			case ALLEGRO_EVENT_KEY_DOWN:
				switch(event.keyboard.keycode){
					case ALLEGRO_KEY_LEFT:
						x1-=velocidad;
						break;
					case ALLEGRO_KEY_RIGHT:
						x1+=velocidad;
						break;
					case ALLEGRO_KEY_A:
						x2-=velocidad;
						break;
					case ALLEGRO_KEY_D:
						x2+=velocidad;
						break;
					case ALLEGRO_KEY_ESCAPE:
						done = true;
						break;
				}
			break;
			
			case ALLEGRO_EVENT_KEY_UP:
				switch(event.keyboard.keycode){
					case ALLEGRO_KEY_LEFT:
						x1+=velocidad;
						break;
					case ALLEGRO_KEY_RIGHT:
						x1-=velocidad;
						break;
					case ALLEGRO_KEY_A:
						x2+=velocidad;
						break;
					case ALLEGRO_KEY_D:
						x2-=velocidad;
						break;
				}
				break;
			case ALLEGRO_EVENT_TIMER:	
				redraw = true;
				break;
		}
		}
		if(redraw){
			P1.base.setX(P1.base.getX()+x1);
			P2.base.setX(P2.base.getX()+x2);
			al_clear_to_color(al_map_rgb(0, 0 ,0));
			P1.print();
			P2.print();
			al_flip_display();
		}		
	}
}
int main(){
	inicializar_allegro_stuff();
	game_loop();
	destruir_allegro_stuff();
}
/*else if(event.type == ALLEGRO_EVENT_KEY_CHAR){
			if(event.keyboard.repeat == true){
				al_clear_to_color(al_map_rgb(0,0,0));
				P1.base.setX(x1-=5);
				redraw = true;
			}
		}*/

		//else if(event.type == ALLEGRO_EVENT_KEY_DOWN || event.type == ALLEGRO_EVENT_KEY_CHAR){
		//	if(event.keyboard.keycode == ALLEGRO_KEY_LEFT){
			//	al_stop_timer(timer);
		//		if(event.keyboard.repeat == true){
		//			al_clear_to_color(al_map_rgb(0,0,0));
		//			P1.base.setX(x1-=3);
		//		}
		///		else{
			//	al_clear_to_color(al_map_rgb(0,0,0));
				//print_player(x-=5,y,r);
			//	P1.base.setX(x1-=5);
			//	}
			//	redraw = true;
		//	}
		//	else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT){
		//		if(event.keyboard.repeat == true){
		///			al_clear_to_color(al_map_rgb(0,0,0));
			//		P1.base.setX(x1+=3);
			//	}
			//	else{
			//	al_clear_to_color(al_map_rgb(0,0,0));
				//print_player(x-=5,y,r);
			//	P1.base.setX(x1+=5);
			//	}
			//	//print_player(x+=5,y,r);				
			//	redraw = true;
		//	}
		//	else if(event.keyboard.keycode == ALLEGRO_KEY_D){
		//		if(event.keyboard.repeat == true){
		//			al_clear_to_color(al_map_rgb(0,0,0));
		//			P2.base.setX(x2+=3);
		//		}
		//		else{
		//		al_clear_to_color(al_map_rgb(0,0,0));
				//print_player(x-=5,y,r);
		//		P2.base.setX(x2+=5);
		//		}
		//		redraw = true;
		//	}
		//	else if(event.keyboard.keycode == ALLEGRO_KEY_A){
				
		/*		if(event.keyboard.repeat == true){
					al_clear_to_color(al_map_rgb(0,0,0));
					P2.base.setX(x2-=3);
				}
				else{
				al_clear_to_color(al_map_rgb(0,0,0));
				//print_player(x-=5,y,r);
				P2.base.setX(x2-=5);
				}
				//print_player(x+=5,y,r);
				redraw = true;
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
				//if(!al_get_timer_started(timer))
				//	al_start_timer(timer);
				//else al_resume_timer(timer);
				al_draw_text(font, al_map_rgb(0, 125, 15), 50, 50, 0, "hey");
				//al_resume_timer(timer);
				//al_flip_display();
				//print_rayo(x,y);
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
				al_stop_timer(timer);
				al_draw_text(font, al_map_rgb(0, 115, 175), 50, 50, 0, "hey");
				al_flip_display();	
			}
			else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				done = true;
			}
		}
		}
		}*/