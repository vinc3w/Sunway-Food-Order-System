#ifndef ORDER_H
#define ORDER_H

#include <string_view>
#include <vector>

using Price = double;
using Count = int;
using OrderPair = std::vector<std::pair<std::string_view, Price>>;

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

	OrderPair mergedMenuItems{};
	std::vector<std::pair<std::string_view, Count>> orders{};

	Order& printMenu();
	Order& printOrders();
	Order& getPayment();
	Order& printReceipt(double totalPrice, double payment);
public:
	Order()
	{
		for (const auto& pair : appetizers)
			mergedMenuItems.push_back(pair);
		for (const auto& pair : mains)
			mergedMenuItems.push_back(pair);
		for (const auto& pair : deserts)
			mergedMenuItems.push_back(pair);
	}

	Order& getOrders();
};

#endif
