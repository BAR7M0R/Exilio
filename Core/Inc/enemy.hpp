/*
 * entities.hpp
 *
 *  Created on: Jan 2, 2025
 *      Author: dev
 */

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "entitiesInitData.hpp"
#include "virtualDisplay.hpp"
namespace entities {
class entity{
	virtual void move();
};
class player : entity{
	//void move(uint8_t next) override;
};
class enemy1 : entity {
public:
	void move() override;
private:

};
class enemy2 : entity {
public:
	void move() override;
private:

};
class enemy3 : entity {
public:
	void move() override;
private:

};
} /* namespace entities */

#endif /* ENEMY_HPP_ */
