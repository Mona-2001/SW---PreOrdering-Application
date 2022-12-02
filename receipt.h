#include <string>
using namespace std;
class receipt
{
private:
	string id = "O001";
	float calculateTaxes(float);
	float total;

public:
	float getTotal();
	string getID();
	void setID(string);
};

