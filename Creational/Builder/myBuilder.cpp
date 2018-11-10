#import <iostream>
#import <string>
using namespace std;

class lover{
public:
	lover(){
		cout<<"hi lover"<<endl;
	};
	~lover(){cout<<"bye lover"<<endl;};
	void setRelationshipName(const string & relaName){
		m_relationshipName=relaName;
	}
	void setResidence(const string & residence){
		m_residence=residence;
	}
	void setFavFood(const string & favFood){
		m_favFood=favFood;
	}
	/*void summary() const{
		cout << "lovers with name "<<m_relationshipName<<" live in "<<m_residence<<", their favorate food is "<<m_favFood<<endl;
	}*/
private:
	string m_relationshipName;
	string m_residence;
	string m_favFood;
};

class loverBuilder{
public:
	loverBuilder(){ cout<<"hi loverBuilder"<<endl;};
	virtual ~loverBuilder(){ 
		delete m_lover;
		cout <<"bye loverbuilder "<<endl;
	};
	void createNewLover()
	{
		m_lover = new lover();
	}
	lover * getLover() const{
		return m_lover;
	}
	virtual void buildRelationshipName()=0;
	virtual void buildResidence()=0;
	virtual void buildFavFood()=0;
	virtual void buildRoutine()=0;

protected:
	lover *m_lover;
};

class OnegiBuilder : public loverBuilder {
public:
	OnegiBuilder(){ cout<<"hi OnegiBuilder"<<endl;};
	virtual ~OnegiBuilder(){ cout <<"bye onegiBuilder"<<endl;};
	virtual void buildRelationshipName(){
		cout<<"look"<<endl;
		m_lover->setRelationshipName("onegi");
	}
	virtual void buildResidence(){
		m_lover->setResidence("Nuremberg");
	}
	virtual void buildFavFood(){
		m_lover->setFavFood("Kalepache");
	}
	virtual void buildRoutine(){
		this->createNewLover();
		buildRelationshipName();
		this->buildResidence();
		this->buildFavFood();
	}
};

class HCCoupleBuilder : public loverBuilder {
public:
	HCCoupleBuilder(){ cout<<"hi HCCoupleBuilder"<<endl;};
	virtual ~HCCoupleBuilder(){cout <<"bye HCCoupleBuilder"<<endl;};
	virtual void buildRelationshipName(){
		m_lover->setRelationshipName("hccouple");
	}
	virtual void buildResidence(){
		m_lover->setResidence("Rostok");
	}
	virtual void buildFavFood(){
		m_lover->setFavFood("kuchen");
	}
	virtual void buildRoutine(){
		this->createNewLover();
		this->buildRelationshipName();
		this->buildResidence();
		this->buildFavFood();
	}
};

class GACoupleBuilder : public loverBuilder {
public:
	GACoupleBuilder(){ cout<<"hi GACoupleBuilder"<<endl;};
	virtual ~GACoupleBuilder(){cout <<"bye GACoupleBuilder"<<endl;};
	virtual void buildRelationshipName(){
		m_lover->setRelationshipName("gacouple");
	}
	virtual void buildResidence(){
		m_lover->setResidence("Barcelona");
	}
	virtual void buildFavFood(){
		m_lover->setFavFood("pizza");
	}
	virtual void buildRoutine(){
		this->createNewLover();
		this->buildRelationshipName();
		this->buildResidence();
		this->buildFavFood();
	}
};

class CoupleGen{
public:
	void makeLover(loverBuilder * loverBuilder){
		m_loverBuilder=loverBuilder;
		m_loverBuilder->buildRoutine();
	}
private:
	loverBuilder * m_loverBuilder;
};

int main(){
	CoupleGen *coupleGen=new CoupleGen();
	OnegiBuilder *onegibuilder=new OnegiBuilder();
	//HCCoupleBuilder *hcCoupleBuilder=new HCCoupleBuilder();
	//GACoupleBuilder *gaCoupleBuilder=new GACoupleBuilder();

	coupleGen->makeLover(onegibuilder);
	delete onegibuilder;
	delete coupleGen;
	//std::string haha="testing";
	//std::string haha2=&haha;
	//cout<<haha2<<endl;
	//coupleGen->makeLover(hcCoupleBuilder);
	//coupleGen->makeLover(gaCoupleBuilder);
	return 1;
};