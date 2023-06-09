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
	// List of category foods and prices
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

	// all categoy of food and prices put together
	OrderPair mergedMenuItems{};
	// list of user orders and quantity
	std::vector<std::pair<std::string_view, Count>> orders{};

	// member functions
	Order& printMenu();
	Order& printCourses(OrderPair& items, std::string_view categoryName);
	Order& printOrders();
	Order& getPayment();
	Order& printReceipt(double totalPrice, double payment);
public:
	Order()
	{
		// when class is contructed,
		// compile all list of food and prices into mergedMenuItems
		for (const auto& pair : appetizers)
			mergedMenuItems.push_back(pair);
		for (const auto& pair : mains)
			mergedMenuItems.push_back(pair);
		for (const auto& pair : deserts)
			mergedMenuItems.push_back(pair);
	}

	// member functions
	Order& getOrders();
};

#endif
