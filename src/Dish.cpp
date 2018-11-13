#include "../include/Dish.h"

#ifndef DISH_H_
#define DISH_H_

#include <string>

enum DishType{
    VEG, SPC, BVG, ALC
};

class Dish{
public:
    Dish(int d_id, std::string d_name, int d_price, DishType d_type): id(d_id),name(d_name),price(d_price),type(d_type);{
    }
    int getId() const{
        return id;
    }
    std::string getName() const{
        return name;
    }
    int getPrice() const {
        return price;
    }
    DishType getType() const{
        return type;
    }
private:
	const int id;
    const std::string name;
    const int price;
    const DishType type;
}


#endif