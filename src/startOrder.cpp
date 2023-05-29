#include "./../include/order.h"
#include <iostream>

void Order::startOrder()
{
    printMenu();
    getOrders();
    getPayment();
}
