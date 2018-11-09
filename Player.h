#include "Punto.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
class Player{
	private:
		Punto mIzquierda, mDerecha;
		float r;
		int vida;
	public:
		Punto base;
		Player(float _x=0, float _y=0, float _r = 25){
			this->base.setPos(_x,_y);
			r = _r;
			vida = 10;
		}
		void setPlayer(float _x, float _y, float _r){
			this->base.setPos(_x,_y);
			r = _r;
		}
		float getR(){
			return r;
		}
		int getVida(){
			return vida;
		}
		void setVida(int _vida){
			vida -= _vida;
		}
		void setmIzquierda(float mx, float my){
			this->mIzquierda.setPos(mx,my);
		}
		void setmDerecha(float mx, float my){
			this->mDerecha.setPos(mx,my);
		}
		void print(){
			al_draw_circle(this->base.getX(), this->base.getY(), this->getR(), al_map_rgb(150,150,150),0);//body
			al_draw_line(this->base.getX(), this->base.getY()+this->getR(), this->base.getX(), this->base.getY()+3*this->getR(), al_map_rgb(150,150,150),0);//body
            al_draw_line(this->base.getX(), this->base.getY()+2*this->getR(), this->base.getX()-2*this->getR(), this->base.getY()+2*this->getR(), al_map_rgb(150,150,150),0);
            //lhand
            al_draw_line(this->base.getX(), this->base.getY()+2*this->getR(), this->base.getX()+2*this->getR(), this->base.getY()+2*this->getR(), al_map_rgb(150,150,150),0); //rhand
            al_draw_line(this->base.getX(), this->base.getY()+3*this->getR(), this->base.getX()-2*this->getR(),this->base.getY()+4*this->getR(), al_map_rgb(150,150,150),0);
            //lfoot
            al_draw_line(this->base.getX(), this->base.getY()+3*this->getR(), this->base.getX()+2*this->getR(), this->base.getY()+4*this->getR(), al_map_rgb(150,150,150),0);
			for (int i=0; i < this->getVida(); i++){
				al_draw_line(this->base.getX()+this->getR()-i*5,this->base.getY()-this->getR()*3,this->base.getX()+this->getR()-i*5, this->base.getY()-this->getR()-5,al_map_rgb(50,50,50),0);
			}
            //rfoot
          //  al_flithis->disthis->ay();
		}
  


		/*void mover(ALLEGRO_EVENT &event){
			if(event.tythis-> == ALLEGRO_EVENT_KEY_DOWN){
				if(event.keyboard.keycode == ALLEGRO_KEY_LEFT){
					al_clear_to_color(al_mathis->rgb(0,0,0));
					gbase.setX(x-5);
				}
				else if(event.keyboard.keycode == ALLEGRO_LEY_RIGHT){
					al_clear_to_color(al_mathis->rgb(0,0,0));
					gbase.setX(x+5);

				}
			}
		}*/
};
