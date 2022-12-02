#include "item.h"
void item::setID(string newID)
{
	id = newID;
}
float item::getPrice()
{
	return price;
}
void item::setPrice(float newPrice)
{
	price = newPrice;
}
int item::getQuantity()
{
	return quantity;
}
void item::setQuantity(int new_quantity)
{
	quantity = new_quantity;
}
bool item:: isAvailable()
{
	if (getQuantity() == 0)
		return false;
	return true;
}
string item::getID()
{
	return id;
}