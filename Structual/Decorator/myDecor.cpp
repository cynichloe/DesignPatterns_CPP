#include <iostream>
using namespace std;


class I {

  public:
    I() {cout<<"I ctor"<<endl;}
    virtual ~I(){}

    virtual void do_it() = 0;

};

 

class A: public I {

  public:
    A() {cout<<"A ctor"<<endl;}
    ~A() {

        cout << "A dtor" << '\n';

    }

    /*virtual*/

    void do_it() {

        cout << 'A';

    }

};

 

class D: public I {

  public:
    D() {cout<<"D ctor"<<endl;}
    D(I *inner) {

        m_wrappee = inner;

    }

    ~D() {

        delete m_wrappee;

    }

    /*virtual*/

    void do_it() {

        m_wrappee->do_it();

    }

  private:

    I *m_wrappee;

};

 

class X: public D {

  public:
    X(I *core): D(core){ cout<<"X ctor"<<endl;}

    ~X() {

        cout << "X dtor" << "   ";

    }

    /*virtual*/

    void do_it() {

        D::do_it();

        cout << 'X';

    }

};

 

class Y: public D {

  public:

    Y(I *core): D(core){ cout<<"Y ctor"<<endl;}

    ~Y() {

        cout << "Y dtor" << "   ";

    }

    /*virtual*/

    void do_it() {

        D::do_it();

        cout << 'Y';

    }

};

 

class Z: public D {

  public:

    Z(I *core): D(core){ cout<<"Z ctor"<<endl; }

    ~Z() {

        cout << "Z dtor" << "   ";

    }

    /*virtual*/

    void do_it() {

        D::do_it();

        cout << 'Z';

    }

};

 

int main() {

  I *anX = new X(new A);

  I *anXY = new Y(new X(new A));

  I *anXYZ = new Z(new Y(new X(new A)));

  anX->do_it();

  cout << '\n';

  anXY->do_it();

  cout << '\n';

  anXYZ->do_it();

  cout << '\n';

  delete anX;

  delete anXY;

  delete anXYZ;

}
