#include <string>
using namespace std;
class item
{
private:
	string id = "CIL020";
	float price = 50;
	int quantity = 10;
	void setID(string);
public:
	string name;
	float getPrice();
	string getID();
	int getQuantity();
	bool isAvailable();
	void setPrice(float);
	void setQuantity(int);
};

