//investment.cpp
#include <iostream>
#include <string>
using namespace std;

//Your declarations and implementations would go here

//////////class Investment///////////////

class Investment
{
public:
	Investment(string name, int purchasePrice)
		:m_name(name), m_purchasePrice(purchasePrice)
	{}
	virtual ~Investment() {};
	string name() const { return m_name; }
	virtual bool fungible() const = 0;
	virtual string description() const = 0;
	int purchasePrice() const { return m_purchasePrice; }


private:
	string m_name;
	int m_purchasePrice;
};


/////////////class Painting////////////////

class Painting :public Investment
{
public:
	Painting(string name, int purchasePrice)
		: Investment(name, purchasePrice), m_fungible(false), m_description("painting")
	{}
	virtual ~Painting()
	{
		cout << "Destroying " << name() << ", a painting" << endl;
	}
	virtual bool fungible() const { return m_fungible; }
	virtual string description() const { return m_description; }


private:
	bool m_fungible;
	string m_description;

};


//////////class House////////////

class House :public Investment
{
public:
	House(string name, int purchasePrice)
		: Investment(name, purchasePrice), m_fungible(false), m_description("house")
	{}
	virtual ~House()
	{
		cout << "Destroying the house " << name() << endl;
	}
	virtual bool fungible() const { return m_fungible; }
	virtual string description() const { return m_description; }


private:
	bool m_fungible;
	string m_description;

};

//////////class Stock/////////////////

class Stock :public Investment
{
public:
	Stock(string name, int purchasePrice, string description)
		: Investment(name, purchasePrice), m_fungible(true), m_description("stock trading as " + description)
	{}
	virtual ~Stock()
	{
		cout << "Destroying " << name() << ", a stock holding" << endl;
	}
	virtual bool fungible() const { return m_fungible; }
	virtual string description() const { return m_description; }


private:
	bool m_fungible;
	string m_description;

};

void display(const Investment* inv)
{
	cout << inv->name();
	if (inv->fungible())
		cout << " (fungible)";
	cout << ": " << inv->description() << " bought for $" << inv->purchasePrice() << endl;
}

int main()
{
	Investment* portfolio[4];
	portfolio[0] = new Painting("Salvator Mundi", 450300000);
	// Stock holdings have a name, value, and ticker symbol
	portfolio[1] = new Stock("Alphabet", 100000, "GOOGL");
	portfolio[2] = new Stock("Symantec", 50000, "SYMC");
	portfolio[3] = new House("4 Privet Drive", 660000);

	for (int k = 0; k < 4; k++)
		display(portfolio[k]);

	// Clean up the investments before exiting
	cout << "Cleaning up" << endl;
	for (int k = 0; k < 4; k++)
		delete portfolio[k];
}
