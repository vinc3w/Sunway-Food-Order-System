#include "./../include/order.h"

OrderPair Order::getMergedMenuItems()
{
	OrderPair merge{};
	for (const auto& pair : appetizers)
		merge.push_back(pair);
	for (const auto& pair : mains)
		merge.push_back(pair);
	for (const auto& pair : deserts)
		merge.push_back(pair);
	return merge;
}