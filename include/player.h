#ifndef PLAYER_H
#define PLAYER_H
//player.h

clqss player{
public:
	player(vec3_t start);

	//Accessors
	&vec3_t getPosPtr() const {return pos;};
	void getPos(vec3_t a) const;
	double getX() const {return pos[0];};
	double getY() const {return pos[1];};
	double getZ() const {return pos[2];};

	//Mutators
	void setPos(vec3_t a);
	void setX(double x);
	void setY(double y);
	void setZ(double z);

private:
	vec3_t pos;
	vec3_t dir;
	int health;
	int weapon;
};

#endif
