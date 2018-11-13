download
#include "../include/Customer.h"

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "Dish.h"

class Customer{

public:
    Customer(std::string c_name, int c_id): name(c_name), id(c_id){
    }

    virtual std::vector<int> order(const std::vector<Dish> &menu)=0;

    virtual std::string toString() const = 0 {

    }
    std::string getName() const{
        return name;
    }
    int getId() const{
        return id;
    }
private:
    const std::string name;
    const int id
};


class VegetarianCustomer : public Customer {
public:
	VegetarianCustomer(std::string name, int id){
	    new Customer(name,id);
	    vegBevId = -1;
	    vegDishId = -1;
	    firstOrder = true;
	}
    std::vector<int> order(const std::vector<Dish> &menu){//מנה צמחונית ראשונה משקה הכי יקר לא אלכוהולי
	    Vector<int> ans ;
	    if(firstOrder == true ){
	        this.setVeg(menu);
	        firstOrder == false;
	    }
	     if(!(vegBevId== -1 || vegDishId == -1 )){
	            ans.push_back(vegBevId);
	            ans.push_back(vegDishId);
	     }
	     return ans;
	}
    std::string toString() const;

	void setVeg(const std::vector<Dish> &menu){
	    int min;
	    bool firsBev = false;
	    bool foundDish = false;
	    for(int i=0;i<menu.size();i++){
	        if(foundDish == false && ((menu.at(i)).getType() == VEG) {//לבדוק על סינטקס VEG
	           vegDishId = (menu.at(i)).getId();
	        }
	        if((menu.at(i)).getType() == BVG ){
	            if ( firstBev == false){
	                min = (menu.at(i)).getPrice();
	                firstBev = true;
	                }
	            if((menu.at(i)).getPrice()< min){
	                min = (menu.at(i)).getPrice();
	                vegBevId = (menu.at(i)).getId();
	                }

	        }
	    }

	}

private:
    int vegBevId;
	int vegDishId;
	bool firstOrder;



};


class CheapCustomer : public Customer {
public:
	CheapCustomer(std::string name, int id){
	        new Customer(name,id);
	        firstOrder = true;
	}
    std::vector<int> order(const std::vector<Dish> &menu){
	    vector<int> ans;
	   if(firstOrder == true) {
	       int min = (menu.at(0)).getPrice();
	       ans.push_back(0);
	       for(int i=0;i<menu.size();i++){
	         if((menu.at(i)).getPrice() < min){
	             min = (menu.at(i)).getPrice();
	             ans.clear();
	             ans.push_back(i)
	         }
	       }
	   }
	   return ans;
	}

    std::string toString() const;
private:
    bool firstOrder;
};


class SpicyCustomer : public Customer {
public:
	SpicyCustomer(std::string name, int id){
	    new Customer(name,id);
	    this.spicyBevId = -1;
	    this.firstOrder = false;
	}
    std::vector<int> order(const std::vector<Dish> &menu){
	    vector<int> ans;
	    if(firstOrder == true){
	        int max = 0;
	        int minBev;
	        bool firstBev = true;
	        for(int i=0; i<menu.size(); i++){
	            if ( (menu.at(i)).getType() == SPC) {
	                if ((menu.at(i)).getPrice() > max){
	                    max = (menu.at(i)).getPrice() ;
	                    ans.clear() ;
	                    ans.push_back(i);
	                }
	            }
	            if( (menu.at(i)).getType() == BVG){
	                if(firstBev==true){
	                    minBev = (menu.at(i)).getPrice();
	                }
	                if ((menu.at(i)).getPrice() < minBev){
	                    minBev = (menu.at(i)).getPrice() ;
	                    spicyBevId = i ;
	                    }
	            }
	    }
	        return ans;

	}
	    ans.push_back(spicyBevId) ;
	    return ans;
	}
    std::string toString() const;
private:
    bool firstOrder ;
    int spicyBevId ;
};


class AlchoholicCustomer : public Customer {
public:
	AlchoholicCustomer(std::string name, int id){
	    new Customer(name,id) ;
        firstOrder = true;
	}

    std::vector<int> order(const std::vector<Dish> &menu){
        vector<int> ans;
	    int min;
	    Dish min_d ;
	    if (firstOrder == true){
            this.sortAlc(menu);
        }
        min = (sortAlc.at(0)).getPrice();
	    min_d = sortAlc.at(0);
	    int sorAlc_index = 0 ;
	    for (int i = 1; i<sortAlc.size(); i++){
	        if((sortAlc.at(i)).getPrice() < min){
	            min = (sortAlc.at(i)).getPrice();
	            min_d = sortAlc.at(i) ;
	            sortAlc_index = i ;
	        }
	     }
	    ans.push_back((min_d).getId()) ;
	    sortAlc.erase(sortAlc_index, min_d);

	    return ans;

	}
	void sortAlc(const std::vector<Dish> &menu){
	    vector<int> alcVector ;
	    for (int i=0; i<menu.size(); i++){
	        if((menu.at(i)).getType() == ALC){
	            alcVector.push_back(menu.at(i));
	        }
	    }
	    alcBev = alcVector ;    //לבדוק אם ההשמה תקינה
	    }

    std::string toString() const;
private:
    bool firstOrder ;
    vector<int> alcBev;
}


#endif