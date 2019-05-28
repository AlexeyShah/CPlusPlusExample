#include <iostream>
#include <string>
using namespace std;

class substance {
private:

	string name = "";
	double density = 0.;

public:

	substance() {};

	substance(string name, double density) {
		this->name = name;
		this->density = density;
	};

	~substance() {
		this->name = "";
		this->density = 0.;
	};

	string getName() {
		return this->name;
	};

	void setName(string name) {
		this->name = name;
	};

	double getDensity() {
		return this->density;
	};

	void setDensity(double density) {
		this->density = density;
	};
	
	virtual void Show() {
		cout << "Substance name: " << this->name << endl;
		cout << "Substance density: " << this->density << endl;
	}
};

class fluyid:public substance {
private:
	double viscidity = 0.;
public:
	fluyid() :substance() {
	};
	fluyid(double viscidity) :substance() {
		this->viscidity = viscidity;
	};
	fluyid(double viscidity, string name, double density) :substance(name, density) {
		this->viscidity = viscidity;
	};
	double getViscidity() {
		return this->viscidity;
	}
	void setViscidity(double viscidity) {
		this->viscidity = viscidity;
	}
	void setName(string name) {
		substance::setName(name);
	};
	void setDensity(double density) {
		substance::setDensity(density);
	};
	void Show() override {
		cout << "Fluyid name: " << this->getName() << endl;
		cout << "Fluyid density: " << this->getDensity() << endl;
		cout << "Fluyid viscidity: " << this->viscidity << endl;
	}
};

int main()
{
	substance subs;
	subs.setName("substance");
	subs.setDensity(5.4);

	subs.Show();

	fluyid fluyid;

	fluyid.setName("fluyid");
	fluyid.setDensity(10.7);
	fluyid.setViscidity(9.7);

	fluyid.Show();

	return 0;
}