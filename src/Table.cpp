#include "../include/Table.h"

#ifndef TABLE_H_
#define TABLE_H_

#include <vector>
#include "Customer.h"
#include "Dish.h"

typedef std::pair<int, Dish> OrderPair;

class Table{
public:
    Table(int t_capacity):capacity(t_capacity){
        open = false;
    }
    int getCapacity() const{
        return capacity;
    }
    void addCustomer(Customer* customer){
        if ( open == false )
            customersList.push_back(*customer);
    }
    void removeCustomer(int id);
    Customer* getCustomer(int id){
        for(int i=0;i<customersList.size();i++){
            if (*(customersList.at(i)).getId == id){ //לבדוק את הכוכבית
                return customersList.at(i);
            }

        }
    }
    std::vector<Customer*>& getCustomers(){
        vector<Customer*>& r_customers = customersList;
        return r_customers;
    }
    std::vector<OrderPair>& getOrders(){
        vector<OrderPair*>& r_orders = orderList;
        return r_orders;
    }
    void order(const std::vector<Dish> &menu){//// לעבור שוב אחרי שעשינו מחלקת CUSTOMER
        for(int i=0;i < customersList.size();i++){
            vector <int> currentOrder = (customerList.at(i)).order();
            int tempId = (customerList.at(i)).getId();
            for(int i=0;i<currentOrder.size();i++){
                      orderList.push_back(std::make_pair(tempId,menu.at(currentOrder.at(i))); //לבדוק אם צריך את ה-STD
            }
        }
    }
        for(int i=0;i<customersList.size();i++){

            orderList.push_back(();
        }
    }
    void openTable(){
        open = true;
    }
    void closeTable(){
        open = false;
        }
    int getBill(){
        int ans(0) ;
        for(int i=0;i<orderList.size();i++){
            ans = ans + ((orderList.at(i)).second).getPrice();
            }
            return ans;
        }
    bool isOpen(){
        return open;
    }
private:
    const int capacity;
    bool open;
    std::vector<Customer*> customersList;
    std::vector<OrderPair> orderList; //A list of pairs fzor each order in a table - (customer_id, Dish)
};


#endif