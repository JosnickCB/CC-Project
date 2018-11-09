#ifndef PUNTO_H
#define PUNTO_H

class Punto{
	private:
		float x,y;
	public:
		Punto(int a = 0, int b = 0): x(a), y(b) {}
		float getX() const{return x;}
		float getY() const{return y;}
		//float getPos() const;
		void setX(float n){ x = n;}
		void setY(float n){ y = n;}
		void setPos(float _x,float _y){ x = _x; y = _y;}
};

#endif
