#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "Dish.h"

class Customer{
public:
    Customer(std::string c_name, int c_id);
    virtual std::vector<int> order(const std::vector<Dish> &menu)=0;
    virtual std::string toString() const = 0;
    std::string getName() const;
    int getId() const;
private:
    const std::string name;
    const int id
};


class VegetarianCustomer : public Customer { //מנה צמחונית עם תז נמוך ביותר ומשקה לא אלכהולי הכי יקר
public:
	VegetarianCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
};


class CheapCustomer : public Customer {//מזמינים פעם אחת ומנה זולה ביותר
public:
	CheapCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
};


class SpicyCustomer : public Customer {// המנה החריפה היקרה ביותר , עבור הזמנה נוספת - משקה לא אלכוהולי הכי זול
public:
	SpicyCustomer(std::string name, int id);
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
};


class AlchoholicCustomer : public Customer {//רק משקאות אלכהולים . מתחיל עם המשקה הכי זול וממשיך בסדרה עולה לפי מחיר
public:
	AlchoholicCustomer(std::string name, int id)
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
};


#endif