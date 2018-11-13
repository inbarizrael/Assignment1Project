#include "../include/Action.h"
extern Restaurant* backup;
#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <iostream>
#include "Customer.h"

enum ActionStatus{
    PENDING, COMPLETED, ERROR
};

//Forward declaration
class Restaurant;

class BaseAction{
public:
    BaseAction(){
        status = PENDING;
        errorMsg ="";
    }
    ActionStatus getStatus() const {
        return status;
    }
    virtual void act(Restaurant& restaurant)=0;
    virtual std::string toString() const=0;
protected:
    void complete(){
        status = COMPLETED;
    }
    void error(std::string errorMsg) {
        status = ERROR;
        this.errorMsg = errorMsg;
    }
    std::string getErrorMsg() const{
        return errorMsg;
    }
private:
    std::string errorMsg;
    ActionStatus status;
};


class OpenTable : public BaseAction {
public:

    OpenTable(int id, std::vector<Customer *> &customersList):tableId(id){
        customers = customersList;
    }

    void act(Restaurant &restaurant){
        int temp = restaurant.getNumOfTables();
        if( tableId < 0 | tableId > temp  | *(restaurant.getTable(tableId)).isOpen() | *(restaurant.getTable(tableId)).getCapacity() < customers.size()) {
           this.error("Table does not exist or is already open") ;
           }
           else{
            Table tempTable = *(restaurant.getTable(tableId)) ;
                for(int i=0 ; i < customersList.size(); i++){
                    tempTable.addCustomer(customerList.at(i));
                    }
                 tempTable.openTable();
                 this.complete();
                }
            }

     std::string toString() const{
        string ans = "open " + tableId ;
        for(int i=0;i<customers.size();i++){
            ans = ans + " " + (customers.at(i))->toString();
            }
            ans = ans + this.getStatus();
            return ans;
    }

private:
	const int tableId;
	std::vector<Customer *> customers;
};


class Order : public BaseAction {
public:
    Order(int id): tableId (id){}


    void act(Restaurant &restaurant){
        int temp = restaurant.getNumOfTables();
        if( tableId < 0 | tableId > temp  | *(restaurant.getTable(tableId)).isOpen()) {
           this.error("Table does not exist or is already open") ;
           }
        else{
          Table tempTable = *(restaurant.getTable(tableId));
          tempTable.order(restaurant.getMenu());// הפונ הזאת שולחת להזמנה לכל לקוח+מעדכנת את הליסט בטייבל
         string ans = "order " + tableId ;
        vector <Customer*> tempCustomerList= tempTable.getCustomers();
        for (int i= 0; i<tempCustomerList.size(); i++) {
            Customer* temp = tempCustomerList.at(i) ;
           vector <int> customerOrder = temp->order(restaurant.getMenu());
            for(int j = 0 ; j<customerOrder.size();j++ ){
                ans = ans + "/n" + temp->getName() + " ordered " + menu.at((customerOrder.at(i)).getName());
         }
    }
                std:: cout << ans << ;
                this.complete();
    }
    }
    std::string toString() const{
        string ans = "order " + tableId + " " + this.getStatus();
        return ans;
    }
private:
    const int tableId;
};

class MoveCustomer : public BaseAction {
public:
    MoveCustomer(int src, int dst, int customerId) : id(customerId) , srcTable(src) , dstTable(dst){}
    void act(Restaurant &restaurant){
        int temp = restaurant.getNumOfTables();
        Table t_src = *(restaurant.getTable(src));
        Table t_dst = *(restaurant.getTable(dst));
        bool exist = false;
        vector <Customer*> tempCustomerList = (t_src).getCustomers();
        Customer* tempCustomer;
        for(int i=0;i < tempCustomerList.size() ; i++){
            if(tempCustomerList.at(i)->getId() == customerId){
                exist = true;
                tempCustomer = tempCustomerList.at(i);
                break;
                }
         if ( exist == true && dst => 0 && dst <= temp  && t_dst.isOpen() && (t_dst.getCustomers()).size() < t_dst.getCapacity() ){
             std :: vector <OrderPair>  src_orders = t_src.getOrders() ;
             std :: vector <OrderPair>  dst_orders = t_dst.getOrders() ;
            for (int i =0; i<src_orders.size() ; i++) {
                if ((src_orders.at(i)).first == customerId){
                    std :: Pair temp = src_orders.at(i) ;
                    src_orders.erase(i,temp) ;
                    std_orders.push_back(temp) ;
                    }
            }
            if((t_src.getCustomers()).size() == 1){
                       t_src.closeTable();
                        }
                this.complete();
                t_src.removeCustomer(customerId);
                t_dst.addCustomer(tempCustomer);

         }
         else{
              this.error("Cannot move customer") ;
         }

    }

    std::string toString() const{
        string ans = "move " + srcTable + " " +  dstTable + " " + id + " " + this.getStatus();
        return ans;
    }
    }
private:
    const int srcTable;
    const int dstTable;
    const int id;
};


