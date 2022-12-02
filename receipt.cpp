#include "receipt.h"
float receipt::calculateTaxes(float orgPrice) // return the tax part only, but modifies the whole total
{
	// assume 15% is added as taxes
	total = orgPrice + 0.15 * orgPrice;
	return(0.15 * orgPrice);
}
float receipt::getTotal()
{
	return total;
}
void receipt::setID(string newID)
{
	id = newID;
}
string receipt::getID()
{
	return id;
}
