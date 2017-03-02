/*
 * Initiated by Jared on March 2, 2017.
 *
 * This is used for testing multiple thread applications.
 *
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void
fun()
{
    cout<<"This is funny"<<endl;
}

void
fun1(int i, const string& str)
{
    cout<<"Parameters is "<<str<<" and "<<i<<endl;
}

void pause_thread(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
    cout<<"Thread "<<this_thread::get_id()<<" slept for "<<n<<" seconds"<<endl;
}

void
test_detach()
{
    vector<thread> pool;
    for (int i=0; i < 5; i++) {
        pool.push_back(thread(pause_thread, 5*(i +1)));
    }

    for (auto & th : pool)
        th.detach();
    
}

int
main(int argc, char** argv)
{
    thread first(fun);
    thread second(fun1, 5, "powerful thread support in c++11");
    
    cout<<"main, fun and fun1 are executed concurrently"<<endl;

    first.join();
    second.join();
    
    test_detach();
    cout<<"all theads are completed."<<endl;

}

