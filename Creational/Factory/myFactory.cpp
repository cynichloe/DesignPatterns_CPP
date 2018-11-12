#import <iostream>
#import <string>
using namespace std;

class person{
public:
	virtual void Action()=0;
	virtual void BeingFunny()=0;
	virtual ~person() {};
};

class APerson: public person {
public:
	void Action()  {
		m_RaccoonStuff=true;
	}
	void BeingFunny()  {
		m_gooz=true;
	}
protected:
	bool m_RaccoonStuff;
	bool m_gooz;
};

class FangiPerson: public person {
public:
	void Action()  {
		m_cute=true;
	}
	void BeingFunny()  {
		m_laugh=true;
	}
protected:
	bool m_cute;
	bool m_laugh;
};

class personFactory{
public:
	enum personType{
		Fangi,
		Ahmadi
	};
	static person * CreatePerson(personType person_type){
		switch(person_type){
			case Fangi: return new FangiPerson();
			case Ahmadi: return new APerson();
		}
		throw "nooogi!";
	}
};

int main(){
	personFactory::CreatePerson(personFactory::Fangi);
}