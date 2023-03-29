#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Item{
    string itemName;
    int countOfItem;
public:
    Item(string newItemName, int newCountOfItem){
        this->itemName=newItemName;
        this->countOfItem=newCountOfItem;
    }
    void setCountOfItem(int newValue){
        this->countOfItem=newValue;
    }
    int getCountOfItem(){
        return this->countOfItem;
    }
    string getItemName(){
        return this->itemName;
    }
};

class Warehouse
{
    vector<shared_ptr<Item>> items;
    string warehouseName;
public:
    Warehouse(string name);
    void showAllGoods();
    ~Warehouse(){
        cout << "Destruktor magazynu"<<endl;
    };
    const string &getWarehouseName() const;
    vector<shared_ptr<Item>> getItems(){
        return this->items;
    }
    void addItem(string name, int count);
};

void Warehouse::showAllGoods()
{
    for(auto ptr: items){
        cout<<"Nazwa przedmiotu: "<<ptr->getItemName() << " Ilosc: "<< ptr->getCountOfItem()<<endl;
    }
}


const string &Warehouse::getWarehouseName() const
{
    return warehouseName;
}

void Warehouse::addItem(string name, int count)
{
    shared_ptr<Item> spr1(new Item(name,count));
    this->items.push_back(spr1);
}

Warehouse::Warehouse(string name)
{
    cout<<"Konstruktor magazynu"<<endl;
    shared_ptr<Item> spr1(new Item("Fotele",90));
    shared_ptr<Item> spr2(new Item("Biurka",120));
    shared_ptr<Item> spr3(new Item("Krzesla",180));
    shared_ptr<Item> spr4(new Item("Stoliki",45));
    shared_ptr<Item> spr5(new Item("Szafy",30));
    this->items.push_back(spr1);
    this->items.push_back(spr2);
    this->items.push_back(spr3);
    this->items.push_back(spr4);
    this->items.push_back(spr5);

    this->warehouseName = name;
}

class Shop
{
    string shopName;
    vector<Warehouse> warehouses;
public:
    Shop();
    Shop(string newShopName);
    void addWarehouse(Warehouse newWarehouse);
    void sellGood(string goodName, int count);
    void showWarehouses();
    void showShopName();
    ~Shop(){
        cout<<"Destruktor magazynu"<<endl;
    }
};

Shop::Shop()
{

}

Shop::Shop(string newShopName)
{
    cout<<"Konstruktor sklepu"<<endl;
    this->shopName = newShopName;
}

void Shop::addWarehouse(Warehouse newWarehouse)
{
    this->warehouses.push_back(newWarehouse);
}

void Shop::sellGood(string goodName, int count)
{
    bool sold = false;
    for(auto ptr: this->warehouses){
        auto war = ptr.getItems();
        for(auto i: war){
            if(i->getCountOfItem()>count && i->getItemName()==goodName){
                cout<<"Sprzedano z magazynu "<<ptr.getWarehouseName()<<endl;
                i->setCountOfItem(i->getCountOfItem()-count);
                sold = true;
                break;
            }
        }
        if(sold) break;
    }
    if(!sold){
        cout<<"Nie udalo sie sprzedac!"<<endl;
    }
}

void Shop::showWarehouses()
{
    cout<<"Magazyny:"<<endl;
    for(auto i:this->warehouses){
        cout<< i.getWarehouseName()<<endl;
    }
}

void Shop::showShopName()
{
    cout<<"Nazwa sklepu:"<<this->shopName<<endl;
}

int main() {
    unique_ptr<Warehouse> magazine1(new Warehouse("Meblowy"));
    unique_ptr<Warehouse> magazine2(new Warehouse("Gospodarczy"));
    unique_ptr<Shop> shop1(new Shop("Sklep"));

    magazine2->addItem("Worek na smieci",560);

    shop1->addWarehouse(*magazine1);
    shop1->addWarehouse(*magazine2);

    shop1->showWarehouses();
    cout<<endl;

    shop1->showShopName();
    shop1->sellGood("Worki",55);

    magazine2->showAllGoods();
    return 0;
}
