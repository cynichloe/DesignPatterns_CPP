#include <iostream>
using namespace std;
#include <unordered_map>;

// This common interface is what interact with the factory
class BlackEntry {
    public:
        void setDeeds(String deed);
        void speech() const ;
};

////////////////////
// real cases implementing the interface, variables reside here.
class ShibeAtFault : public BlackEntry {
    private:
        const String m_Apology;
        String m_deed;
    public:
        ShibeAtFault(){
            m_Apology="Sorry from Shibe!"; 
        }
        void setDeeds(String deed){
            m_deed=deed;
        }
        void speech() const{
            cout<<m_Apology<<" "<<m_deed<<endl;
        }
}

class RaccoonAtFault : public BlackEntry{
    private:
      const String m_Apology;
      String m_deed;
    public:
      RaccoonAtFault(){
         m_Apology="Sorry from Raccugi!";
      }
      void setDeeds(String deed){
          m_deed=deed;
      }
      void speech() const{
         cout<<m_Apology<<" "<<m_deed<<endl;
      }
}
/////////////

class BlackEntryFactory{
    private:
       static unordered_map<String, *BlackEntry > blackDic=new unordered_map<String, *BlackEntry>;
    public:
       static BlackEntry * getBlackEntry(String who){
          BlackEntry * be= null;
         if blackDic.contains(who)
            be=blackDic.get(who)
         else{
            switch(who){
                case "Fangi":{
                	cout<<"oops! Fangi not cool!"<<endl;
                	be= new ShibeAtFault();
                    break;
                }
                case "Ahmadi":{
                	cout<<"nooo! Ahmadi again? :( "<<endl;
                	be= new RaccoonAtFault();
                	break;
                }
                default: {
                	cout<<"who?"<<end; 
                	break;
                }
            }
        }
        return be;
    }

int main(){
	String EntryType[]=["Fangi","Ahmadi"];
	String deeds[]=["goozed","raccooned sth"];
	for (int i=0;i<1;i++){
		BlackEntry *be= BlackEntryFactory.getBlackEntry(EntryType[rand()%2]);
		be->setDeeds(deeds[rand()%2]);
		be->speech();
	}
}

                  
