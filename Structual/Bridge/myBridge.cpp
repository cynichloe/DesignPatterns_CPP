#include <iostream>
using namespace std;

class SportsImpl {
  public:
    SportsImpl(int rank, int effort) {
        m_rank = rank;
        m_effort = effort;
    }
    virtual void SportsFact() {
        cout << "Healthy factor Rank=" << m_rank << ", And effort is "<< m_effort<<"/10 !"<<endl;
    }
  protected:
    int m_rank;
    int m_effort;
};

class SwimSportsImpl: public SportsImpl{
  public:
    SwimSportsImpl(int rank, int effort, int minEffectiveTime): SportsImpl(rank,effort){
    m_minEffectiveTime=minEffectiveTime;
  }
  void SportsFact() {
        cout << "Healthy factor Rank=" << m_rank << ", And effort is "<< m_effort<<"/10 ! and Min effective time is="<<m_minEffectiveTime<<endl;
    }
  private:
    int m_minEffectiveTime;
};

class RunSportsImpl: public SportsImpl{
  public:
    RunSportsImpl(int rank, int effort, int KneeDamage): SportsImpl(rank,effort){
    m_KneeDamage=KneeDamage;
  }
  void SportsFact() {
        cout << "Healthy factor Rank=" << m_rank << ", And effort is "<< m_effort<<"/10 ! and potential damage to knee is="<<m_KneeDamage<<"/10 !"<<endl;
    }
  private:
    int m_KneeDamage;
};

class Sport{
protected:
  SportsImpl * m_sportsImpl;
public:
  Sport() {}; // for inheritence sake
  Sport(int rank, int effort){
    m_sportsImpl=new SportsImpl(rank,effort);
  }
  void TellFacts() const{
    m_sportsImpl->SportsFact();
  }
};

class Swim: public Sport{
public:
  Swim(int rank, int effort, int minEffectiveTime)
  {
    m_sportsImpl=new SwimSportsImpl(rank,effort,minEffectiveTime);
  }
  void TellFacts() const{
    m_sportsImpl->SportsFact();
  }
};

class Run: public Sport{
public:
  Run(int rank, int effort, int KneeDamage)
  {
    m_sportsImpl=new RunSportsImpl(rank,effort,KneeDamage);
  }
  void TellFacts() const{
    m_sportsImpl->SportsFact();
  }
};


int main() {
  Sport *Sport[2];
  Sport[0]=new Swim(1,8,30);
  Sport[1]=new Run(1,9,8);
  for (int i = 0; i < 2; i++)
    Sport[i]->TellFacts();
}