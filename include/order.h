#ifndef ORDER_H
#define ORDER_H

#include <string_view>
#include <vector>

using OrderPair = std::vector<std::pair<std::string_view, double>>;

class Order
{
private:
	OrderPair appetizers{{
		{"Kerabu Mangga", 5.5},
		{"Popia Sayur Ranggup", 2.5},
		{"Lokcing / Satay Ikan", 3}
	}};
	OrderPair mains{{
		{"Ayam Percik dan Nasi Putih", 7},
		{"Daging Rendang", 8},
		{"Nasi Kunyit Rendang Daging", 9},
		{"Nasi Beriyani", 12}
	}};
	OrderPair deserts{{
		{"Bubur Caca", 3},
		{"Chocolate Ice-cream", 3},
		{"Strawberry Ice-cream", 3},
		{"Vanilla Ice-cream", 3},
		{"Fresh Cut Fruit", 0}
	}};
	std::vector<std::pair<std::string_view, int>> orders{};
public:
	Order& printMenu();
	Order& printOrders();
	Order& getOrders();
	Order& editOrders();
	Order& getPayment();
	Order& printReceipt(double totalPrice, double payment);

	OrderPair getMergedMenuItems();

	void removeOrders();
	void insertOrders();
	void startOrder();
};

#endif