class Close : public BaseAction {
public:
    Close(int id) : tableId(id){}
    void act(Restaurant &restaurant){
        int temp = restaurant.getNumOfTables();
        if( tableId < 0 | tableId > temp  | !(*(restaurant.getTable(tableId)).isOpen())){
          this.error("Table does not exist or is not open") ;
        }
        else{
            Table tempTable = *(restaurant.getTable(tableId));
            int tempBill = tempTable.getBill();
            tempTable.close();
            this.complete();
            (tempTable.getOrders()).clear();
            vector <Customer*> tempCustomersList = tempTable.getCustomers();
            for(int i = 0 ; i < tempCustomersList.size() ; i++){
                delete tempCustomersList.at(i) ;
                }
             tempCustomersList.clear();
            }
            std :: cout << "Table " + tableId + " was closed." " Bill " + tempBill + "NIS" <<;
        }
    }
    std::string toString() const{
        string ans =  "close " + tableId + " " + this.getStatus();
        return ans;
    }
private:
    const int tableId;
};


class CloseAll : public BaseAction {
public:
    CloseAll(){}

    void act(Restaurant &restaurant){
        for (int i = 0; i<restaurant.getNumOfTables() ; i++){
            Table temp_table = *restaurant.getTable(i) ;
            if ( temp_table.isOpen() == true ){
                Close x = new Close(i) ;
                x.Close(i) ;

        }
    }
    this.complete() ;
    }

    std::string toString() const {
        return "closeall" + " " + "completed";

    }
private:
};


class PrintMenu : public BaseAction {
public:
    PrintMenu(){}

    void act(Restaurant &restaurant){
       vector<Dish> c_menu = restaurant.getMenu() ;
       string ans = "";
       for (int i=0; i < c_menu.size() ; i++) {
           Dish curr_dish = menu.at(i) ;
           ans = ans + '/n' +  curr_dish.getName() + " " + curr_dish.getType() + " " + curr_dish.getPrice() +"NIS" ;
        }
        this.complete();
        std :: cout << ans << ;

    }

    std::string toString() const {
        return "menu" + " completed";
    }
private:
};


class PrintTableStatus : public BaseAction {
public:
    PrintTableStatus(int id): tableId(id) {}

    void act(Restaurant &restaurant){
        Table c_table = *(restaurant.getTable(tableId));
        string status = "close";
        if(c_table.isOpen()){
            status = "open";
        std:: cout<< "Table " + tableId + " status:" + status + '/n' + "customers:" <<;
        vector<Customer*> c_customerList = c_table.getCustomers() ;
         std :: cout<< "Customers:" <<endl;
        for (int i=0; i<c_customerList.size(); i++ ) {
            Customer c_custoemr = *customerList.at(i) ;
            std :: cout<< c_customer.getId() + " " + c_customer.getName()<<endl;
            std :: cout<< "Orders:" <<endl;
         for(int i=0 ; i < (c_table.getOrders()).size() ; i++){
             Dish c_dish = ((c_table.getOrders()).at(i)).second ;
             int tempId = ((c_table.getOrders()).at(i)).first ;
              std :: cout<< c_dish.getName() + " " + c_dish.getPrice() + "NIS " + tempId <<endl;
         }
         }
            std :: cout << "Current Bill: " + c_table.getBill() <<endl;
         }
         else{
           std:: cout<< "Table " + tableId + " status:" + status <<;
           }
         this.complete();
        }


    std::string toString() const{
            return "status " + tableId + " " +  this.getStatus();
        }
private:
    const int tableId;
};


class PrintActionsLog : public BaseAction {
public:
    PrintActionsLog(){}
    void act(Restaurant &restaurant){
        string ans = "";
       vector<BaseAction*> temp_vec = restaurant.getActionsLog();
       for (int i=0 ; i<temp_vec.size() ; i++){
           ans = *(temp_vec.at(i)).toString() + '/n';
           }
           std :: cout << ans << ;
       }

    std::string toString() const {
        return "log " + "completed";
        }
private:
};


class BackupRestaurant : public BaseAction {
public:
    BackupRestaurant();
    void act(Restaurant &restaurant);
    std::string toString() const;
private:
};


class RestoreResturant : public BaseAction {
public:
    RestoreResturant();
    void act(Restaurant &restaurant);
    std::string toString() const;

};


#endif