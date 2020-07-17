#include <iostream>

using namespace std;

class base{
	public:
		virtual ~base(){}
		void start(){
			cout << "base.start()" <<endl;
			run();
		}
	protected:
		virtual void run(){
			cout << "base.run()" <<endl;
		}
};

class devied:public base{

	protected:
		virtual void _run() {
			cout << "devied._run()" <<endl;
		}

	private:
		void run() override{
			cout << "devied.run()" <<endl;
			_run();
		}
};

int main(){
	base* b = new base();
	b->start();
	base *d = new devied();
	d->start();
	delete b;
	delete d;
	return 0;
}
