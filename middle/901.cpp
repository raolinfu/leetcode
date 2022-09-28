#include <list>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

using pii = pair<int, int>;

class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int weight = 1;
        while (!stk.empty() && stk.top().first <= price)
        {
            weight += stk.top().second;
            stk.pop();
        }

        stk.emplace(price, weight);

        return stk.top().second;
    }

private:
    stack<pii> stk;
};

int main(int argc, char const *argv[])
{
    list<int> li;
    li.push_back(2);
    li.insert(li.begin(), 3);
    cout<< *li.begin()<< endl;
    StockSpanner s;
    cout<< s.next(12)<< endl;
    cout<< s.next(2)<< endl;
    cout<< s.next(5)<< endl;
    return 0;
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */