//Class_Adapter_Design_Pattern

#include <iostream>
using namespace std;
/*
 * Target
 * defines specific interface that Client uses
 */
class TargetCircle
{
public:
	virtual ~TargetCircle() {}
	virtual void draw() = 0;
};

/*
 * Adaptee
 * all requests get delegated to the Adaptee which defines
 * an existing interface that needs adapting
 */

class AdapteeCircle
{
private:
	double m_radius;
public:
	~AdapteeCircle(){}
	AdapteeCircle(double radius) : m_radius(radius)
	{
		cout << "Adaptee Circle with radius " << m_radius << " created." << endl;
	}

	void oldDraw()
	{
		cout << "Adaptee Circle has been drawn with radius "<< m_radius <<"." << endl;
	}

};
/*
 * Adapter
 * implements the Target interface and lets the Adaptee respond
 * to request on a Target by extending both classes
 * ie adapts the interface of Adaptee to the Target interface
 */
class CircleAdapter: public TargetCircle, private AdapteeCircle
{
public:
	CircleAdapter(double diameter) : AdapteeCircle(diameter / 2)
	{
		cout << "Circle Adapter created circle with diameter " << diameter << "." << endl;
	}
	void draw()override
	{
		cout << "Circle Adapter adapted method draw() from Target Circle for Adaptee Circle:" << endl;
		oldDraw();
	}
};



int main()
{
	TargetCircle* circle = new CircleAdapter(20);
	circle->draw();
	delete circle;
	return 0;
}

