/*
 * Initiated by Jared on March 2, 2017.
 *
 * This is used for testing multiple thread applications.
 *
 */

#include <thread>
#include <chrono>
#include <vector>

#include <concurrent/basic.hpp>

using namespace std;

atomic<bool> BasicConcurrent::ready (false);
atomic_flag BasicConcurrent::winner = ATOMIC_FLAG_INIT;

void
BasicConcurrent::funny()
{
    cout<<"Function funny() is called"<<endl;
}

void
BasicConcurrent::fun1(int i, const string& str)
{
    cout<<"Parameters is "<<str<<" and "<<i<<endl;
}

void
BasicConcurrent::pause_thread(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
    cout<<"Thread "<<this_thread::get_id()<<" slept for "<<n<<" seconds"<<endl;
}

void
BasicConcurrent::test_detach()
{
    cout<<"testing detach"<<endl;
    vector<thread> pool;
    for (int i=0; i < 5; i++) {
        pool.push_back(thread(pause_thread, 5*(i +1)));
    }

    for (auto & th : pool)
        th.detach();
   
    // here, if do not wait, detached threads could not write to stdout
    pause_thread(30);   
}

void
BasicConcurrent::test_join()
{
    cout<<"testing join()"<<endl;
    thread first(funny);
    thread second(fun1, 5, "powerful thread support in c++11");
    
    cout<<"main, fun and fun1 are executed concurrently"<<endl;

    first.join();
    second.join();
}

void
BasicConcurrent::count_num(int id)
{
    while (!ready) {
        this_thread::yield();
    }

    for (volatile int i = 0; i < 1000000; i++) {}
    cout<<id;
    if (!winner.test_and_set())
        cout<<"Winner is "<<id<<endl;
}

void
BasicConcurrent::test_yield()
{
    cout<<"testing yield"<<endl;
    
    vector<thread> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(thread(count_num, i));
    
    ready = true;
    
    for (auto & th : vec)
        th.join();
    
    cout<<endl<<"testing yield finished"<<endl;
}

/*
int
main(int argc, char** argv)
{
    test_join();
    test_detach();
    test_yield();
    cout<<"all theads are completed."<<endl;

}
*/
